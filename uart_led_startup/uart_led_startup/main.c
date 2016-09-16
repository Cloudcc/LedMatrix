/*
 * main.c
 *
 *  Created on: 2016 Sep 15 21:00:42
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

void draw_screen(uint8_t data[]);

int main(void) {
	DAVE_STATUS_t status;
	UART_STATUS_t init_status;
	uint8_t trigger[1];
	uint8_t msg[] = "Running...";
	uint8_t data1[] = { 1, 0, 0, 0, 0, 0, 0, 1 };
	uint8_t data2[] = { 0, 0, 0, 0, 0, 0, 0, 1 };
	uint8_t data3[] = { 1, 0, 0, 0, 0, 0, 0, 0 };
	uint8_t data4[] = { 0, 0, 1, 0, 1, 1, 0, 0 };
	uint8_t data5[] = { 0, 0, 1, 1, 0, 1, 0, 0 };
	uint8_t clear[] = { 0, 0, 0, 0, 0, 0, 0, 0 };

	uint8_t pattern_x[] = { 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0,
			0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0,
			0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0,
			1, };

	status = DAVE_Init(); /* Initialization of DAVE APPs  */

	if (status != DAVE_STATUS_SUCCESS) {
		/* Placeholder for error handler code. The while loop below can be replaced with an user error handler. */
		XMC_DEBUG("DAVE APPs initialization failed\n");

		while (1U) {

		}
	}
	// Set Pins to Low
	DIGITAL_IO_SetOutputLow(&DIGITAL_IO_0);	// shift 	SH_CP
	DIGITAL_IO_SetOutputLow(&DIGITAL_IO_1);	// storage 	ST_CP
	DIGITAL_IO_SetOutputLow(&DIGITAL_IO_2);	// data		DS

	// init UART
	init_status = (UART_STATUS_t) UART_Init(&UART_0);
	if (init_status == UART_STATUS_SUCCESS) {
		UART_Transmit(&UART_0, msg, sizeof(msg) - 1);
		while (1) {
			if (UART_Receive(&UART_0, trigger, 1) == UART_STATUS_SUCCESS) {
				if (trigger[0] == '1') draw_screen(pattern_x);
			}
		}
	} else {
		XMC_DEBUG("Application initialization failed");
		while (1U) {
		}
	}
	return 1U;
}

void draw_screen(uint8_t data[]) {

	for (uint8_t i = 0; i < 64; i++) {
		uint8_t dat[] = { 0, 0, 0, 0, 0, 0, 0, 1 };
		for (uint8_t j = i; j < 8 + i; j++) {
			if (data[i] == 0x01UL) DIGITAL_IO_SetOutputHigh(&DIGITAL_IO_2);
			if (data[i] == 0x00UL) DIGITAL_IO_SetOutputLow(&DIGITAL_IO_2);

			DIGITAL_IO_SetOutputHigh(&DIGITAL_IO_0);
			DIGITAL_IO_SetOutputLow(&DIGITAL_IO_0);

		}
		for (uint8_t c = 0; c < 8 ; c++) {
			if (dat[i] == 0x01UL) DIGITAL_IO_SetOutputHigh(&DIGITAL_IO_2);
			if (dat[i] == 0x00UL) DIGITAL_IO_SetOutputLow(&DIGITAL_IO_2);

			DIGITAL_IO_SetOutputHigh(&DIGITAL_IO_0);
			DIGITAL_IO_SetOutputLow(&DIGITAL_IO_0);

		}
		DIGITAL_IO_SetOutputHigh(&DIGITAL_IO_1);
		DIGITAL_IO_SetOutputLow(&DIGITAL_IO_1);

	}
}
