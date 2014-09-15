/*
  ************************************************************************
  *	pins_energia.h
  *
  *	Pin definition functions for SEAM-WiT Implant Prototype
  *		Copyright (c) 2014 Sebastian Stöcklin. All right reserved.
  *
  ***********************************************************************
  Derived from:

  pins_arduino.h - Pin definition functions for Arduino
  Part of Energia - http://www.energia.nu/

  Copyright (c) 2012 Robert Wessels. All right reserved.

  ... and from:

  pins_arduino.h - Pin definition functions for Arduino
  Part of Arduino - http://www.arduino.cc/

  Copyright (c) 2007 David A. Mellis

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA
*/

#ifndef Pins_Energia_h
#define Pins_Energia_h
#ifndef BV
#define BV(x) (1 << (x))
#endif

#if defined(__MSP430_HAS_EUSCI_B0__)
static const uint8_t SS      = 11;  /* only external CS when working as master, real SS not connected */
static const uint8_t SCK     = 12;  /* P2.2 */
static const uint8_t MOSI    = 13;  /* P1.6 aka SIMO */
static const uint8_t MISO    = 14;  /* P1.7 aka SOMI */
static const uint8_t TWISDA  = 13;  /* P1.6 */
static const uint8_t TWISCL  = 14;  /* P1.7 */
#define TWISDA_SET_MODE  (PORT_SELECTION1 | INPUT_PULLUP)
#define TWISCL_SET_MODE  (PORT_SELECTION1 | INPUT_PULLUP)
#endif

#if defined(__MSP430_HAS_EUSCI_A0__)
static const uint8_t DEBUG_UARTRXD = 11;  /* Receive  Data (RXD) at P2.1 */
static const uint8_t DEBUG_UARTTXD = 10;  /* Transmit Data (TXD) at P2.0 */
#define DEBUG_UARTRXD_SET_MODE (PORT_SELECTION1 | INPUT)
#define DEBUG_UARTTXD_SET_MODE (PORT_SELECTION1 | OUTPUT)
#define DEBUG_UART_MODULE_OFFSET 0x00
#endif


/* Analog pins */
/* Note: In contrast to other Energia pin mappings, the Ax names correspond to those of the datasheet */

static const uint8_t A0  = 1;	/* 1 - P1.0 */
static const uint8_t A1  = 2;   /* 2 - P1.1 */
static const uint8_t A2  = 3;   /* 3 - P1.2 */
static const uint8_t A3  = 4;   /* 4 - P1.3 */
static const uint8_t A4  = 5;   /* 5 - P1.4 */
static const uint8_t A5  = 6;   /* 6 - P1.5 */

// still there from Fraunchpad pin mapping (maybe there is a need for a change):
static const uint8_t A10 = 128 + 10; //Special this is device's internal temp sensor */
static const uint8_t A11 = 128 + 11; //Special this is Vcc/2 */


/* special pin functions (corresponding to schematic names) */

static const uint8_t VcoilSlow 		= 1;
static const uint8_t VrefPWM 		= 2;
static const uint8_t SlicedData		= 3;
static const uint8_t Vshunt			= 4;
static const uint8_t VhvMeas 		= 5;
static const uint8_t Modulation		= 6;
static const uint8_t BoostDisable 	= 7;
static const uint8_t PowerData	 	= 8;
static const uint8_t PowerEnable	= 9;
static const uint8_t MSPTX 			= 10;
static const uint8_t MSPRX	 		= 11;


/* Pin names based on the TI port and pin names */

static const uint8_t P1_0 = 1;
static const uint8_t P1_1 = 2;
static const uint8_t P1_2 = 3;
static const uint8_t P1_3 = 4;
static const uint8_t P1_4 = 5;
static const uint8_t P1_5 = 6;
static const uint8_t PJ_0 = 7;
static const uint8_t PJ_1 = 8;
static const uint8_t PJ_3 = 9;
static const uint8_t P2_0 = 10;
static const uint8_t P2_1 = 11;
static const uint8_t P2_2 = 12;
static const uint8_t P1_6 = 13;
static const uint8_t P1_7 = 14;


#ifdef ARDUINO_MAIN

const uint16_t port_to_input[] = {
	NOT_A_PORT,
	(uint16_t) &P1IN,
	(uint16_t) &P2IN,
#ifdef __MSP430_HAS_PORT3_R__
	(uint16_t) &P3IN,
#endif
#ifdef __MSP430_HAS_PORT4_R__
	(uint16_t) &P4IN,
#endif
#ifdef __MSP430_HAS_PORTJ_R__
	(uint16_t) &PJIN,
#endif
};

const uint16_t port_to_output[] = {
	NOT_A_PORT,
	(uint16_t) &P1OUT,
	(uint16_t) &P2OUT,
#ifdef __MSP430_HAS_PORT3_R__
	(uint16_t) &P3OUT,
#endif
#ifdef __MSP430_HAS_PORT4_R__
	(uint16_t) &P4OUT,
#endif
#ifdef __MSP430_HAS_PORTJ_R__
	(uint16_t) &PJOUT,
#endif
};

const uint16_t port_to_dir[] = {
	NOT_A_PORT,
	(uint16_t) &P1DIR,
	(uint16_t) &P2DIR,
#ifdef __MSP430_HAS_PORT3_R__
	(uint16_t) &P3DIR,
#endif
#ifdef __MSP430_HAS_PORT4_R__
	(uint16_t) &P4DIR,
#endif
#ifdef __MSP430_HAS_PORTJ_R__
	(uint16_t) &PJDIR,
#endif
};

