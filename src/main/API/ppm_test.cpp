/*
 * ppm_test.cpp
 *
 *  Created on: 21-May-2022
 *      Author: Drona
 */




/*
 * PPM-User.cpp
 *
 *  Created on: 28-Feb-2022
 *      Author: Tech Tronix Projects
 */


#include"ppm_test.h"

void RX_P::InputStatus(RX_state STATE)
{

    switch (STATE) {

    case MSP_IP:

    	PPM_MODE=0;

        break;

    case PPM_IP:

    	PPM_MODE=1;

        break;
    default:
    	PPM_MODE=0;
    }

}
bool PPM_MODE=0;
RX_P RX;
