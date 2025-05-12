/*
 * midi.h
 *
 *  Created on: May 12, 2025
 *      Author: utilisateur
 */

#ifndef INC_MIDI_H_
#define INC_MIDI_H_


void ProgramChange(int MIDISoundNumber);
void ControlChange(int pedalValue);
int ADC_value(void);

#endif /* INC_MIDI_H_ */
