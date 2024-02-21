#include <Keypad.h>
#include <Stepper.h>


const int steps = 2048;
int revolutionVal = 500;


Stepper stepper(steps, 8, 9, 10, 11);


const byte ROWS = 2;
const byte COLS = 2;

char keys[ROWS][COLS] ={
  {'1','2'},
  {'3','4'}
};
byte rowPins[ROWS] = {5, 4};
byte colPins[COLS] = {3, 2};
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  stepper.setSpeed(5);

}

void loop() {
  // put your main code here, to run repeatedly:
  char key = keypad.getKey();

  if(key == '1'){
    Serial.print("go \n");
    stepper.step(steps);
    //delay(500);
    
  } else if(key == '2'){
    Serial.print("back \n");
    int newSped = steps * (-1);
    stepper.step(newSped);
    stepper.version();
    //delay(500);
  }
  Serial.print("end of if \n");
}
