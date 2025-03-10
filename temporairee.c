/*
 * temporaire.c
 *
 *  Created on: Mar 10, 2025
 *      Author: sacha
 */


// Definition du message MIDI (à mettre dans le fichier.h)
#define MIDI_CHANNEL XXXX // à fixer
#define CONTROL_CHANGE XXXX // à fixer
#define CONTROL_NUMBER XXXX // à fixer


/*
 *Forme message MIDI : Status, Data 1, Data 2
 *Status = forme un byte qui contient l'information du channel et du message(ici Control Change)
 *Data 1 = la valeur qui identifie le programme
 *Data 2 = valeur donnée à l'effet du programme
 */

//envoi d'un message MIDI
void sendMIDI(int status, int data1, int data2) {
	uint8_t data[3] = {status, data1, data2};
	HAL_UART_Transmit(&huart1, data, 3, HAL_MAX_DELAY);
}

/*
 * à mettre dans le main.c
 * sendMIDI(CONTROL_CHANGE | MIDI_CHANNEL , CONTROL_NUMBER, pedalMIDIValue); 
*/