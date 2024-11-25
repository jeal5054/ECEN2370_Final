/*
 * ApplicationCode.c
 *
 *  Created on: Sep 10, 2024
 *      Author: jeffreya181
 */
#include "ApplicationCode.h"


void applicationInit(){
	//applicationInterruptInit();
	object_Select();
	addScheduledEvent(MATRIX_UPDATE_EVENT);
}

