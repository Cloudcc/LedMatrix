/*
 * main.c
 *
 *  Created on: 2016 Sep 24 02:01:27
 *  Author: Johnny
 */

#include <DAVE.h>                 //Declarations from DAVE Code Generation (includes SFR declaration)

/**

 * @brief main() - Application entry point
 *
 * <b>Details of function</b><br>
 * This routine is the application entry point. It is invoked by the device startup code. It is responsible for
 * invoking the APP initialization dispatcher routine - DAVE_Init() and hosting the place-holder for user application
 * code.
 */

void color(uint16_t red, uint16_t green, uint16_t blue);

void delay(uint32_t time) {
	for (uint8_t i = 0; i < time; i++)
		;
}

int main(void) {
	DAVE_STATUS_t status;
	UART_STATUS_t init_status;

	uint8_t col[3];
	uint8_t startMsg[] = "Running...";

	status = DAVE_Init(); /* Initialization of DAVE APPs  */

	if (status != DAVE_STATUS_SUCCESS) {
		/* Placeholder for error handler code. The while loop below can be replaced with an user error handler. */
		XMC_DEBUG("DAVE APPs initialization failed\n");

		while (1U) {

		}
	}

	PWM_SetDutyCycle(&PWM_2, 0);		// Red
	PWM_SetDutyCycle(&PWM_1, 0);		// Green
	PWM_SetDutyCycle(&PWM_0, 0);		// Blue

	init_status = (UART_STATUS_t) UART_Init(&UART_0);
	if (init_status == UART_STATUS_SUCCESS) {
		UART_Transmit(&UART_0, startMsg, sizeof(startMsg) - 1);
		while (1) {
			if (UART_Receive(&UART_0, col, 1) == UART_STATUS_SUCCESS) {
				if(col[0] == 1) color(10000, 0, 0);
				if(col[0] == 2) color(0, 10000, 0);
				if(col[0] == 3) color(0, 0, 10000);
				if(col[0] == 4) color(10000, 0, 10000);
				if(col[0] == 5) color(0, 10000, 10000);
				if(col[0] == 6) color(10000, 10000, 0);
				if(col[0] == 7) color(0, 0, 0);
			}
		}

	} else {
		XMC_DEBUG("APPLICATION FAILED!!!");
		while (1U) {
		}
	}
	return 1U;

}

void color(uint16_t red, uint16_t green, uint16_t blue) {
	PWM_SetDutyCycle(&PWM_2, red);
	PWM_SetDutyCycle(&PWM_1, green);
	PWM_SetDutyCycle(&PWM_0, blue);
}
