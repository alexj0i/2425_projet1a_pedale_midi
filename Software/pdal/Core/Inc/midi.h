/*
 * midi.h
 *
 *  Created on: May 12, 2025
 *      Author: utilisateur
 */

#ifndef INC_MIDI_H_
#define INC_MIDI_H_

#include "main.h"

#define BUTTON_UP GPIO_PIN_12
#define BUTTON_DOWN GPIO_PIN_11
#define PEDAL GPIO_PIN_0
#define EFFECT 7 //Volume

void ProgramChange(int MIDISoundNumber);
void ControlChange(int pedalValue, int effect);
uint8_t ADCValue(void);

#endif /* INC_MIDI_H_ */
