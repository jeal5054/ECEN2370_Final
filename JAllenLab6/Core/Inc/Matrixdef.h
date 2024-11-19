/*
 * Matrixdef.h
 *
 *  Created on: Nov 19, 2024
 *      Author: jeffreya181
 */

#ifndef INC_MATRIXDEF_H_
#define INC_MATRIXDEF_H_

#include <stdint.h>

#define pixel_Width 24
#define pixel_Length 24
#define pixel_Area (pixel_Width*pixel_Length)

static uint8_t dummyTable[13][10];

enum { // Orioinal Names of Tetris blocks
	/*      1
	 *    111
	 */
	ORICKY,

	/*    1
	 *    111
	 */
	BRICKY,

	/*   11
	 *    11
	 */
	CLEVELAND,

	/*   11
	 *    11
	 */
	RHODE,

	/*
	 *    1111
	 */
	HERO,

	/*     1
	 *    111
	 */
	TEEWEE,

	/*   11
	 *   11
	 */
	SMASHBOY
}Tetris_name;

typedef struct {
	Tetris_name name = ORICKY;
	uint8_t originbit[13][10];
	uint8_t suboriginbit_0[13][10];
	uint8_t suboriginbit_1[13][10];
	uint8_t suboriginbit_2[13][10];
} Object;
/*
	Equations for Verification and Preventing Errors
*/

/*******
 Equations used for matrix manipulation of variable
*******/
void object_Select(void);
void shift_Left(Object object);
void shift_Right(void);
void transform_Matrix(void);
void check_State(void);
void update_Matrix(void);

#endif /* INC_MATRIXDEF_H_ */
