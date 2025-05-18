/*
 * midi.c
 *
 *  Created on: May 12, 2025
 *      Author: sacha
 */

#include "midi.h"
//Forme message MIDI : Status, Data 1, Data 2

// Fonction d'envoi d'un changement de de son dans la banque MIDI
void ProgramChange(int MIDISoundNumber)
{
    int data[2] = {0xC0, MIDISoundNumber};  // le changement de programme se fait sur le canal 1 car 0xC0
    HAL_UART_Transmit(&huart1, data, 2, HAL_MAX_DELAY);
}

// Fonction pedale MIDI changement de valeur d'un bouton au fonctionnement définit

void ControlChange(int pedalValue,int effect)
{
    int data[3] = {0xB0, effect, pedalValue};  // 0xB0 = Control Change sur canal 1 bouton 0
    HAL_UART_Transmit(&huart1, data, 3, HAL_MAX_DELAY);
}

// Recupere la valeur du potentiometre suivant l'inclinaison de la pédale et la convertit en un nombre entre 0 127
uint8_t ADCValue(void)
{
	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
    uint12_t lastADCValue = HAL_ADC_GetValue(&hadc1); //Lit la valeur analogique convertie
    HAL_ADC_Stop(&hadc1); // economie d'energie on éteint l'adc si il n'est pas utilisé.
    return (uint8_t)((lastADCValue * 127) / 4095);
}


