#include <Servo.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16,2);

Servo servo;
int angle = 90;


const byte ROWS = 2;
const byte COLS = 2;

char keys[ROWS][COLS] ={
  {'1','2'},
  {'3','4'}
};
byte rowPins[ROWS] = {5, 4};
byte colPins[COLS] = {3, 2};
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void writeAngle(){
  lcd.clear();
  lcd.setCursor(0, 0); 
  lcd.print("Angle:" + String(angle));
}

void setup() {
  lcd.init();
  lcd.backlight();

  servo.attach(8);
  servo.write(angle);

  writeAngle();
}

void loop() 
{ 
    char key = keypad.getKey();

  if(key == '3'){
    for(angle; angle >= 45; angle--)  
    {                                  
      servo.write(angle);                
      writeAngle();
    } 
  } else if(key == '1'){
    if(angle >= 135){
      final
    }
    for(angle; angle <= 135; angle++){
      servo.write(angle);
      writeAngle();
    }
  }
}