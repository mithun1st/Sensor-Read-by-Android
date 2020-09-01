#include<LiquidCrystal.h>

LiquidCrystal lcd(53, 51, 49, 47, 45, 43);

const int led = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(A0, INPUT);
  lcd.begin(16, 2);
  Serial3.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial3.print("pot: ");
  Serial3.println(analogRead(A0));
  lcd.clear();
  lcd.print(analogRead(A0));
  delay(1000);

  String s = "";


  while (Serial3.available()) {
    s += (char)Serial3.read();
    delay(50);
  }




  if (s == "on") {
    digitalWrite(led, 1);
  }
  if (s == "off") {
    digitalWrite(led, 0);
  }

}
