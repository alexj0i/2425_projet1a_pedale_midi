/*
 * screen.c
 *
 *  Created on: Mar 10, 2025
 *      Author: sacha
 */

#include "screen.h"

// Tableau contenant les valeurs pour les chiffres de 0 à 9 ( ANODE COMMUNE )

// Correspondance physique : A=1, B=3, C=4, D=5, E=6, F=7, G=8
// Ordre : A B C D E F G (mappés sur bits 1 3 4 5 6 7 8)
const uint16_t array[10] = {
    (0<<1)|(0<<3)|(0<<4)|(0<<5)|(0<<6)|(0<<7)|(1<<8), // 0
    (1<<1)|(0<<3)|(0<<4)|(1<<5)|(1<<6)|(1<<7)|(1<<8), // 1
    (0<<1)|(0<<3)|(1<<4)|(0<<5)|(0<<6)|(1<<7)|(0<<8), // 2
    (0<<1)|(0<<3)|(0<<4)|(0<<5)|(1<<6)|(1<<7)|(0<<8), // 3
    (1<<1)|(0<<3)|(0<<4)|(1<<5)|(1<<6)|(0<<7)|(0<<8), // 4
    (0<<1)|(1<<3)|(0<<4)|(0<<5)|(1<<6)|(0<<7)|(0<<8), // 5
    (0<<1)|(1<<3)|(0<<4)|(0<<5)|(0<<6)|(0<<7)|(0<<8), // 6
    (0<<1)|(0<<3)|(0<<4)|(1<<5)|(1<<6)|(1<<7)|(1<<8), // 7
    (0<<1)|(0<<3)|(0<<4)|(0<<5)|(0<<6)|(0<<7)|(0<<8), // 8
    (0<<1)|(0<<3)|(0<<4)|(0<<5)|(1<<6)|(0<<7)|(0<<8), // 9
};

#define DOT_PIN    GPIO_PIN_0   // PB0

#define LED10_PIN  GPIO_PIN_4   // PB4
#define LED11_PIN  GPIO_PIN_7   // PB7
#define LED12_PIN  GPIO_PIN_0   // PF0

int globalToDisplay;

void screenDisplay(void) {
	static int displayNumber = 0;

	//Effacement de la virgule pour l'afficheur
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);

	// Efface uniquement les bits des segments (1,3,4,5,6,7,8)
		GPIOA->ODR &= ~( (1<<1) | (1<<3) | (1<<4) | (1<<5) | (1<<6) | (1<<7) | (1<<8) );

    if (displayNumber == 0) {
        GPIOA->ODR = array[globalToDisplay / 10]; // Chiffre des dizaines
        HAL_GPIO_WritePin(GPIO_PORT_B, COM0, GPIO_PIN_SET);  // COM0 = 1
        HAL_GPIO_WritePin(GPIO_PORT_B, COM1, GPIO_PIN_RESET); // COM1 = 0
    } else {
        GPIOA->ODR = array[globalToDisplay % 10]; // Chiffre des unités
        HAL_GPIO_WritePin(GPIO_PORT_B, COM0, GPIO_PIN_RESET); // COM0 = 0
        HAL_GPIO_WritePin(GPIO_PORT_B, COM1, GPIO_PIN_SET);  // COM1 = 1
    }

    displayBar(ADCValue());
    displayNumber = 1 - displayNumber;
}

void displayBar(uint8_t val) {
    static int com = 0; // Alterne entre COM0 et COM1
    int nbLeds = ((127 - val) * 6) / 128;
 // De 0 à 6 LEDs en fonction de l’ADC

    // Remet toutes les LED à 0
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET); // LED10
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET); // LED11
    HAL_GPIO_WritePin(GPIOF, GPIO_PIN_0, GPIO_PIN_RESET); // LED12

    // Active le COM concerné
    if (com == 0) {
        HAL_GPIO_WritePin(GPIO_PORT_B, COM0, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIO_PORT_B, COM1, GPIO_PIN_RESET);
    } else {
        HAL_GPIO_WritePin(GPIO_PORT_B, COM0, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIO_PORT_B, COM1, GPIO_PIN_SET);
    }

    // Allume les bonnes LEDs dans l'ordre LED12 → LED11 → LED10
    if (nbLeds >= 1 + com * 3) HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET); // LED12
       if (nbLeds >= 2 + com * 3) HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET); // LED11
       if (nbLeds >= 3 + com * 3) HAL_GPIO_WritePin(GPIOF, GPIO_PIN_0, GPIO_PIN_SET); // LED10

    com = 1 - com; // Alterne à chaque appel
}
