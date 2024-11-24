/*
 * Matrixdef.c
 *
 *  Created on: Nov 19, 2024
 *      Author: jeffreya181
 */
#include "Matrixdef.h"

#define MATRIX_LCD 0

void RND_NUM(void) { // issue here
	uint32_t RND;
	RNG_HandleTypeDef hrng;
	hrng.Instance = RNG;

	if (HAL_RNG_Init(&hrng) != HAL_OK)
	{
		while(1);
	}
	  /* USER CODE BEGIN RNG_Init 2 */
    if (HAL_RNG_GenerateRandomNumber(&hrng, &RND) != HAL_OK) {
    	// Handle the error (e.g., infinite loop or error logging)
	    while (1);
	}
	   RND = RND % 7;  // Constrain the result to 0-6
	   randomNumber = RND;
}

uint8_t check_State(void) {
	if(     (object.originbit.x <= 0) || (object.originbit.x >= 9) ||
	   (object.suboriginbit_0.x <= 0) || (object.suboriginbit_0.x >= 9) ||
	   (object.suboriginbit_1.x <= 0) || (object.suboriginbit_1.x >= 9) ||
	   (object.suboriginbit_2.x <= 0) || (object.suboriginbit_2.x >= 9) )
	{
		return 0; // This means object has gone outside of the bounds
	} else if( (object.originbit.y <= 0)      || (object.suboriginbit_0.y <= 0) ||
			   (object.suboriginbit_1.y <= 0) || (object.suboriginbit_2.y <= 0) )
	{
		// initiate the ending protocal
		// Place the object in the matrix, generate new object
		dummyTable[object.originbit.x][object.originbit.y] = 1;
		dummyTable[object.suboriginbit_0.x][object.suboriginbit_0.y] = 1;
		dummyTable[object.suboriginbit_1.x][object.suboriginbit_1.y] = 1;
		dummyTable[object.suboriginbit_2.x][object.suboriginbit_2.y] = 1;
		object_Select();
		return 1; // This means object has hit the button
	} else {
		return 2; // In case we want to see nothing can be done
	}
}

void object_Select(void){
	/*
	uint32_t RND;
	if (HAL_RNG_GenerateRandomNumber(&hrng, &RND) != HAL_OK) {
		 // Handle the error (e.g., infinite loop or error logging)
		   while (1);
	}
	RND = RND % 7;  // Constrain the result to 0-6
	RND_NUM(RND);
	*/
	switch(randomNumber) {
		case(ORICKY):
			Object Oricky = {
				.name = ORICKY,
				.Rotation = ROTATION_0,			  //       1
				.originbit = { .x = 5, .y = 12 }, // 1 [1] 1
				.suboriginbit_0 = {0, 0}, 
				.suboriginbit_1 = {0, 0},
				.suboriginbit_2 = {0, 0}
			};
			object = Oricky;
		    transform_rotation(Oricky.Rotation);
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
			object = Bricky;
			transform_rotation(Bricky.Rotation);
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
			object = Cleveland;
		    transform_rotation(Cleveland.Rotation);
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
			object = Rhode;
			transform_rotation(Rhode.Rotation);
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
			object = Hero;
			transform_rotation(Hero.Rotation);
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
			object = Teewee;
			transform_rotation(Teewee.Rotation);
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
			object = Smashboy;
			transform_rotation(Smashboy.Rotation);
			break;

	}
}

void shift_Left(){
	Object temp = object;
	object.originbit.x -= 1;
	object.suboriginbit_0.x -= 1;
	object.suboriginbit_1.x -= 1;
	object.suboriginbit_2.x -= 1;
	if(check_State()) {
		object = temp;
	}
}

void shift_Right(){
	Object temp = object;
	object.originbit.x += 1;
	object.suboriginbit_0.x += 1;
	object.suboriginbit_1.x += 1;
	object.suboriginbit_2.x += 1;
	if(check_State()) {
		object = temp;
	}
}

