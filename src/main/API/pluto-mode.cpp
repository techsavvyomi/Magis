/*
 * pluto-mode.cpp

 *
 *  Created on: Sep 6, 2022
 *      Author: Omkar Mahesh Dandekar
 */


#include"pluto-mode.h"


void Mode_P::PlutoMode(Mode_state Platform)

{


    switch (Platform) {


    case HOVER_IP:


    	PLUTO_MODE=1;


        break;


    case ROVER_IP:


    	PLUTO_MODE=2;


        break;

    default:

    	PLUTO_MODE=0;

    }


}

int PLUTO_MODE=0;

Mode_P Mode;


