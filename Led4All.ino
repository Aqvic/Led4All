/* 
 *  https://github.com/Aqvic/Led4All
*/

const byte chCount = 4;

const byte  inPins[chCount] = {23, 24, 25, 26}; //a0, a1, a2, a3
const byte outPins[chCount] = {3, 9, 10, 11};

void setup() {   

    // set[frequency]PWM() works only for D3, D9, D10, D11 
    // For D5, D6 we use default 1Khz always. See Timer0 notice in PWM_frequency.txt
    // Uncomment one of them to choose frequency. Or leave all commented for default 500Hz:
    
    //set31KHzPWM();  // 31372.55 Hz
    //set4KHzPWM();   //  3921.16 Hz
    //set500HzPWM();  //   490.20 Hz DEFAULT (Notice: default PWM frequency can depend from bootloader)
    //set120HzPWM();  //   122.55 Hz
    //set30HzPWM();   //    30.64 Hz

    //initialize output pins to uotput & 0 value
    for(int i=0; i<chCount; i++){
        pinMode(outPins[i], OUTPUT);
        analogWrite(outPins[i], 0);
    }
}

void loop() {
    for(int i=0; i<chCount; i++){
        analogWrite(outPins[i], map(analogRead(inPins[i]), 0, 1023, 0, 255));
    }
}



void set31KHzPWM(){
    TCCR2B = TCCR2B & B11111000 | B00000001; //Timer2 D3, D11
    TCCR1B = TCCR1B & B11111000 | B00000001; //Timer1 D9, D10
}

void set4KHzPWM(){
    TCCR2B = TCCR2B & B11111000 | B00000010;
    TCCR1B = TCCR1B & B11111000 | B00000010;
}

void set500HzPWM(){
    TCCR2B = TCCR2B & B11111000 | B00000100;
    TCCR1B = TCCR1B & B11111000 | B00000011;
}

void set120HzPWM(){
    TCCR2B = TCCR2B & B11111000 | B00000110;
    TCCR1B = TCCR1B & B11111000 | B00000100;
}

void set30HzPWM(){
    TCCR2B = TCCR2B & B11111000 | B00000111;
    TCCR1B = TCCR1B & B11111000 | B00000101;
}


