/*
 * screen.h
 *
 *  Created on: May 12, 2025
 *      Author: utilisateur
 */

#ifndef INC_SCREEN_H_
#define INC_SCREEN_H_

// Variable globale pour stocker le nombre à afficher
extern int global_to_display;

// Tableau contenant les valeurs pour les chiffres de 0 à 9 ( CATHODE COMMUNE )
const uint8_t array[10] =
{
    0b00111111, // 0
    0b00000110, // 1
    0b01011011, // 2
    0b01001111, // 3
    0b01100110, // 4
    0b01101101, // 5
    0b01111101, // 6
    0b00000111, // 7
    0b01111111, // 8
    0b01101111  // 9
};

/* POUR ANODE COMMUNE
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
 */

void screen_display(void);

#endif /* INC_SCREEN_H_ */
