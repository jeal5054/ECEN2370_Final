/*
 * Matrixdef.c
 *
 *  Created on: Nov 19, 2024
 *      Author: jeffreya181
 */
#include "Matrixdef.h"

#define MATRIX_LCD 1

static Object object;
static uint8_t dummyTable[ROWS][COLS];
static uint32_t randomNumber;
static uint16_t tickNum;

void START_SCREEN(void){
#if MATRIX_LCD == 1
	LCD_Clear(0,LCD_COLOR_BLUE);
	LCD_SetTextColor(LCD_COLOR_WHITE);
	LCD_SetFont(&Font16x24);
	// TETRIS
	LCD_DisplayChar(70,110,'T');
	LCD_DisplayChar(90,110,'E');
	LCD_DisplayChar(110,110,'T');
	LCD_DisplayChar(130,110,'R');
	LCD_DisplayChar(150,110,'I');
	LCD_DisplayChar(170,110,'S');
	// PRESS
	LCD_DisplayChar(80,130,'P');
	LCD_DisplayChar(100,130,'R');
	LCD_DisplayChar(120,130,'E');
	LCD_DisplayChar(140,130,'S');
	LCD_DisplayChar(160,130,'S');
	// BUTTON
	LCD_DisplayChar(70,150,'B');
	LCD_DisplayChar(90,150,'U');
	LCD_DisplayChar(110,150,'T');
	LCD_DisplayChar(130,150,'T');
	LCD_DisplayChar(150,150,'O');
	LCD_DisplayChar(170,150,'N');
	// TO
	LCD_DisplayChar(110,170,'T');
	LCD_DisplayChar(130,170,'O');
	// START
	LCD_DisplayChar(80,190,'S');
	LCD_DisplayChar(100,190,'T');
	LCD_DisplayChar(120,190,'A');
	LCD_DisplayChar(140,190,'R');
	LCD_DisplayChar(160,190,'T');

#else
	int rows = 13, cols = 10;  // Width set to 10
	    char matrix_enc[13][10];

	    // Initialize the matrix with spaces
	    for (int i = 0; i < rows; i++) {
	        for (int j = 0; j < cols; j++) {
	            matrix_enc[i][j] = ' ';
	        }
	    }

	    // Add text to the matrix (manually adjusting for 10 columns)
	    const char lines[13][10] = {
	        "          ",
	        "          ",
	        "  TETRIS  ",
	        "          ",
	        "          ",
	        "   PRESS  ",
	        "          ",
	        "  BUTTON  ",
	        "          ",
	        "    TO    ",
	        "          ",
	        "   START  ",
	        "          "
	    };

	    // Copy the text into the matrix
	    for (int i = 0; i < rows; i++) {
	        for (int j = 0; j < cols; j++) {
	            matrix_enc[i][j] = lines[i][j];
	        }
	    }

	    // Print the matrix
	    for (int i = 0; i < rows; i++) {
	        for (int j = 0; j < cols; j++) {
	            printf("%c", matrix_enc[i][j]);
	        }
	        printf("\n");
	    }
#endif
}

