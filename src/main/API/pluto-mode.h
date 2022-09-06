/*
 * pluto-mode.h
 *
 *  Created on: Sep 6, 2022
 *      Author: ADMIN
 */






#include "PlutoPilot.h"


#ifdef __cplusplus

extern "C" {

#endif

typedef enum {


     HOVER_IP,

	 ROVER_IP

} Mode_state;


class Mode_P {

public:

    void PlutoMode(Mode_state Platform);


};


extern int PLUTO_MODE;

extern Mode_P Mode;

#ifdef __cplusplus

}






#endif /* SRC_MAIN_API_PLUTO_MODE_H_ */
