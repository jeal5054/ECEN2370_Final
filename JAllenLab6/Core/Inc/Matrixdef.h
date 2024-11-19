/*
 * Matrixdef.h
 *
 *  Created on: Nov 19, 2024
 *      Author: jeffreya181
 */

#ifndef INC_MATRIXDEF_H_
#define INC_MATRIXDEF_H_

#include <stdint.h>
#include "stm32f4xx_hal.h"

#define pixel_Width 24
#define pixel_Length 24
#define pixel_Area (pixel_Width*pixel_Length)

/*	MATRIX PLAN
 13x10 Grid, x = 0 starts at left screen
 	 	 	 y = 0 starts at bottom of screen
 	 	 	      	  	  	  Tetris <- We have a spare L=8pixels and w= 240 pixels to add whatever
 	y-axis
 	 	12 	 	0	0	0	0	0	0	0	0	0	0
 	 	11 	 	0	0	0	0	0	0	0	0	0	0
 	 	10 	 	0	0	0	0	0	0	0	0	0	0
 	 	9 	 	0	0	0	0	0	0	0	0	0	0
 	 	8 	 	0	0	0	0	0	0	0	0	0	0
 	 	7 	 	0	0	0	0	0	0	0	0	0	0
 	 	6 	 	0	0	0	0	0	0	0	0	0	0
 	 	5 	 	0	0	0	0	0	0	0	0	0	0
 	 	4 	 	0	0	0	0	0	0	0	0	0	0
 	 	3 		0	0	0	0	0	0	0	0	0	0
 	 	2 	 	0	0	0	0	0	0	0	0	0	0
 	 	1 	 	0	0	0	0	0	0	0	0	0	0
 	 	0 	 	0	0	0	0	0	0	0	0	0	0

 	 x-axis     0	1	2	3	4	5	6	7	8	9
 */

static uint8_t RND_FLAG;
static uint8_t dummyTable[13][10];
static uint32_t randomNumber;
typedef enum { // Orioinal Names of Tetris blocks
	ORICKY,
	BRICKY,
	CLEVELAND,
	RHODE,
	HERO,

	/*      1
	 *    1[1]1
	 */
	TEEWEE,

	/*    1 1
	 *   [1]1
	 */
	SMASHBOY
} Tetris_name;

typedef enum{
	ROTATION_0,
	ROTATION_1,
	ROTATION_2,
	ROTATION_3
} rotation;

typedef struct {
	uint8_t x;
	uint8_t y;
} coordinates;

typedef struct {
	Tetris_name name;
	rotation Rotation;
	coordinates originbit;
	coordinates suboriginbit_0;
	coordinates suboriginbit_1;
	coordinates suboriginbit_2;
} Object;

/*
	Equations for Verification and Preventing Errors
*/


/*******
 Equations used for matrix manipulation of variable
*******/
void RND_NUM(void);
Object object_Select(void);
void shift_Left(Object object);
void shift_Right(void);
void transform_Matrix(void);
void check_State(void);
void update_Matrix(void);

#endif /* INC_MATRIXDEF_H_ */
