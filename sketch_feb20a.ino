#include <LiquidCrystal.h>
#include <math.h>
#define MQ135 A0
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
float R0 = 8.5;     
float RL = 10.0;    

void setup() {
  Serial.begin(9600);
  Serial.println("MQ135 Gas Sensor Monitoring");
  delay(2000);
}
void loop() {

  char out[16];      
  char floatStr[16];   

  int sensorValue = analogRead(MQ135);
  float voltage = sensorValue * (5.0 / 1023.0);
  float Rs = ((5.0 - voltage) / voltage) * RL;
  float ratio = Rs / R0;

  float CO2 = 116.602 * pow(ratio, -2.769);
  float NH3 = 102.2 * pow(ratio, -2.473);
  float Alcohol = 77.255 * pow(ratio, -2.391);

  Serial.print("NH3: ");
  Serial.println(NH3);

  Serial.print("CO2: ");
  Serial.println(CO2);

  Serial.print("Alcohol: ");
  Serial.println(Alcohol);

  lcd.setCursor(0, 0);
  dtostrf(CO2, 6, 2, floatStr);
  snprintf(out, 16, "CO2:%s ppm", floatStr);
  lcd.print(out);

  delay(3000);
  lcd.clear();

  lcd.setCursor(0, 0);
  dtostrf(NH3, 6, 2, floatStr);
  snprintf(out, 16, "NH3:%s ppm", floatStr);
  lcd.print(out);

  delay(3000);
  lcd.clear();

  lcd.setCursor(0, 0);
  dtostrf(Alcohol, 6, 2, floatStr);
  snprintf(out, 16, "ALC:%s ppm", floatStr);
  lcd.print(out);

  delay(3000);
  lcd.clear();
}
