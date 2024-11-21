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

uint8_t check_State(Object object){
	if(     (object.originbit.x <= 0) || (object.originbit.x >= 9) ||
	   (object.suboriginbit_0.x <= 0) || (object.suboriginbit_0.x >= 9) ||
	   (object.suboriginbit_1.x <= 0) || (object.suboriginbit_1.x >= 9) ||
	   (object.suboriginbit_2.x <= 0) || (object.suboriginbit_2.x >= 9) )
	{
		return 0;
	} else if( (object.originbit.y <= 0)      || (object.suboriginbit_0.y <= 0) ||
			   (object.suboriginbit_1.y <= 0) || (object.suboriginbit_2.y <= 0) )
	{
		return 1;
	} else {
		return 2;
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
				.suboriginbit_0 = {0, 0}, 
				.suboriginbit_1 = {0, 0},
				.suboriginbit_2 = {0, 0}
			};
		    Oricky = transform_rotation(Oricky, Oricky.Rotation);
			return Oricky;
			break;

		case(BRICKY):
			Object Bricky = {
				.name = BRICKY,
				.Rotation = ROTATION_0,           // 1
				.originbit = { .x = 5, .y = 12 }, // 1 [1] 1
				.suboriginbit_0 = {0, 0}, 
				.suboriginbit_1 = {0, 0},
				.suboriginbit_2 = {0, 0}
			};
			Bricky = transform_rotation(Bricky, Bricky.Rotation);
			return Bricky;
			break;

		case(CLEVELAND):
			Object Cleveland = {
				.name = CLEVELAND,
				.Rotation = ROTATION_0,           //   1 1
				.originbit = { .x = 5, .y = 12 }, //    [1] 1
				.suboriginbit_0 = {0, 0},  
				.suboriginbit_1 = {0, 0},
				.suboriginbit_2 = {0, 0}
			};
		    Cleveland = transform_rotation(Cleveland, Cleveland.Rotation);
			return Cleveland;
			break;

		case(RHODE):
			Object Rhode = {
				.name = RHODE,
				.Rotation = ROTATION_0,           //        1 1
				.originbit = { .x = 5, .y = 12 }, //     1 [1]
				.suboriginbit_0 = {0, 0},
				.suboriginbit_1 = {0, 0},
				.suboriginbit_2 = {0, 0}
			};
			Rhode = transform_rotation(Rhode, Rhode.Rotation);
			return Rhode;
			break;

		case(HERO):
			Object Hero = {
				.name = HERO,
				.Rotation = ROTATION_0,          			 //
				.originbit = { .x = 5, .y = 12 }, 			 //  1 1 [1] 1
				.suboriginbit_0 = {0, 0}, 
				.suboriginbit_1 = {0, 0},
				.suboriginbit_2 = {0, 0}
			};
			Hero = transform_rotation(Hero, Hero.Rotation);
			return Hero;
			break;

		case(TEEWEE):
			Object Teewee = {
				.name = TEEWEE,
				.Rotation = ROTATION_0,          			 	//    1
				.originbit = { .x = 5, .y = 12 }, 			 	// 1 [1] 1
				.suboriginbit_0 = {0, 0},
				.suboriginbit_1 = {0, 0},
				.suboriginbit_2 = {0, 0}
			};
			Teewee = transform_rotation(Teewee, Teewee.Rotation);
			return Teewee;

			break;
		case(SMASHBOY):
			Object Smashboy = {
				.name = SMASHBOY,
				.Rotation = ROTATION_0,          			 	// 1  1
				.originbit = { .x = 5, .y = 12 }, 			 	//[1] 1
				.suboriginbit_0 = {0, 0},
				.suboriginbit_1 = {0, 0},
				.suboriginbit_2 = {0, 0}
			};
			Smashboy = transform_rotation(Smashboy, Smashboy.Rotation);
			return Smashboy;

			break;
		default:
			Object null = {0};
			return null;
	}
}

Object shift_Left(Object object){
	Object temp = object;
	object.originbit.x -= 1;
	object.suboriginbit_0.x -= 1;
	object.suboriginbit_1.x -= 1;
	object.suboriginbit_2.x -= 1;
	if(check_State(object)) {
		return temp;
	} else {
		return object;
	}
}

Object shift_Right(Object object){
	Object temp = object;
	object.originbit.x += 1;
	object.suboriginbit_0.x += 1;
	object.suboriginbit_1.x += 1;
	object.suboriginbit_2.x += 1;
	if(check_State(object)) {
		return temp;
	} else {
		return object;
	}
}

