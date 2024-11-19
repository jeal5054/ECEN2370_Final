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
				.Rotation = ROTATION_0,			  //       1
				.originbit = { .x = 5, .y = 12 }, // 1 [1] 1
				.suboriginbit_0 = {0, 0},  // Explicit zero-initialization for unused fields
				.suboriginbit_1 = {0, 0},
				.suboriginbit_2 = {0, 0}
			};
			Oricky.suboriginbit_0.x = Oricky.originbit.x - 1;   //		 1
			Oricky.suboriginbit_0.y = Oricky.originbit.y;		// [1] 1 1

			Oricky.suboriginbit_1.x = Oricky.originbit.x + 1;	//        1
			Oricky.suboriginbit_1.y = Oricky.originbit.y;		//  1  1 [1]

			Oricky.suboriginbit_2.x = Oricky.originbit.x + 1;	// 	  [1]
			Oricky.suboriginbit_2.y = Oricky.originbit.y + 1; 	// 1 1 1
			return Oricky;
			break;

		case(BRICKY):
			Object Bricky = {
				.name = BRICKY,
				.Rotation = ROTATION_0,           // 1
				.originbit = { .x = 5, .y = 12 }, // 1 [1] 1
				.suboriginbit_0 = {0, 0},  // Explicit zero-initialization for unused fields
				.suboriginbit_1 = {0, 0},
				.suboriginbit_2 = {0, 0}
			};
			Bricky.suboriginbit_0.x = Bricky.originbit.x - 1;   //	1
			Bricky.suboriginbit_0.y = Bricky.originbit.y;		// [1] 1 1

			Bricky.suboriginbit_1.x = Bricky.originbit.x + 1;	//  1
			Bricky.suboriginbit_1.y = Bricky.originbit.y;		//  1  1 [1]

			Bricky.suboriginbit_2.x = Bricky.originbit.x - 1;	//[1]
			Bricky.suboriginbit_2.y = Bricky.originbit.y + 1; 	// 1 1 1
			return Bricky;
			break;

		case(CLEVELAND):
			Object Cleveland = {
				.name = CLEVELAND,
				.Rotation = ROTATION_0,           //   1 1
				.originbit = { .x = 5, .y = 12 }, //    [1] 1
				.suboriginbit_0 = {0, 0},  // Explicit zero-initialization for unused fields
				.suboriginbit_1 = {0, 0},
				.suboriginbit_2 = {0, 0}
			};
			Cleveland.suboriginbit_0.x = Cleveland.originbit.x;			 //	1 [1]
			Cleveland.suboriginbit_0.y = Cleveland.originbit.y + 1;		 //    1 1

			Cleveland.suboriginbit_1.x = Cleveland.originbit.x - 1;		 // [1] 1
			Cleveland.suboriginbit_1.y = Cleveland.originbit.y + 1;		 //     1 1

			Cleveland.suboriginbit_2.x = Cleveland.originbit.x + 1;		 //  1 1
			Cleveland.suboriginbit_2.y = Cleveland.originbit.y; 	     //    1 [1]
			return Cleveland;
			break;

		case(RHODE):
			Object Rhode = {
				.name = RHODE,
				.Rotation = ROTATION_0,           //        1 1
				.originbit = { .x = 5, .y = 12 }, //     1 [1]
				.suboriginbit_0 = {0, 0},  // Explicit zero-initialization for unused fields
				.suboriginbit_1 = {0, 0},
				.suboriginbit_2 = {0, 0}
			};
			Rhode.suboriginbit_0.x = Rhode.originbit.x;			 //	  [1] 1
			Rhode.suboriginbit_0.y = Rhode.originbit.y + 1;		 //  1 1

			Rhode.suboriginbit_1.x = Rhode.originbit.x + 1;		 //    1 [1]
			Rhode.suboriginbit_1.y = Rhode.originbit.y + 1;		 //  1 1

			Rhode.suboriginbit_2.x = Rhode.originbit.x - 1;		 //     1 1
			Rhode.suboriginbit_2.y = Rhode.originbit.y; 	     // [1] 1
			return Rhode;
			break;

		case(HERO):
			Object Hero = {
				.name = HERO,
				.Rotation = ROTATION_0,           //
				.originbit = { .x = 5, .y = 12 }, //  1 1 [1] 1
				.suboriginbit_0 = {0, 0},  // Explicit zero-initialization for unused fields
				.suboriginbit_1 = {0, 0},
				.suboriginbit_2 = {0, 0}
			};
			Hero.suboriginbit_0.x = Hero.originbit.x - 1;			 //
			Hero.suboriginbit_0.y = Hero.originbit.y;		 // 1 [1] 1 1

			Hero.suboriginbit_1.x = Hero.originbit.x - 2;		 //
			Hero.suboriginbit_1.y = Hero.originbit.y;		 // [1] 1 1 1

			Hero.suboriginbit_2.x = Hero.originbit.x + 1;		 //
			Hero.suboriginbit_2.y = Hero.originbit.y; 	     	 //  1 1 1 [1]
			return Hero;
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

