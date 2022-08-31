String inByte;

void setup(){

    Serial.begin(9600);
    Serial.println("Ready");
    pinMode(LED_BUILTIN, HIGH);
}

void loop(){

    if(Serial.available() > 0){
        inByte = Serial.readStringUntil('\n');
        if(inByte == "1"){
            pinMode(LED_BUILTIN, LOW);
            Serial.write("ON");
        }
        if(inByte == "2"){
            pinMode(LED_BUILTIN, HIGH);
            Serial.write("OFF");
        }
        else{
            Serial.write("invalid Output");
        }
    }
}