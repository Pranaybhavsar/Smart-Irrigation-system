#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
const int AirValue = 620;
const int WaterValue = 310;
int soilMoistureValue = 0;
int soilmoisturepercent=0;
int s=8;
void setup() {
 Serial.begin(9600);
 display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
 display.clearDisplay();
 pinMode(s,OUTPUT);
}
void loop() {
soilMoistureValue = analogRead(A0);
Serial.println(soilMoistureValue);
soilmoisturepercent = map(soilMoistureValue, AirValue, WaterValue, 0, 100);
if(soilmoisturepercent > 100)
{
 Serial.println("100 %");

 display.setCursor(45,0); //oled display
 display.setTextSize(1);
 display.setTextColor(WHITE);
 display.println("MOISTURE");
 display.setCursor(20,15); //oled display
 display.setTextSize(2);
 display.setTextColor(WHITE);
 display.println("100 %");
 display.display();

 display.clearDisplay();
}
else if(soilmoisturepercent <0)
{
 Serial.println("0 %");
 digitalWrite(s,HIGH);
 display.setCursor(45,0); //oled display
 display.setTextSize(1);
 display.setTextColor(WHITE);
 display.println("MOISTURE:");


 display.setCursor(20,15); //oled display
 display.setTextSize(2);
 display.setTextColor(WHITE);
 display.println("0 %");
 display.display();
 display.clearDisplay();
}
else if(soilmoisturepercent >0 && soilmoisturepercent < 50)
{
 Serial.print(soilmoisturepercent);
 Serial.println("%");
 digitalWrite(s,HIGH);
 display.setCursor(45,0); //oled display
 display.setTextSize(1);
 display.setTextColor(WHITE);
 display.println("MOISTURE:");
 display.setCursor(20,15);
 display.setTextSize(2);
 display.setTextColor(WHITE);
 display.println(soilmoisturepercent);
 display.setCursor(70,15);
 display.setTextSize(2);
 display.println(" %");
 display.display();
 display.clearDisplay();
}
else if(soilmoisturepercent >50 && soilmoisturepercent < 100)
{
 Serial.print(soilmoisturepercent);
 Serial.println("%");
 digitalWrite(s,LOW);
 display.setCursor(45,0); //oled display
 display.setTextSize(1);
 display.setTextColor(WHITE);
 display.println("MOISTURE:");
 display.setCursor(20,15);
 display.setTextSize(2);
 display.setTextColor(WHITE);
 display.println(soilmoisturepercent);
 display.setCursor(70,15);
 display.setTextSize(1);
 display.println(" %");
 display.display();
 display.clearDisplay();
}
}
