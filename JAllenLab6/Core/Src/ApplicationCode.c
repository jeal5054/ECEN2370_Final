/*
 * ApplicationCode.c
 *
 *  Created on: Sep 10, 2024
 *      Author: jeffreya181
 */
#include "ApplicationCode.h"
#include "InterruptControl.h"
#include "Matrixdef.h"

void applicationInit(){
	//applicationInterruptInit();
	addScheduledEvent(MATRIX_UPDATE_EVENT);
}

/*
void applicationButtonInit() {
	init_Button();
}


void applicationInterruptInit() {
	Button_Interrupt();
}

void EXTI0_IRQHandler(){
	Interrupt_Disable(EXTI0_IRQ_NUMBER);
	Interrupt_Clear_Pending(EXTI0_IRQ_NUMBER);
	Interrupt_Clear_Pending_EXTI(GPIO_PIN_NUM_13);

	Interrupt_Enable(EXTI0_IRQ_NUMBER);
}

void TIM2_IRQHandler() {
	Interrupt_Disable(TIM2_IRQ_NUMBER);
	Interrupt_Clear_Pending(TIM2_IRQ_NUMBER);
	Interrupt_Clear_Pending_TIM(TIM2);


	Interrupt_Enable(TIM2_IRQ_NUMBER);
}


*/
