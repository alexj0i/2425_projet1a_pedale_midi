/*
 * configuration du ADC
 * Mode : Continuous Conversion
 * Trigger : Software Start
 */

/*
 * configuration TIMER
Prescaler: 7999
Counter Period: 9
Interrupts: Update Event
 *
 */

int last_button_time = 0; // Anti-rebonds

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    if (htim->Instance == TIM4) {
    	screen_display();
    }
}

/* Fonction de callback des boutons */
void HAL_GPIO_EXTI_Callback(int GPIO_Pin)
{
    if ((HAL_GetTick() - last_button_time) > 50)
    { // Anti-rebonds 50ms
       	switch(GPIO_Pin)
       	{
       	case GPIO_PIN_0:
            global_to_display++;
            if (global_to_display > 127) //RQ: pour moi 127 car une data en midi = 1 octet donc au max 128 sons différents possibles
            {
            }
            // Change l'instrument virtuel suivant le numero affiché sur l'ecran en piochant le son associé dans la banque MIDI.
            sendProgramChange(global_to_display);
            break;
    	case GPIO_PIN_1:
            global_to_display--;
            if (global_to_display < 0)
            {
            }
            // Change l'instrument virtuel suivant le numero affiché sur l'ecran en piochant le son associé dans la banque MIDI.
            sendProgramChange(global_to_display);
            break;
    	case PEDAL:
    		ControlChange(ADC_value());
    		break;

       	}

        last_button_time = HAL_GetTick();
    }
}
