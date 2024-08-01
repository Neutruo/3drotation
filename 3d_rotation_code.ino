#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <math.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  Serial.begin(115200);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();
}

float focal_length = 25;

float x1 = -10;
float y1 = -10;
float z1 = -10;

float x2 = 10;
float y2 = -10;
float z2 = -10;

float x3 = -10;
float y3 = 10;
float z3 = -10;

float x4 = 10;
float y4 = 10;
float z4 = -10;

float x5 = -10;
float y5 = -10;
float z5 = 10;

float x6 = 10;
float y6 = -10;
float z6 = 10;

float x7 = -10;
float y7 = 10;
float z7 = 10;

float x8 = 10;
float y8 = 10;
float z8 = 10;

float angle = 5;
float theta = angle*(3.141592654/180);

float x1_projected = x1;
float y1_projected = y1;

float x2_projected = x2;
float y2_projected = y2;

float x3_projected = x3;
float y3_projected = y3;

float x4_projected = x4;
float y4_projected = y4;

float x5_projected = x5;
float y5_projected = y5;

float x6_projected = x6;
float y6_projected = y6;

float x7_projected = x7;
float y7_projected = y7;

float x8_projected = x8;
float y8_projected = y8;

float x1_new = 0;
float y1_new = 0;

float x2_new = 0;
float y2_new = 0;

float x3_new = 0;
float y3_new = 0;

float x4_new = 0;
float y4_new = 0;

float x5_new = 0;
float y5_new = 0;

float x6_new = 0;
float y6_new = 0;

float x7_new = 0;
float y7_new = 0;

float x8_new = 0;
float y8_new = 0;

float cube_center_x = 0;
float cube_center_y = 0;
float cube_center_z = 0;

