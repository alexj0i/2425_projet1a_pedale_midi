/*
 * screen.h
 *
 *  Created on: May 12, 2025
 *      Author: utilisateur
 */

#ifndef INC_SCREEN_H_
#define INC_SCREEN_H_

#include "main.h"

#define GPIO_PORT_B GPIOB
#define COM0 GPIO_PIN_6
#define COM1 GPIO_PIN_5

// Variable globale pour stocker le nombre à afficher
extern int globalToDisplay;

void screenDisplay(void);

#endif /* INC_SCREEN_H_ */
