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

/*----------VARIABLES-----------------------------------------------------------*/

/* Store the number of pets */
uint8_t npets; 

/*----------FUNCTIONS-----------------------------------------------------------*/

/* Initializes npets variable from EEPROM */
void initPets(){
	
	npets = readEEPROM(NUMBER_OF_PETS_POS);
		
	/* Debug code*/
	#ifdef DEBUG
		Serial.print(F("Number of pets defined: "));
		if(npets == 0xFF)	Serial.println(F("No pets defined"));
		else Serial.println(npets);
	#endif
	
}

/* Redefine number of pets */
void definePetsNumber(uint8_t n){
	
	/* Update number of pets value */
	npets = n;
	writeEEPROM(NUMBER_OF_PETS_POS,n);
	
	/* Reset position of pets */
	npetsIn = n;
	npetsOut = 0;
	
	/* Clear next action to avoid bad behaviour */
	clearNextAction();
			
}

/* Reset number of pets */
void resetPetsNumber(void){
	
	/* Reset number of pets value */
	npets = 0xFF;
	writeEEPROM(NUMBER_OF_PETS_POS,0xFF);
	
	/* Reset position of pets */
	npetsIn = 0xFF;
	npetsOut = 0;
	
	/* Clear next action to avoid bad behaviour */
	clearNextAction();
	
}

/*----------INTERRUPTS----------------------------------------------------------*/