void loop() {
  lcd.setCursor(1,0);
  lcd.print("Rotation:Yaw");
  cube_center_x = (x1 + x2 + x3 + x4 + x5 + x6 + x7 + x8) / 8;
  cube_center_y = (y1 + y2 + y3 + y4 + y5 + y6 + y7 + y8) / 8;
  cube_center_z = (z1 + z2 + z3 + z4 + z5 + z6 + z7 + z8) / 8;

  x1 -= cube_center_x;
  y1 -= cube_center_y;
  z1 -= cube_center_z;
  x2 -= cube_center_x;
  y2 -= cube_center_y;
  z2 -= cube_center_z;
  x3 -= cube_center_x;
  y3 -= cube_center_y;
  z3 -= cube_center_z;
  x4 -= cube_center_x;
  y4 -= cube_center_y;
  z4 -= cube_center_z;
  x5 -= cube_center_x;
  y5 -= cube_center_y;
  z5 -= cube_center_z;
  x6 -= cube_center_x;
  y6 -= cube_center_y;
  z6 -= cube_center_z;
  x7 -= cube_center_x;
  y7 -= cube_center_y;
  z7 -= cube_center_z;
  x8 -= cube_center_x;
  y8 -= cube_center_y;
  z8 -= cube_center_z;

  x1_new = ((x1*(cos(theta)))-(y1*(sin(theta))));
  y1_new = ((x1*(sin(theta)))+(y1*(cos(theta))));

  x2_new = ((x2*(cos(theta)))-(y2*(sin(theta))));
  y2_new = ((x2*(sin(theta)))+(y2*(cos(theta))));

  x3_new = ((x3*(cos(theta)))-(y3*(sin(theta))));
  y3_new = ((x3*(sin(theta)))+(y3*(cos(theta))));

  x4_new = ((x4*(cos(theta)))-(y4*(sin(theta))));
  y4_new = ((x4*(sin(theta)))+(y4*(cos(theta))));

  x5_new = ((x5*(cos(theta)))-(y5*(sin(theta))));
  y5_new = ((x5*(sin(theta)))+(y5*(cos(theta))));

  x6_new = ((x6*(cos(theta)))-(y6*(sin(theta))));
  y6_new = ((x6*(sin(theta)))+(y6*(cos(theta))));

  x7_new = ((x7*(cos(theta)))-(y7*(sin(theta))));
  y7_new = ((x7*(sin(theta)))+(y7*(cos(theta))));

  x8_new = ((x8*(cos(theta)))-(y8*(sin(theta))));
  y8_new = ((x8*(sin(theta)))+(y8*(cos(theta))));

  x1 = x1_new + cube_center_x;
  y1 = y1_new + cube_center_y;
  z1 += cube_center_z;
  x2 = x2_new + cube_center_x;
  y2 = y2_new + cube_center_y;
  z2 += cube_center_z;
  x3 = x3_new + cube_center_x;
  y3 = y3_new + cube_center_y;
  z3 += cube_center_z;
  x4 = x4_new + cube_center_x;
  y4 = y4_new + cube_center_y;
  z4 += cube_center_z;
  x5 = x5_new + cube_center_x;
  y5 = y5_new + cube_center_y;
  z5 += cube_center_z;
  x6 = x6_new + cube_center_x;
  y6 = y6_new + cube_center_y;
  z6 += cube_center_z;
  x7 = x7_new + cube_center_x;
  y7 = y7_new + cube_center_y;
  z7 += cube_center_z;
  x8 = x8_new + cube_center_x;
  y8 = y8_new + cube_center_y;
  z8 += cube_center_z;

  x1_projected = ((x1*focal_length)/(z1+focal_length))+64;
  y1_projected = ((y1*focal_length)/(z1+focal_length))+32;

  x2_projected = ((x2*focal_length)/(z2+focal_length))+64;
  y2_projected = ((y2*focal_length)/(z2+focal_length))+32;

  x3_projected = ((x3*focal_length)/(z3+focal_length))+64;
  y3_projected = ((y3*focal_length)/(z3+focal_length))+32;

  x4_projected = ((x4*focal_length)/(z4+focal_length))+64;
  y4_projected = ((y4*focal_length)/(z4+focal_length))+32;

  x5_projected = ((x5*focal_length)/(z5+focal_length))+64;
  y5_projected = ((y5*focal_length)/(z5+focal_length))+32;

  x6_projected = ((x6*focal_length)/(z6+focal_length))+64;
  y6_projected = ((y6*focal_length)/(z6+focal_length))+32;

  x7_projected = ((x7*focal_length)/(z7+focal_length))+64;
  y7_projected = ((y7*focal_length)/(z7+focal_length))+32;

  x8_projected = ((x8*focal_length)/(z8+focal_length))+64;
  y8_projected = ((y8*focal_length)/(z8+focal_length))+32;

  display.drawPixel(x1_projected, y1_projected, WHITE);
  display.drawPixel(x2_projected, y2_projected, WHITE);
  display.drawPixel(x3_projected, y3_projected, WHITE);
  display.drawPixel(x4_projected, y4_projected, WHITE);
  display.drawPixel(x5_projected, y5_projected, WHITE);
  display.drawPixel(x6_projected, y6_projected, WHITE);
  display.drawPixel(x7_projected, y7_projected, WHITE);
  display.drawPixel(x8_projected, y8_projected, WHITE);

  display.drawLine(x1_projected, y1_projected, x2_projected, y2_projected, WHITE);
  display.drawLine(x1_projected, y1_projected, x3_projected, y3_projected, WHITE);
  display.drawLine(x4_projected, y4_projected, x2_projected, y2_projected, WHITE);
  display.drawLine(x3_projected, y3_projected, x4_projected, y4_projected, WHITE);
  display.drawLine(x5_projected, y5_projected, x6_projected, y6_projected, WHITE);
  display.drawLine(x5_projected, y5_projected, x7_projected, y7_projected, WHITE);
  display.drawLine(x8_projected, y8_projected, x6_projected, y6_projected, WHITE);
  display.drawLine(x7_projected, y7_projected, x8_projected, y8_projected, WHITE);
  display.drawLine(x1_projected, y1_projected, x5_projected, y5_projected, WHITE);
  display.drawLine(x2_projected, y2_projected, x6_projected, y6_projected, WHITE);
  display.drawLine(x3_projected, y3_projected, x7_projected, y7_projected, WHITE);
  display.drawLine(x4_projected, y4_projected, x8_projected, y8_projected, WHITE);


  display.display();
  delay((100/6));

  display.drawPixel(x1_projected, y1_projected, BLACK);
  display.drawPixel(x2_projected, y2_projected, BLACK);
  display.drawPixel(x3_projected, y3_projected, BLACK);
  display.drawPixel(x4_projected, y4_projected, BLACK);
  display.drawPixel(x5_projected, y5_projected, BLACK);
  display.drawPixel(x6_projected, y6_projected, BLACK);
  display.drawPixel(x7_projected, y7_projected, BLACK);
  display.drawPixel(x8_projected, y8_projected, BLACK);

  display.drawLine(x1_projected, y1_projected, x2_projected, y2_projected, BLACK);
  display.drawLine(x1_projected, y1_projected, x3_projected, y3_projected, BLACK);
  display.drawLine(x4_projected, y4_projected, x2_projected, y2_projected, BLACK);
  display.drawLine(x3_projected, y3_projected, x4_projected, y4_projected, BLACK);
  display.drawLine(x5_projected, y5_projected, x6_projected, y6_projected, BLACK);
  display.drawLine(x5_projected, y5_projected, x7_projected, y7_projected, BLACK);
  display.drawLine(x8_projected, y8_projected, x6_projected, y6_projected, BLACK);
  display.drawLine(x7_projected, y7_projected, x8_projected, y8_projected, BLACK);
  display.drawLine(x1_projected, y1_projected, x5_projected, y5_projected, BLACK);
  display.drawLine(x2_projected, y2_projected, x6_projected, y6_projected, BLACK);
  display.drawLine(x3_projected, y3_projected, x7_projected, y7_projected, BLACK);
  display.drawLine(x4_projected, y4_projected, x8_projected, y8_projected, BLACK);

  display.display();
  delay((100/6));  
}