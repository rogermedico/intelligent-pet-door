/*
 * Copyright (C) 2019 Universitat Oberta de Catalunya - http://www.uoc.edu/
 *
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Universitat Oberta de Catalunya nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

/*----------INCLUDES-------------------------------------------------------------*/

/*----------DEFINES--------------------------------------------------------------*/

/* Uncoment this line to allow debug info to be shown througth the serial. */
#define DEBUG 1

/*----------TYPEDEFS------------------------------------------------------------*/

/*----------VARIABLES-----------------------------------------------------------*/

int npets = 1; //hardcoded!!!

/*----------FUNCTIONS-----------------------------------------------------------*/

/* Common setup function in all arduino projects. Initialize all things here. */
void setup() {
	
	/* Initialize Serial interface */
	initSerial();
	
	/* Initialize servos */
	initServo();

	/* Initialitze sensors interrupts */
	initISR();

	/* Initialize EEPROM */
	initEEPROM();

	/* Initialize Real Time Clock */
	initRTC();
	
	/* Uncoment this if your DS3231 module has lost power or it's the first time you are 
	 * uploading that code to your arduino. Sets the correct date and time to DS3231 module.	 
	 */
	//adjustRTC();
	
	/* Initialize some time related variables to allow checkSchedule() function to run properly */
	initCheckSchedule();
	
	/* Initialize the variables of checkButtons to allow sensors ISR treatment */
	initCheckButtons();
	
	initCheckCommand();
	initCheckNextAction();

	/* Initialize wireless module */
	

}

/* Common loop function in all arduino projects. Main program goes here and iterates forever. Super-loop. */
void loop() {
	
	/* Checks if user has issued a command */
	checkCommand();
	
	/* Checks if programmed next action has to be done */
	checkNextAction();
	
	/* Checks if something programmed has to be done */
	checkSchedule();
	
	/* Checks if sensors have detected some movement */
	checkButtons();
  
}

/*----------INTERRUPTS----------------------------------------------------------*/
