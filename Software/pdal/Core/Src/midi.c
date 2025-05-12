/*
 * midi.c
 *
 *  Created on: Mar 10, 2025
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

void ControlChange(int pedalValue)
{
    int data[3] = {0xB0, 0, pedalValue};  // 0xB0 = Control Change sur canal 1 bouton 0
    HAL_UART_Transmit(&huart1, data, 3, HAL_MAX_DELAY);
}

// Recupere la valeur du potentiometre suivant l'inclinaison de la pédale et la convertit en un nombre entre 0 127
int ADC_value(void)
{
    int adcValue = HAL_ADC_GetValue(&hadc1);//Lit la valeur convertie
    HAL_ADC_Stop(&hadc1);
    return (uint8_t)((adcValue * 127) / 4095);
}