const uint16_t port_to_ren[] = {
	NOT_A_PORT,
	(uint16_t) &P1REN,
	(uint16_t) &P2REN,
#ifdef __MSP430_HAS_PORT3_R__
	(uint16_t) &P3REN,
#endif
#ifdef __MSP430_HAS_PORT4_R__
	(uint16_t) &P4REN,
#endif
#ifdef __MSP430_HAS_PORTJ_R__
	(uint16_t) &PJREN,
#endif
};

const uint16_t port_to_sel0[] = {
	NOT_A_PORT,
	(uint16_t) &P1SEL0,
	(uint16_t) &P2SEL0,
#ifdef __MSP430_HAS_PORT3_R__
	(uint16_t) &P3SEL0,
#endif
#ifdef __MSP430_HAS_PORT4_R__
	(uint16_t) &P4SEL0,
#endif
#ifdef __MSP430_HAS_PORTJ_R__
	(uint16_t) &PJSEL0,
#endif
};

const uint16_t port_to_sel1[] = {
	NOT_A_PORT,
	(uint16_t) &P1SEL1,
	(uint16_t) &P2SEL1,
#ifdef __MSP430_HAS_PORT3_R__
	(uint16_t) &P3SEL1,
#endif
#ifdef __MSP430_HAS_PORT4_R__
	(uint16_t) &P4SEL1,
#endif
#ifdef __MSP430_HAS_PORTJ_R__
	(uint16_t) &PJSEL1,
#endif
};

/* Definition of single pin attributes
   - the array index corresponds to the pin numbering
 */

const uint8_t digital_pin_to_timer[] = {
	NOT_ON_TIMER,  	 /*  0 - pin count starts at 1 */
	T0A1, 			 /*  1 - P1.0 */
	T0A2, 			 /*  2 - P1.1 */
	T1A1, 			 /*  3 - P1.2 */
	T1A2, 			 /*  4 - P1.3 */
	T0B1, 			 /*  5 - P1.4 */
	T0B2, 			 /*  6 - P1.5 */
	NOT_ON_TIMER,	 /*  7 - PJ.0 */
	NOT_ON_TIMER,	 /*  8 - PJ.1 */
	NOT_ON_TIMER,	 /*  9 - PJ.3 */
	NOT_ON_TIMER,	 /*  10 - P2.0 */
	T0B0, 			 /*  11 - P2.1 */
	T0A1, 			 /*  12 - P2.2 */
	T0A0, 			 /*  13 - P1.6 */
	T1A0 			 /*  14 - P1.7 */

};

const uint8_t digital_pin_to_port[] = {
	NOT_A_PIN, 	/*  0 - pin count starts at 1 */
	P1,			/*  1 - P1.0 */
	P1, 		/*  2 - P1.1 */
	P1, 		/*  3 - P1.2 */
	P1, 		/*  4 - P1.3 */
	P1, 		/*  5 - P1.4 */
	P1, 		/*  6 - P1.5 */
	PJ,			/*  7 - PJ.0 */
	PJ,	 		/*  8 - PJ.1 */
	PJ,	 		/*  9 - PJ.3 */
	P2,	 		/*  10 - P2.0 */
	P2, 		/*  11 - P2.1 */
	P2, 		/*  12 - P2.2 */
	P1, 		/*  13 - P1.6 */
	P1			/*  14 - P1.7 */

};

const uint8_t digital_pin_to_bit_mask[] = {
	NOT_A_PIN,  /*  0 - pin count starts at 1 */
	BV(0),		/*  1 - P1.0 */
	BV(1), 		/*  2 - P1.1 */
	BV(2), 		/*  3 - P1.2 */
	BV(3), 		/*  4 - P1.3 */
	BV(4), 		/*  5 - P1.4 */
	BV(5), 		/*  6 - P1.5 */
	BV(0),		/*  7 - PJ.0 */
	BV(1),	 	/*  8 - PJ.1 */
	BV(3),	 	/*  9 - PJ.3 */
	BV(0),	 	/*  10 - P2.0 */
	BV(1), 		/*  11 - P2.1 */
	BV(2), 		/*  12 - P2.2 */
	BV(6), 		/*  13 - P1.6 */
	BV(7)  		/*  14 - P1.7 */

};

const uint32_t digital_pin_to_analog_in[] = {
	NOT_ON_ADC,  /*  0 - pin count starts at 1 */
	0, 			 /*  1 - P1.0 - A0 */
	1, 			 /*  2 - P1.1 - A1 */
	2, 			 /*  3 - P1.2 - A2 */
	3, 			 /*  4 - P1.3 - A3 */
	4, 			 /*  5 - P1.4 - A4 */
	5, 			 /*  6 - P1.5 - A5 */
	NOT_ON_ADC,	 /*  7 - PJ.0 */
	NOT_ON_ADC,	 /*  8 - PJ.1 */
	NOT_ON_ADC,	 /*  9 - PJ.3 */
	NOT_ON_ADC,	 /*  10 - P2.0 */
	NOT_ON_ADC,  /*  11 - P2.1 */
	NOT_ON_ADC,  /*  12 - P2.2 */
	NOT_ON_ADC,  /*  13 - P1.6 */
	NOT_ON_ADC   /*  14 - P1.7 */
};
#endif
#endif
