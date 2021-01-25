#include "WZ_S.h"
#include <SoftwareSerial.h> 
#include <LiquidCrystal.h>

//HCHO 5V
//Pin D9 TX
//Pin D8 RX
SoftwareSerial wz_s_Serial(8, 9);
WZ_S wz_s(wz_s_Serial);
WZ_S::DATA hcho_data;
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup(){
 Serial.begin(9600);
 wz_s_Serial.begin(9600); 
 wz_s.passiveMode();
 // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

void loop()
{
  // if using multiple software serial, you might want listen() before sending command!
  // wz_s_Serial.listen(); 
  wz_s.requestData(); // passive mode require you to request data, active mode dont.
  if(wz_s.dataRead(hcho_data))
  {
  Serial.print("HCHO PPB:");
  Serial.println(hcho_data.HCHO_ppb);
   Serial.print("HCHO ug:");
  Serial.println(hcho_data.HCHO_ugm3);
  lcd.setCursor(0,0);
  lcd.print("HCHO PPB:");
  lcd.print(hcho_data.HCHO_ppb);
  lcd.setCursor(0,1);
   lcd.print("HCHO ug:");
  lcd.print(hcho_data.HCHO_ugm3);

  
  }
  delay(2000); //don't request data too frequent :P 
   lcd.clear();
}
