/*
 * ApplicationCode.h
 *
 *  Created on: Sep 10, 2024
 *      Author: jeffreya181
 */

#ifndef APPLICATIONCODE_H_
#define APPLICATIONCODE_H_

#include "Scheduler.h"

#define NAME_LENGTH 7
#define MAGNIFY_DELAY 25000
#define USE_INTERRUPT_FOR_BUTTON 0
#define ACTIVE_INTERRUPT 1

void applicationInit();
void appDelay(uint32_t delay);

//button prototypes
void applicationButtonInit();
void applicationInterruptInit();

#endif /* APPLICATIONCODE_H_ */