Object transform_rotation(Object object, rotation new_rotation){
	Object temp = object;
	switch(object.name){
		case(ORICKY):
			switch(new_rotation) {
				case(ROTATION_0):
						//       1
						// 1 [1] 1
					object.suboriginbit_0.x = object.originbit.x - 1;   //		 1
					object.suboriginbit_0.y = object.originbit.y;		// [1] 1 1

					object.suboriginbit_1.x = object.originbit.x + 1;	//        1
					object.suboriginbit_1.y = object.originbit.y;		//  1  1 [1]

					object.suboriginbit_2.x = object.originbit.x + 1;	// 	  [1]
					object.suboriginbit_2.y = object.originbit.y + 1; 	// 1 1 1
				case(ROTATION_1):
						// 1  1
						//   [1]
						//    1
					object.suboriginbit_0.x = object.originbit.x;
					object.suboriginbit_0.y = object.originbit.y - 1;

					object.suboriginbit_1.x = object.originbit.x;
					object.suboriginbit_1.y = object.originbit.y + 1;

					object.suboriginbit_2.x = object.originbit.x - 1;
					object.suboriginbit_2.y = object.originbit.y + 1;

				case(ROTATION_2):
						// 1  [1]  1
						// 1
					object.suboriginbit_0.x = object.originbit.x + 1;
					object.suboriginbit_0.y = object.originbit.y;

					object.suboriginbit_1.x = object.originbit.x - 1;
					object.suboriginbit_1.y = object.originbit.y;

					object.suboriginbit_2.x = object.originbit.x - 1;
					object.suboriginbit_2.y = object.originbit.y - 1;

				case(ROTATION_3):
						//  1
						// [1]
						//  1 1
					object.suboriginbit_0.x = object.originbit.x;
					object.suboriginbit_0.y = object.originbit.y + 1;

					object.suboriginbit_1.x = object.originbit.x;
					object.suboriginbit_1.y = object.originbit.y - 1;

					object.suboriginbit_2.x = object.originbit.x + 1;
					object.suboriginbit_2.y = object.originbit.y - 1;
			}
			break;
		case(BRICKY):
			switch(new_rotation) {
				case(ROTATION_0):
						// 1
						// 1 [1] 1
					object.suboriginbit_0.x = object.originbit.x - 1;   //	1
					object.suboriginbit_0.y = object.originbit.y;		// [1] 1 1

					object.suboriginbit_1.x = object.originbit.x + 1;	//  1
					object.suboriginbit_1.y = object.originbit.y;		//  1  1 [1]

					object.suboriginbit_2.x = object.originbit.x - 1;	//[1]
					object.suboriginbit_2.y = object.originbit.y + 1; 	// 1 1 1
				case(ROTATION_1):
						// 1 1
						//[1]
						// 1
					object.suboriginbit_0.x = object.originbit.x;
					object.suboriginbit_0.y = object.originbit.y;

					object.suboriginbit_1.x = object.originbit.x;
					object.suboriginbit_1.y = object.originbit.y;

					object.suboriginbit_2.x = object.originbit.x;
					object.suboriginbit_2.y = object.originbit.y;
				case(ROTATION_2):
						// 1 [1] 1
						//       1
					object.suboriginbit_0.x = object.originbit.x;
					object.suboriginbit_0.y = object.originbit.y;

					object.suboriginbit_1.x = object.originbit.x;
					object.suboriginbit_1.y = object.originbit.y;

					object.suboriginbit_2.x = object.originbit.x;
					object.suboriginbit_2.y = object.originbit.y;
				case(ROTATION_3):
						//   1
						//  [1]
						// 1 1
					object.suboriginbit_0.x = object.originbit.x;
					object.suboriginbit_0.y = object.originbit.y;

					object.suboriginbit_1.x = object.originbit.x;
					object.suboriginbit_1.y = object.originbit.y;

					object.suboriginbit_2.x = object.originbit.x;
					object.suboriginbit_2.y = object.originbit.y;
			}

			break;
		case(CLEVELAND):
			switch(new_rotation) {
				case(ROTATION_0):
						// 1 1
						//  [1] 1
					object.suboriginbit_0.x = object.originbit.x;			 //	1 [1]
					object.suboriginbit_0.y = object.originbit.y + 1;		 //    1 1

					object.suboriginbit_1.x = object.originbit.x - 1;		 // [1] 1
					object.suboriginbit_1.y = object.originbit.y + 1;		 //     1 1

					object.suboriginbit_2.x = object.originbit.x + 1;		 //  1 1
					object.suboriginbit_2.y = object.originbit.y; 	     	//    1 [1]
				case(ROTATION_1):
						//     1
						// [1] 1
						//  1
					object.suboriginbit_0.x = object.originbit.x+1;
					object.suboriginbit_0.y = object.originbit.y;

					object.suboriginbit_1.x = object.originbit.x+1;
					object.suboriginbit_1.y = object.originbit.y+1;

					object.suboriginbit_2.x = object.originbit.x;
					object.suboriginbit_2.y = object.originbit.y-1;
				case(ROTATION_2):
						// 1 [1]
						//    1  1
					object.suboriginbit_0.x = object.originbit.x - 1;
					object.suboriginbit_0.y = object.originbit.y;

					object.suboriginbit_1.x = object.originbit.x;
					object.suboriginbit_1.y = object.originbit.y - 1;

					object.suboriginbit_2.x = object.originbit.x + 1;
					object.suboriginbit_2.y = object.originbit.y - 1;
				case(ROTATION_3):
						//     1
						//  1 [1]
						//  1
					object.suboriginbit_0.x = object.originbit.x - 1;
					object.suboriginbit_0.y = object.originbit.y;

					object.suboriginbit_1.x = object.originbit.x - 1;
					object.suboriginbit_1.y = object.originbit.y - 1;

					object.suboriginbit_2.x = object.originbit.x;
					object.suboriginbit_2.y = object.originbit.y + 1;
			}
			break;
		case(RHODE):
			switch(new_rotation) {
				case(ROTATION_0):
						//    1 1
						// 1 [1]
					object.suboriginbit_0.x = object.originbit.x;			 //	  [1] 1
					object.suboriginbit_0.y = object.originbit.y + 1;		 //  1 1

					object.suboriginbit_1.x = object.originbit.x + 1;		 //    1 [1]
					object.suboriginbit_1.y = object.originbit.y + 1;		 //  1 1

					object.suboriginbit_2.x = object.originbit.x - 1;		 //     1 1
					object.suboriginbit_2.y = object.originbit.y; 	     // [1] 1
				case(ROTATION_1):
						// 1
						//[1] 1
						//    1
					object.suboriginbit_0.x = object.originbit.x;
					object.suboriginbit_0.y = object.originbit.y + 1;

					object.suboriginbit_1.x = object.originbit.x + 1;
					object.suboriginbit_1.y = object.originbit.y;

					object.suboriginbit_2.x = object.originbit.x + 1;
					object.suboriginbit_2.y = object.originbit.y - 1;
				case(ROTATION_2):
						//  [1] 1
						// 1 1
					object.suboriginbit_0.x = object.originbit.x + 1;
					object.suboriginbit_0.y = object.originbit.y;

					object.suboriginbit_1.x = object.originbit.x;
					object.suboriginbit_1.y = object.originbit.y - 1;

					object.suboriginbit_2.x = object.originbit.x - 1;
					object.suboriginbit_2.y = object.originbit.y - 1;
				case(ROTATION_3):
						// 1
						// 1 [1]
						//    1
					object.suboriginbit_0.x = object.originbit.x;
					object.suboriginbit_0.y = object.originbit.y - 1;

					object.suboriginbit_1.x = object.originbit.x - 1;
					object.suboriginbit_1.y = object.originbit.y;

					object.suboriginbit_2.x = object.originbit.x - 1;
					object.suboriginbit_2.y = object.originbit.y + 1;
			}
			break;
		case(HERO):
			switch(new_rotation) {
				case(ROTATION_0):
						// 1 1 [1] 1
					object.suboriginbit_0.x = object.originbit.x - 1;	 //
					object.suboriginbit_0.y = object.originbit.y;		 // 1 [1] 1 1

					object.suboriginbit_1.x = object.originbit.x - 2;	 //
					object.suboriginbit_1.y = object.originbit.y;		 // [1] 1 1 1

					object.suboriginbit_2.x = object.originbit.x + 1;	 //
					object.suboriginbit_2.y = object.originbit.y; 	     //  1 1 1 [1]
				case(ROTATION_1):
						//  1
						//  1
						// [1]
						//  1
					object.suboriginbit_0.x = object.originbit.x;
					object.suboriginbit_0.y = object.originbit.y + 1;

					object.suboriginbit_1.x = object.originbit.x;
					object.suboriginbit_1.y = object.originbit.y - 1;

					object.suboriginbit_2.x = object.originbit.x;
					object.suboriginbit_2.y = object.originbit.y + 2;
				case(ROTATION_2):
						// 1 [1] 1 1
					object.suboriginbit_0.x = object.originbit.x - 1;
					object.suboriginbit_0.y = object.originbit.y;

					object.suboriginbit_1.x = object.originbit.x + 1;
					object.suboriginbit_1.y = object.originbit.y;

					object.suboriginbit_2.x = object.originbit.x + 2;
					object.suboriginbit_2.y = object.originbit.y;
				case(ROTATION_3):
						//  1
						// [1]
						//  1
						//  1
					object.suboriginbit_0.x = object.originbit.x;
					object.suboriginbit_0.y = object.originbit.y + 1;

					object.suboriginbit_1.x = object.originbit.x;
					object.suboriginbit_1.y = object.originbit.y - 1;

					object.suboriginbit_2.x = object.originbit.x;
					object.suboriginbit_2.y = object.originbit.y - 2;
			}

			break;
		case(TEEWEE):
			switch(new_rotation) {
				case(ROTATION_0):
						//    1
						// 1 [1] 1
					object.suboriginbit_0.x = object.originbit.x - 1;	 //     1
					object.suboriginbit_0.y = object.originbit.y;		 // [1] 1 1

					object.suboriginbit_1.x = object.originbit.x + 1;	 //	  1
					object.suboriginbit_1.y = object.originbit.y;		 // 1 1 [1]

					object.suboriginbit_2.x = object.originbit.x;	     //	 [1]
					object.suboriginbit_2.y = object.originbit.y + 1; 	 // 1 1 1
				case(ROTATION_1):
						//  1
						// [1] 1
						//  1
					object.suboriginbit_0.x = object.originbit.x + 1;
					object.suboriginbit_0.y = object.originbit.y;

					object.suboriginbit_1.x = object.originbit.x;
					object.suboriginbit_1.y = object.originbit.y + 1;

					object.suboriginbit_2.x = object.originbit.x;
					object.suboriginbit_2.y = object.originbit.y - 1;
				case(ROTATION_2):
						// 1 [1] 1
						//    1
					object.suboriginbit_0.x = object.originbit.x;
					object.suboriginbit_0.y = object.originbit.y - 1;

					object.suboriginbit_1.x = object.originbit.x + 1;
					object.suboriginbit_1.y = object.originbit.y;

					object.suboriginbit_2.x = object.originbit.x - 1;
					object.suboriginbit_2.y = object.originbit.y;
				case(ROTATION_3):
						//    1
						// 1 [1]
						//    1
					object.suboriginbit_0.x = object.originbit.x - 1;
					object.suboriginbit_0.y = object.originbit.y;

					object.suboriginbit_1.x = object.originbit.x;
					object.suboriginbit_1.y = object.originbit.y + 1;

					object.suboriginbit_2.x = object.originbit.x;
					object.suboriginbit_2.y = object.originbit.y - 1;
			}

			break;
		case(SMASHBOY):
			switch(new_rotation) {
				case(ROTATION_0):
					object.suboriginbit_0.x = object.originbit.x + 1;	 //  1  1
					object.suboriginbit_0.y = object.originbit.y;		 //  1 [1]

					object.suboriginbit_1.x = object.originbit.x;		 //	[1] 1
					object.suboriginbit_1.y = object.originbit.y + 1;	 //  1  1

					object.suboriginbit_2.x = object.originbit.x + 1;	 //	1 [1]
					object.suboriginbit_2.y = object.originbit.y + 1; 	 // 1  1
				case(ROTATION_1):

					object.suboriginbit_0.x = object.originbit.x + 1;	 //  1  1
					object.suboriginbit_0.y = object.originbit.y;		 //  1 [1]

					object.suboriginbit_1.x = object.originbit.x;		 //	[1] 1
					object.suboriginbit_1.y = object.originbit.y + 1;	 //  1  1

					object.suboriginbit_2.x = object.originbit.x + 1;	 //	1 [1]
					object.suboriginbit_2.y = object.originbit.y + 1; 	 // 1  1
				case(ROTATION_2):
					object.suboriginbit_0.x = object.originbit.x + 1;	 //  1  1
					object.suboriginbit_0.y = object.originbit.y;		 //  1 [1]

					object.suboriginbit_1.x = object.originbit.x;		 //	[1] 1
					object.suboriginbit_1.y = object.originbit.y + 1;	 //  1  1

					object.suboriginbit_2.x = object.originbit.x + 1;	 //	1 [1]
					object.suboriginbit_2.y = object.originbit.y + 1; 	 // 1  1
				case(ROTATION_3):

					object.suboriginbit_0.x = object.originbit.x + 1;	 //  1  1
					object.suboriginbit_0.y = object.originbit.y;		 //  1 [1]

					object.suboriginbit_1.x = object.originbit.x;		 //	[1] 1
					object.suboriginbit_1.y = object.originbit.y + 1;	 //  1  1

					object.suboriginbit_2.x = object.originbit.x + 1;	 //	1 [1]
					object.suboriginbit_2.y = object.originbit.y + 1; 	 // 1  1
			}
		break;
	}

	if(check_State(object)) {
		return object;
	} else if (check_State(object) == 1){
		return temp; //////////************ NNNNEEEEDD TO SAY IF IT HITS BOTTOM////////////
	} else {
		return temp;
	}

}

void update_Matrix(void){

}

