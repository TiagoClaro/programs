#include <Adafruit_SSD1306.h>
#include <splash.h>

#include <LiquidCrystal.h>
#define pi 3.1415926535897932384626433832795

//VSS - GND
//VDD - 5V
//V0 - trimmer
//RS - pin 2
//RW - GND
//E - pin 3
//D4 - pin 4
//D5 - pin 5
//D6 - pin 6
//D7 - pin 7
//A - 5V
//K - GND

//Up - A4
//Down - A5
//Right - A2
//Left - A3

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

int up, down, left, right;
float x, y, m, a, lux;

byte degree[] = {
  B11100,
  B10100,
  B11100,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};


void setup(){

    pinMode(A4, INPUT);
    pinMode(A5, INPUT);
    pinMode(A2, INPUT);
    pinMode(A3, INPUT);
    Serial.begin(9600);
    lcd.begin(16,2);
    logo();
}

void loop(){
    
    down = analogRead(A5);
    up = analogRead(A4);
    left = analogRead(A3);
    right = analogRead(A2);
    lcd.createChar(1, degree);

    y = up - down;
    x = right - left;

    m = y / x;

    a = atan(m);
    a = (a * 180) / pi;

    if(x>0 && y>0){
        a = a;
    }
    else if(x<0 && y<0){
        a = a + 180;
    }
    else if(x>0 && y<0){
        a = a + 360;
    }
    else if(x<0 && y>0){
        a = a + 180;
    }

    //lux = sqrt((x*x)+(y*y));

/*     lux = (lux*5)/1023;

    lux = ((2500/lux)-500)/10; */

    lcd.setCursor(0,0);
    lcd.print("Angle: ");
    lcd.print(a);
    lcd.setCursor(13,0);
    lcd.write(1);
/*     lcd.setCursor(0,1);
    lcd.print("Module: ");
    lcd.print((int)lux);
    lcd.setCursor(13,1); */
    //lcd.print("lux");
/*     lcd.setCursor(0,0);
    lcd.print("U: ");
    lcd.print(up);
    lcd.setCursor(0, 1);
    lcd.print("D: ");
    lcd.print(down);
    lcd.setCursor(8, 0);
    lcd.print("L: ");
    lcd.print(left);
    lcd.setCursor(8, 1);
    lcd.print("R: ");
    lcd.print(right); */
    delay(200);

}

void logo(){
    lcd.setCursor(0,0);
    lcd.print("T");
    lcd.setCursor(1,1);
    lcd.print("C");
    lcd.setCursor(4,2);
    lcd.print("Technology");
    delay(2000);
    lcd.clear();
}