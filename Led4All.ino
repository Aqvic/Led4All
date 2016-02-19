/* 
 *  https://github.com/Aqvic/Led4All
*/

const byte inPins[4] = {1, 2, 3, 4};
const byte outPins[4] = {1, 2, 3, 4};

void setup() {}

void loop() {
    for(int i=0; i<4; i++){
        analogWrite(outPins[i], map(analogRead(inPins[i]), 0, 1023, 0, 255));
    }
}