void GAME_OVER(uint32_t total_time) { // code for displaying game over
#if MATRIX_LCD == 1
	LCD_Clear(0,LCD_COLOR_BLUE);
	LCD_SetTextColor(LCD_COLOR_WHITE);
	LCD_SetFont(&Font16x24);

	// GAME
	LCD_DisplayChar(90,100,'G');
	LCD_DisplayChar(110,100,'A');
	LCD_DisplayChar(130,100,'M');
	LCD_DisplayChar(150,100,'E');
	// OVER
	LCD_DisplayChar(90,130,'O');
	LCD_DisplayChar(110,130,'V');
	LCD_DisplayChar(130,130,'E');
	LCD_DisplayChar(150,130,'R');
	// TIME:
	LCD_DisplayChar(85,160,'T');
	LCD_DisplayChar(105,160,'I');
	LCD_DisplayChar(125,160,'M');
	LCD_DisplayChar(145,160,'E');
	LCD_DisplayChar(165,160,':');

	//Timer to keep tract
	// t_on = ARR / 16MHz
	total_time = total_time / 1599999;
	uint32_t minutes = total_time / 60;
	uint32_t seconds = total_time % 60;

	char m1 = '0' + (minutes / 10);  // Tens place of minutes
	char m2 = '0' + (minutes % 10);  // Units place of minutes
	char s1 = '0' + (seconds / 10);  // Tens place of seconds
	char s2 = '0' + (seconds % 10);  // Units place of seconds

	LCD_DisplayChar(85,190,m1);
	LCD_DisplayChar(105,190,m2);
	LCD_DisplayChar(125,190,':');
	LCD_DisplayChar(145,190,s1);
	LCD_DisplayChar(165,190,s2);


#else
	char matrix_enc[ROWS][COLS];

		// Initialize the matrix with spaces
		for (int i = 0; i < ROWS; i++) {
			for (int j = 0; j < COLS; j++) {
				matrix_enc[i][j] = ' ';
			}
		}

		// Add text to the matrix (manually adjusting for 10 columns)
		const char lines[ROWS][COLS] = {
			"          ",
			"          ",
			"   GAME   ",
			"          ",
			"   OVER   ",
			"          ",
			"          ",
			"   TIME:  ",
			"          ",
			"   --:--  ",
			"          ",
			"          ",
			"          "
		};

		// update Matrix
		for (int i = 0; i < ROWS; i++) {
			for (int j = 0; j < COLS; j++) {
				matrix_enc[i][j] = lines[i][j];
			}
		}

		// Format the total time (in minutes and seconds)
		uint32_t minutes = total_time / 60;
		uint32_t seconds = total_time % 60;

		// display time
		matrix_enc[9][3] = (minutes / 10) + '0';  // Ten minutes
		matrix_enc[9][4] = (minutes % 10) + '0';  // minutes
		matrix_enc[9][5] = ':';
		matrix_enc[9][6] = (seconds / 10) + '0';  //tens
		matrix_enc[9][7] = (seconds % 10) + '0';  //single seconds

		for (int i = 0; i < ROWS; i++) {
			for (int j = 0; j < COLS; j++) {
				printf("%c", matrix_enc[i][j]);
			}
			printf("\n");
		}
#endif
}

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
	    printf("Error Generating Random Number");
	}
	   RND = RND % 7;  // Constrain the result to 0-6
	   randomNumber = RND;
	   //printf("Random Number: %ld", randomNumber);
}
/*
uint8_t check_State(void) {
	coordinates bits[] = {
		object.originbit,
		object.suboriginbit_0,
		object.suboriginbit_1,
		object.suboriginbit_2
	};

	if((bits[0].y == 0) || (bits[1].y == 0) || (bits[2].y == 0) || (bits[3].y ==0) ||
	   (dummyTable[bits[0].y][bits[0].x] == 1) || (dummyTable[bits[1].y][bits[1].x] == 1) ||
	   (dummyTable[bits[2].y][bits[2].x] == 1) || (dummyTable[bits[3].y][bits[3].x] == 1)
	){
		if(((bits[0].y == ROWS) || (bits[1].y == ROWS) || (bits[2].y == ROWS) || (bits[3].y == ROWS)) && (
		   (dummyTable[bits[0].y][bits[0].x] == 1) || (dummyTable[bits[1].y][bits[1].x] == 1) ||
		   (dummyTable[bits[2].y][bits[2].x] == 1) || (dummyTable[bits[3].y][bits[3].x] == 1))
		   ){
			return END_GAME;
		   }
		return COLLISION;
	} else if(((bits[0].x < 0) || (bits[0].x > COLS)) || ((bits[1].x < 0) || (bits[1].x > COLS)) ||
			  ((bits[2].x < 0) || (bits[2].x > COLS)) || ((bits[3].x < 0) || (bits[3].x > COLS))
	){
		return COLLISION;
	} else {
		return SAFE;
	}
}
*/
uint8_t check_State(void) {
    coordinates bits[] = {
        object.originbit,
        object.suboriginbit_0,
        object.suboriginbit_1,
        object.suboriginbit_2
    };

    // Check bounds and collisions
    for (int i = 0; i < 4; i++) {
        // Horizontal bounds
        if (bits[i].x < 0 || bits[i].x >= COLS) {
        	printf(" Out of horizontal bounds\n");
            return COLLISION; // Out of horizontal bounds
        }

        // Vertical bounds
        if (bits[i].y < 0) {
        	printf("hit bottom\n");
            return COLLISION; // Hit the bottom
        }

        // Check for collisions with existing blocks
        if (dummyTable[bits[i].y][bits[i].x] == 1) {
            if (bits[i].y >= ROWS - 1) { // Game over condition
            	printf("Hit top\n");
                return END_GAME;
            }
            printf("block_hit\n");
            return COLLISION;
        }
    }
    printf("Safe Matrix\n");
    // If all checks pass, the position is safe
    return SAFE;
}


void check_Decide(uint8_t state, Object temp) {
    printf("check_State result: %d\n", state);
    switch (state) {
        case END_GAME:
            removeSchedulerEvent(MATRIX_UPDATE_EVENT);
            addScheduledEvent(MATRIX_END_EVENT);
            break;

        case COLLISION:
        	/*
            object = temp; // Restore object state
            printf("Update Matrix\n");
            Matrix_update(); // Lock the block in place
            printf("Select Matrix\n");
            object_Select(); // Spawn a new tetris block
            break;
            */
        	Matrix_update(); // Update grid with current tetromino
        	Matrix_clear(); // Clear previous state

        case SAFE:
        	Matrix_update(); // Update grid with current tetromino
            Matrix_clear(); // Clear previous state
            break;

        default:
            printf("ERROR: Invalid state\n");
            break;
    }
}