void transform_rotation(rotation new_rotation){
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

					break;
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

					break;
				case(ROTATION_2):
						// 1  [1]  1
						// 1
					object.suboriginbit_0.x = object.originbit.x + 1;
					object.suboriginbit_0.y = object.originbit.y;

					object.suboriginbit_1.x = object.originbit.x - 1;
					object.suboriginbit_1.y = object.originbit.y;

					object.suboriginbit_2.x = object.originbit.x - 1;
					object.suboriginbit_2.y = object.originbit.y - 1;

					break;
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

					break;
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

					break;
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

					break;
				case(ROTATION_2):
						// 1 [1] 1
						//       1
					object.suboriginbit_0.x = object.originbit.x;
					object.suboriginbit_0.y = object.originbit.y;

					object.suboriginbit_1.x = object.originbit.x;
					object.suboriginbit_1.y = object.originbit.y;

					object.suboriginbit_2.x = object.originbit.x;
					object.suboriginbit_2.y = object.originbit.y;

					break;
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

					break;
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

					break;
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

					break;
				case(ROTATION_2):
						// 1 [1]
						//    1  1
					object.suboriginbit_0.x = object.originbit.x - 1;
					object.suboriginbit_0.y = object.originbit.y;

					object.suboriginbit_1.x = object.originbit.x;
					object.suboriginbit_1.y = object.originbit.y - 1;

					object.suboriginbit_2.x = object.originbit.x + 1;
					object.suboriginbit_2.y = object.originbit.y - 1;

					break;
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

					break;
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

					break;
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

					break;
				case(ROTATION_2):
						//  [1] 1
						// 1 1
					object.suboriginbit_0.x = object.originbit.x + 1;
					object.suboriginbit_0.y = object.originbit.y;

					object.suboriginbit_1.x = object.originbit.x;
					object.suboriginbit_1.y = object.originbit.y - 1;

					object.suboriginbit_2.x = object.originbit.x - 1;
					object.suboriginbit_2.y = object.originbit.y - 1;

					break;
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

					break;
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

					break;
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

					break;
				case(ROTATION_2):
						// 1 [1] 1 1
					object.suboriginbit_0.x = object.originbit.x - 1;
					object.suboriginbit_0.y = object.originbit.y;

					object.suboriginbit_1.x = object.originbit.x + 1;
					object.suboriginbit_1.y = object.originbit.y;

					object.suboriginbit_2.x = object.originbit.x + 2;
					object.suboriginbit_2.y = object.originbit.y;

					break;
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

					break;
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

					break;
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

					break;
				case(ROTATION_2):
						// 1 [1] 1
						//    1
					object.suboriginbit_0.x = object.originbit.x;
					object.suboriginbit_0.y = object.originbit.y - 1;

					object.suboriginbit_1.x = object.originbit.x + 1;
					object.suboriginbit_1.y = object.originbit.y;

					object.suboriginbit_2.x = object.originbit.x - 1;
					object.suboriginbit_2.y = object.originbit.y;

					break;
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

					break;
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

					break;
				case(ROTATION_1):

					object.suboriginbit_0.x = object.originbit.x + 1;	 //  1  1
					object.suboriginbit_0.y = object.originbit.y;		 //  1 [1]

					object.suboriginbit_1.x = object.originbit.x;		 //	[1] 1
					object.suboriginbit_1.y = object.originbit.y + 1;	 //  1  1

					object.suboriginbit_2.x = object.originbit.x + 1;	 //	1 [1]
					object.suboriginbit_2.y = object.originbit.y + 1; 	 // 1  1

					break;
				case(ROTATION_2):
					object.suboriginbit_0.x = object.originbit.x + 1;	 //  1  1
					object.suboriginbit_0.y = object.originbit.y;		 //  1 [1]

					object.suboriginbit_1.x = object.originbit.x;		 //	[1] 1
					object.suboriginbit_1.y = object.originbit.y + 1;	 //  1  1

					object.suboriginbit_2.x = object.originbit.x + 1;	 //	1 [1]
					object.suboriginbit_2.y = object.originbit.y + 1; 	 // 1  1

					break;
				case(ROTATION_3):

					object.suboriginbit_0.x = object.originbit.x + 1;	 //  1  1
					object.suboriginbit_0.y = object.originbit.y;		 //  1 [1]

					object.suboriginbit_1.x = object.originbit.x;		 //	[1] 1
					object.suboriginbit_1.y = object.originbit.y + 1;	 //  1  1

					object.suboriginbit_2.x = object.originbit.x + 1;	 //	1 [1]
					object.suboriginbit_2.y = object.originbit.y + 1; 	 // 1  1

					break;
			}
		break;
	}



	if (check_State() == 0) {
		object = temp;
	}

}

void update_Matrix(void){
	dummyTable[object.originbit.y][object.originbit.x] = 1;
	dummyTable[object.suboriginbit_0.y][object.suboriginbit_0.x] = 1;
	dummyTable[object.suboriginbit_1.y][object.suboriginbit_1.x] = 1;
	dummyTable[object.suboriginbit_2.y][object.suboriginbit_2.x] = 1;

#if MATRIX_LCD == 1
	// Connect to the LCD screen and update that

#elif MATRIX_LCD == 0
	printf("Matrix Representation:\n");

	for (int i = 0; i < ROWS; i++) {
		printf("%3d|", i);
		for (int j = 0; j < COLS; j++) {
			printf("%5d", dummyTable[i][j]);
		}
		printf("\n");
	}

	printf("   +");
	for (int j = 0; j < COLS; j++) {
		printf("-----");
	}
	printf("\n");

	printf("%5s", " ");
	for (int i = 0; i < COLS; i++) {
		printf("%5d", i);
	}
	printf("\n");

#endif

}

