/*
 * Hover.cpp
 *
 *  Created on: Aug 23, 2022
 *      Author: ADMIN
 */
#include "PlutoPilot.h"
#include "Hover.h"
#include "Utils.h"
#include "Control.h"
#include "User.h"
#include "Motor.h"
#include "Estimate.h"
#include<stdint.h>
bool sw=0;





void HoverInit(void){
LED.flightStatus(DEACTIVATE);
		Motor.init(M5);
		Motor.init(M6);
		Motor.init(M7);
		Motor.init(M8);
}
void HoverLoop (void){
if(RcData.get(RC_ROLL)>1800 && RcData.get(RC_YAW)<1150){
		sw=1;
}
if(sw==1){
		LED.set(RED,TOGGLE);
		Motor.set(M6,RcData.get(RC_THROTTLE)-(RcData.get(RC_ROLL)-1500)/2);
		Motor.set(M5,1800);
		Motor.set(M7,RcData.get(RC_THROTTLE)+(RcData.get(RC_ROLL)-1500)/2);
		Motor.set(M8,1800);
		if(RcData.get(RC_ROLL)>1950 && RcData.get(RC_YAW)<1050){
				sw=0;
		}
}
if(sw==0){
	Motor.set(M5,1000);
	Motor.set(M6,1000);
	Motor.set(M7,1000);
	Motor.set(M8,1000);

}
}



