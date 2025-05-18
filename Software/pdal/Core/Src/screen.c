/*
 * screen.c
 *
 *  Created on: Mar 10, 2025
 *      Author: sacha
 */

#include "screen.h"

void screenDisplay(void) {
	static int displayNumber = 0;

    if (displayNumber == 0) {
        GPIOB->ODR = array[globalToDisplay / 10]; // Chiffre des dizaines
        HAL_GPIO_WritePin(GPIOA, COM0, GPIO_PIN_SET);  // COM0 = 1
        HAL_GPIO_WritePin(GPIOA, COM1, GPIO_PIN_RESET); // COM1 = 0
    } else {
        GPIOB->ODR = array[globalToDisplay % 10]; // Chiffre des unités
        HAL_GPIO_WritePin(GPIOA, COM0, GPIO_PIN_RESET); // COM0 = 0
        HAL_GPIO_WritePin(GPIOA, COM1, GPIO_PIN_SET);  // COM1 = 1
    }

    displayNumber = 1 - displayNumber;
}
