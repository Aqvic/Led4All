/* 
 *  https://github.com/Aqvic/Led4All
*/

const byte chCount = 4;

const byte  inPins[chCount] = {1, 2, 3, 4};
const byte outPins[chCount] = {1, 2, 3, 4};

void setup() {   
    set4KHzPWM(); // D3, D9, D10, D11 - 4KHz; D5, D6 - 8KHz 

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

void set4KHzPWM(){
    //comment line below to live default 1KHz for D5 & D6
    TCCR0B = TCCR0B & B11111000 | B00000010; // 8KHz D5 & D6
    
    TCCR1B = TCCR1B & B11111000 | B00000010; // 4KHz D9 & D10
    TCCR2B = TCCR2B & B11111000 | B00000010; // 4KHz D3 & D11 
}