void object_Select(void){
	RND_NUM();
	//Object temp = object;
	switch(randomNumber) {
		case(ORICKY):
			object = (Object){ORICKY, ROTATION_0-1, {5, 10}, {5, 10}, {5, 10}, {5, 10}}; //Cool trick I found
			/*Object Oricky = {
				.name = ORICKY,
				.Rotation = ROTATION_0 - 1,			  //       1
				.originbit = { .x = 5, .y = 12 },     // 1 [1] 1
				.suboriginbit_0 = {0, 0}, 
				.suboriginbit_1 = {0, 0},
				.suboriginbit_2 = {0, 0}
			};
			object = Oricky;*/
			break;

		case(BRICKY):
			Object Bricky = {
				.name = BRICKY,
				.Rotation = ROTATION_0 - 1,           // 1
				.originbit = { .x = 5, .y = 10 },     // 1 [1] 1
				.suboriginbit_0 = {5, 10},
				.suboriginbit_1 = {5, 10},
				.suboriginbit_2 = {5, 10}
			};
			object = Bricky;
			break;

		case(CLEVELAND):
			Object Cleveland = {
				.name = CLEVELAND,
				.Rotation = ROTATION_0 - 1,           //   1 1
				.originbit = { .x = 5, .y = 10 }, 	  //    [1] 1
				.suboriginbit_0 = {5, 10},
				.suboriginbit_1 = {5, 10},
				.suboriginbit_2 = {5, 10}
			};
			object = Cleveland;
			break;

		case(RHODE):
			Object Rhode = {
				.name = RHODE,
				.Rotation = ROTATION_0 - 1,           //        1 1
				.originbit = { .x = 5, .y = 10 },     //     1 [1]
				.suboriginbit_0 = {5, 10},
				.suboriginbit_1 = {5, 10},
				.suboriginbit_2 = {5, 10}
			};
			object = Rhode;
			break;

		case(HERO):
			Object Hero = {
				.name = HERO,
				.Rotation = ROTATION_0 - 1,          	     //
				.originbit = { .x = 5, .y = 10 }, 			 //  1 1 [1] 1
				.suboriginbit_0 = {5, 10},
				.suboriginbit_1 = {5, 10},
				.suboriginbit_2 = {5, 10}
			};
			object = Hero;
			break;

		case(TEEWEE):
			Object Teewee = {
				.name = TEEWEE,
				.Rotation = ROTATION_0 - 1,          			//    1
				.originbit = { .x = 5, .y = 10 }, 			 	// 1 [1] 1
				.suboriginbit_0 = {5, 10},
				.suboriginbit_1 = {5, 10},
				.suboriginbit_2 = {5, 10}
			};
			object = Teewee;
			break;

		case(SMASHBOY):
			Object Smashboy = {
				.name = SMASHBOY,
				.Rotation = ROTATION_0 - 1,          			// 1  1
				.originbit = { .x = 5, .y = 10 }, 			 	//[1] 1
				.suboriginbit_0 = {0, 0},
				.suboriginbit_0 = {5, 10},
				.suboriginbit_1 = {5, 10},
				.suboriginbit_2 = {5, 10}
			};
			object = Smashboy;
			break;

	}
	transform_rotation();
	//check_Decide(check_State(), temp);
}

void shift_Left(uint16_t X){
	// Get object into our grid
	X = X%COLS;
	Object temp = object;
	object.originbit.x = X;
	object.Rotation -= 1;
	transform_rotation();
	check_Decide(check_State(), temp);
}

void shift_Right(uint16_t X){
	// Get object into our grid
	X = X%COLS;
	Object temp = object;
	object.originbit.x = X;
	object.Rotation -= 1;
	transform_rotation();
	check_Decide(check_State(), temp);
}

