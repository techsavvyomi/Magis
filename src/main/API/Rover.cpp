/*
 * rover.cpp

 * Simple Platform selection for pluto platform
 *  Created on: Sep 6, 2022
 *      Author: Omkar Dandekar
 */

#include  "PlutoPilot.h"
#include "Rover.h"
#include  "Control.h"
#include "User.h"
#include  "Motor.h"
#include "Utils.h"
#include "Estimate.h"


#define ABS(x) ((x) > 0 ? (x) : -(x))

int16_t roll_value;
int16_t throttle_value;
int16_t m1m2Value;
int16_t m3m4Value;

bool isAutoStablised=false;
int16_t setHeading=0;
int16_t heading_error=0;
int16_t k=15;//gain for stabilisation control

int constrain(int amt, int low, int high);
int generatePWM(int amt);
bool sw1=0;



void RoverInit(void){
 Motor.initReversibleMotors();
	Motor.set(M1, 1000);
	Motor.set(M2, 1000);
	Motor.set(M3, 1000);
	Motor.set(M4, 1000);
}
void RoverLoop (void){
	if(RcData.get(RC_ROLL)>1800 && RcData.get(RC_YAW)<1150){
			sw1=1;
	}
	if(sw1==1){


	//	AutoStablisation control
	if(RcData.get(RC_PITCH)>=1930)
		{
			isAutoStablised=true;
			setHeading=Angle.get(AG_YAW);

		}

	else if(RcData.get(RC_PITCH)<1070)
		{
			isAutoStablised=false;


		}



	if(isAutoStablised)
	{


		if(ABS(RcData.get(RC_ROLL)-1500)<30)	// check if no RC input is given
		{
			// calculate the errror and correction input for roll
			heading_error=setHeading-Angle.get(AG_YAW);

			if(heading_error>180)
				heading_error=heading_error-360;

			else if(heading_error<-180)
				heading_error=heading_error+360;

			roll_value=1500 +k*heading_error;
		}
		else
		{
			roll_value=RcData.get(RC_ROLL);
			setHeading=Angle.get(AG_YAW);
		}

	}
	else
	{

		 roll_value=RcData.get(RC_ROLL);
	}

	throttle_value=RcData.get(RC_THROTTLE);

	// calculate the motor value
	m1m2Value= (throttle_value-1500)+(roll_value-1500)/2;
	m1m2Value= constrain(m1m2Value, -500, 500);

	m3m4Value= (throttle_value-1500)-(roll_value-1500)/2;
	m3m4Value= constrain(m3m4Value, -500, 500);


	// set motor direction and generate PWM
	if(m1m2Value<0)
	{
		Motor.setDirection(M1, BACKWARD);
		Motor.setDirection(M2, BACKWARD);


	}
	else
	{
		Motor.setDirection(M1, FORWARD);
		Motor.setDirection(M2, FORWARD);
	}

	Motor.set(M1, generatePWM(m1m2Value));
	Motor.set(M2, generatePWM(m1m2Value));

	//Monitor.println("M1,M2: ", generatePWM(m1m2Value));

	if(m3m4Value<0)
	{
		Motor.setDirection(M3, BACKWARD);
		Motor.setDirection(M4, BACKWARD);
	}
	else
	{
		Motor.setDirection(M3, FORWARD);
		Motor.setDirection(M4, FORWARD);

	}

	Motor.set(M3, generatePWM(m3m4Value));
	Motor.set(M4, generatePWM(m3m4Value));

	//Monitor.println("M3,M4: ", generatePWM(m3m4Value));

	if(RcData.get(RC_ROLL)>1950 && RcData.get(RC_YAW)<1050){
						sw1=0;
				}
		}
		if(sw1==0){
			Motor.set(M5,1000);
			Motor.set(M6,1000);
			Motor.set(M7,1000);
			Motor.set(M8,1000);

		}


}
int constrain(int amt, int low, int high)
{
    if (amt < low)
        return low;
    else if (amt > high)
        return high;
    else
        return amt;
}

int generatePWM(int amt)
{

	amt= ABS(amt);

	amt=1000+(amt*2);

	return amt;




}


