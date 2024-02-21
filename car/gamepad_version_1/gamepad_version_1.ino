#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16,2);

const int xPin = A0;
const int yPin = A1;
const int buttonPin = 2;

int xPosition = 0;
int yPosition = 0;
int buttonState = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);

  pinMode(buttonPin, INPUT_PULLUP);

  lcd.init();
  lcd.backlight();
}

void loop() {
  // Считываем показания с джойстика
  xPosition = analogRead(xPin);
  yPosition = analogRead(yPin);
  buttonState = digitalRead(buttonPin);
  lcd.setCursor(0, 0);
  lcd.print("X: " + String(xPosition));
  lcd.setCursor(1, 1);
  lcd.print("Y: " + String(yPosition));

  delay(100); // добавляем задержку между считыванием данных
  lcd.clear();
}

