/*
 * screen.c
 *
 *  Created on: Mar 10, 2025
 *      Author: sacha
 */

#include "screen.h"

// Tableau contenant les valeurs pour les chiffres de 0 à 9 ( ANODE COMMUNE )

const uint8_t array[10] =
{
    0b11000000, // 0
    0b11111001, // 1
    0b10100100, // 2
    0b10110000, // 3
    0b10011001, // 4
    0b10010010, // 5
    0b10000010, // 6
    0b11111000, // 7
    0b10000000, // 8
    0b10010000  // 9
};

int globalToDisplay;

void screenDisplay(void) {
	static int displayNumber = 0;

    if (displayNumber == 0) {
        GPIOB->ODR = array[globalToDisplay / 10]; // Chiffre des dizaines
        HAL_GPIO_WritePin(GPIO_PORT_B, COM0, GPIO_PIN_SET);  // COM0 = 1
        HAL_GPIO_WritePin(GPIO_PORT_B, COM1, GPIO_PIN_RESET); // COM1 = 0
    } else {
        GPIOB->ODR = array[globalToDisplay % 10]; // Chiffre des unités
        HAL_GPIO_WritePin(GPIO_PORT_B, COM0, GPIO_PIN_RESET); // COM0 = 0
        HAL_GPIO_WritePin(GPIO_PORT_B, COM1, GPIO_PIN_SET);  // COM1 = 1
    }

    displayNumber = 1 - displayNumber;
}
