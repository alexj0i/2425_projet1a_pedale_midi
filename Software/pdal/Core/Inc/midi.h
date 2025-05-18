/*
 * midi.h
 *
 *  Created on: May 12, 2025
 *      Author: utilisateur
 */

#ifndef INC_MIDI_H_
#define INC_MIDI_H_

#define BUTTON_UP ...
#define BUTTON_DOWN ...
#define PEDAL ...
#define EFFECT ...

void ProgramChange(int MIDISoundNumber);
void ControlChange(int pedalValue);
int ADCValue(void);

#endif /* INC_MIDI_H_ */
