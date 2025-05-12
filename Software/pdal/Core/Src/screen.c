/*
 * screen.c
 *
 *  Created on: Mar 10, 2025
 *      Author: sacha
 */

#include "screen.h"

void screen_display(void) {
	static int display_number = 0;

    if (display_number == 0) {
        GPIOB->ODR = array[global_to_display / 10]; // Chiffre des dizaines
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);  // COM0 = 1
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET); // COM1 = 0
    } else {
        GPIOB->ODR = array[global_to_display % 10]; // Chiffre des unités
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET); // COM0 = 0
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET);  // COM1 = 1
    }

    display_number = 1 - display_number;
}
