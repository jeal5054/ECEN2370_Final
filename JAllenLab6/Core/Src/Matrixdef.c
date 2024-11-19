/*
 * Matrixdef.c
 *
 *  Created on: Nov 19, 2024
 *      Author: jeffreya181
 */
#include "Matrixdef.h"

void RND_NUM(void) {
	static RNG_HandleTypeDef hrng;
	if(RND_FLAG) {
	  hrng.Instance = RNG;
	  	if (HAL_RNG_Init(&hrng) != HAL_OK) {
		  while(1);
	    }
	} else {
		if (HAL_RNG_GenerateRandomNumber(&hrng, &randomNumber) != HAL_OK) {
			while(1);
		}
	}
}

Object object_Select(void){

	RND_NUM();
	switch(randomNumber%7) {
		case(ORICKY):
			Object Oricky = {
				.name = ORICKY,
				.originbit = { .x = 5, .y = 12 },
				.suboriginbit_0 = {0, 0},  // Explicit zero-initialization for unused fields
				.suboriginbit_1 = {0, 0},
				.suboriginbit_2 = {0, 0}
			};
			Oricky.suboriginbit_0.x = Oricky.originbit.x + 1;
			Oricky.suboriginbit_0.y = Oricky.originbit.y - 1;

			Oricky.suboriginbit_1.x = Oricky.originbit.x + 1;
			Oricky.suboriginbit_1.y = Oricky.originbit.y - 1;

			Oricky.suboriginbit_2.x = Oricky.originbit.x + 1;
			Oricky.suboriginbit_2.y = Oricky.originbit.y - 1;

			return Oricky;
			break;
		case(BRICKY):

			break;
		case(CLEVELAND):

			break;
		case(RHODE):

			break;
		case(HERO):

			break;
		case(TEEWEE):

			break;
		case(SMASHBOY):

			break;
		default:
			return 0;
	}
}

void shift_Left(Object object){

}

void shift_Right(void){

}

void transform_Matrix(void){

}

void check_State(void){

}

void update_Matrix(void){

}

