//LCD1602
//You should now see your LCD1602 display the flowing characters "SUNFOUNDER" and "hello, world"
//Email:support@sunfounder.com
//Website:www.sunfounder.com
//2015.5.7 
#include <LiquidCrystal.h>// include the library code
/**********************************************************/
char array1[]="Hello There!    ";  //the string to print on the LCD top row MAX 16
char array2[]="General Kenobi! ";  //the string to print on the LCD
int tim = 250;  //the value of delay time
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(4, 6, 10, 11, 12, 13);
/*********************************************************/
void setup()
{
  lcd.begin(16, 2);  // set up the LCD's number of columns and rows: 
  
  lcd.clear();

  for(int i=0;i<16;i++){
    lcd.print(array1[i]);
    lcd.setCursor(i+1,0);
  }
  lcd.setCursor(0,1);
  for(int i=0;i<16;i++){
    lcd.print(array2[i]);
    lcd.setCursor(i+1,1);
  }
  
}
/*********************************************************/
void loop() 
{/*
    lcd.setCursor(15,0);  // set the cursor to column 15, line 0
    for ( int positionCounter1 = 0; positionCounter1 < 26; positionCounter1++)
    {
      lcd.scrollDisplayLeft();  //Scrolls the contents of the display one space to the left.
      lcd.print(array1[positionCounter1]);  // Print a message to the LCD.
      delay(tim);  //wait for 250 microseconds
    }
    lcd.clear();  //Clears the LCD screen and positions the cursor in the upper-left corner.
    lcd.setCursor(15,1);  // set the cursor to column 15, line 1
    for (int positionCounter2 = 0; positionCounter2 < 26; positionCounter2++)
    {
      lcd.scrollDisplayLeft();  //Scrolls the contents of the display one space to the left.
      lcd.print(array2[positionCounter2]);  // Print a message to the LCD.
      delay(tim);  //wait for 250 microseconds
    }
    lcd.clear();  //Clears the LCD screen and positions the cursor in the upper-left corner.*/
}
/************************************************************/