void transform_rotation(){
	//Matrix_clear();
	Object temp = object;
	object.Rotation += 1;
	if((object.Rotation > 3) || (object.Rotation < 0)) {
		object.Rotation = 0;
	}
	if((object.Rotation != ROTATION_0) && (object.Rotation != ROTATION_1) &&
	   (object.Rotation != ROTATION_2) && (object.Rotation != ROTATION_0)){
		object.Rotation = ROTATION_0;
	}
	switch(object.name){
		case(ORICKY):
			switch(object.Rotation) {
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
			switch(object.Rotation) {
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
					object.suboriginbit_0.y = object.originbit.y + 1;

					object.suboriginbit_1.x = object.originbit.x + 1;
					object.suboriginbit_1.y = object.originbit.y + 1;

					object.suboriginbit_2.x = object.originbit.x;
					object.suboriginbit_2.y = object.originbit.y - 1;

					break;
				case(ROTATION_2):
						// 1 [1] 1
						//       1
					object.suboriginbit_0.x = object.originbit.x + 1;
					object.suboriginbit_0.y = object.originbit.y;

					object.suboriginbit_1.x = object.originbit.x - 1;
					object.suboriginbit_1.y = object.originbit.y;

					object.suboriginbit_2.x = object.originbit.x + 1;
					object.suboriginbit_2.y = object.originbit.y - 1;

					break;
				case(ROTATION_3):
						//   1
						//  [1]
						// 1 1
					object.suboriginbit_0.x = object.originbit.x;
					object.suboriginbit_0.y = object.originbit.y - 1;

					object.suboriginbit_1.x = object.originbit.x;
					object.suboriginbit_1.y = object.originbit.y + 1;

					object.suboriginbit_2.x = object.originbit.x - 1;
					object.suboriginbit_2.y = object.originbit.y + 1;

					break;
			}

			break;
		case(CLEVELAND):
			switch(object.Rotation) {
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
			switch(object.Rotation) {
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
			switch(object.Rotation) {
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
			switch(object.Rotation) {
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
			switch(object.Rotation) {
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
	check_Decide(check_State(), temp);
}

void tick_Matrix(void) {
	 // erase the previous state
	tickNum++;
	if( (object.Rotation == 0) && (object.name == 0) && (object.originbit.x == 0) && (object.originbit.y == 0) ) {
		Object temp = object;
		// create the new object location
		object.originbit.y -= 1;
		object.suboriginbit_0.y -= 1;
		object.suboriginbit_1.y -= 1;
		object.suboriginbit_2.y -= 1;
		// draw the new state
		printf("Ticking Matrix\n");
		check_Decide(check_State(), temp);
		printf("Ticking Matrix1\n");
		printMatrix();
		printf("Ticking Matrix2\n");
	}
	printf("Tick Num:%d\n",tickNum);
}

void printMatrix(void){
#if MATRIX_LCD == 1
	// Connect to the LCD screen and update that
/*
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			uint8_t value = dummyTable[i][j];
			uint32_t color;
			if(value){
				color = LCD_COLOR_RED;
			} else {
				color = LCD_COLOR_WHITE;
			}

			for (int row = 0; row < BLOCK_HEIGHT; row++) {
				for (int col = 0; col < BLOCK_WIDTH; col++) {
					LCD_Draw_Pixel((j*24)+col,(i*24)+row,color);
				}
			}

		}
	}
	*/
	printf("Printing Matrix\n");
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			uint8_t value = dummyTable[i][j];
			if(value){
				// Calculate top-left corner of the block
				int x = j * 24;//BLOCK_WIDTH;
				int y = i * 24;//BLOCK_HEIGHT;

				// Draw the block on the screen
				for (int row = 0; row < BLOCK_HEIGHT; row++) {
					for (int col = 0; col < BLOCK_WIDTH; col++) {
						LCD_Draw_Pixel(x+col,y+row,LCD_COLOR_RED);
					}
				}
			} else {
				int x = j * 24;//BLOCK_WIDTH;
				int y = i * 24;//BLOCK_HEIGHT;

				// Draw the block on the screen

				for (int row = 0; row < BLOCK_HEIGHT; row++) {
					for (int col = 0; col < BLOCK_WIDTH; col++) {
						LCD_Draw_Pixel(x+col,y+row,LCD_COLOR_WHITE);
					}
				}
			}
		}
	}
#elif MATRIX_LCD == 0
	printf("Matrix Representation:\n");

	for (int i = ROWS-1; i >= 0; i--) {
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

void Matrix_clear(void) {
	dummyTable[object.originbit.y][object.originbit.x] = 0;
	dummyTable[object.suboriginbit_0.y][object.suboriginbit_0.x] = 0;
	dummyTable[object.suboriginbit_1.y][object.suboriginbit_1.x] = 0;
	dummyTable[object.suboriginbit_2.y][object.suboriginbit_2.x] = 0;
}
void Matrix_update(void){
	dummyTable[object.originbit.y][object.originbit.x] = 1;
	dummyTable[object.suboriginbit_0.y][object.suboriginbit_0.x] = 1;
	dummyTable[object.suboriginbit_1.y][object.suboriginbit_1.x] = 1;
	dummyTable[object.suboriginbit_2.y][object.suboriginbit_2.x] = 1;
}
