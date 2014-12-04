/*
  Snake.pde
 
 Example file using the The Meggy Jr Simplified Library (MJSL)
  from the Meggy Jr RGB library for Arduino
   
 Blink a damned LED.
   
   
 
 Version 1.25 - 12/2/2008
 Copyright (c) 2008 Windell H. Oskay.  All right reserved.
 http://www.evilmadscientist.com/
 
 This library is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this library.  If not, see <http://www.gnu.org/licenses/>.
 	  
 */
 

 
 
 
 

/*
 * Adapted from "Blink,"  The basic Arduino example.  
 * http://www.arduino.cc/en/Tutorial/Blink

 */
 /* 
   Draw player 
   Display slate  /delay for 100
   check buttons 
   update direction if a button is pressed 
   update player coordinate based on direction 
   correct for wrapping 
*/


#include <MeggyJrSimple.h> // Required code, line 1 of 2.


int direction = 0;        //possible values are 0,90,180,270
int xapple = random (8);
int yapple = random (8);
struct Point
{
  int x;
  int y;
};

Point p1 = {3,4};
Point p2 = {4,4};
Point p3 = {5,4};
Point snakeArray[64]= {p1, p2, p3};

int marker=3;

void setup()  
{
   MeggyJrSimpleSetup(); 
   Serial.begin (9600);
}

void drawSnake()
{
  for (int i=0; i<marker; i++)
  {
   DrawPx (snakeArray[i].x, snakeArray[i].y, Red);
  } 
}

void updateSnake()
{
  for (int i=marker-1; i>0; i--)
  {
    snakeArray[i] = snakeArray[i-1];
  }
}
void loop ()

{
   Serial.print ("X is ");
  Serial.println (snakeArray[0].x);
  Serial.print ("Y is ");
  Serial.println (snakeArray[0].y);
  Serial.println ();
  
  
   
  drawSnake();
  DrawPx(snakeArray[0].x, snakeArray[0].y,Blue);
  DisplaySlate();
  delay(125);
  ClearSlate();
  updateSnake();
  
  DrawPx(xapple, yapple, Green);
  
  CheckButtonsPress();
   if (Button_Right)
    {
      direction = 90;   
    }
  
   if (Button_Left)
    {
      direction = 270;
    }

    if (Button_Down)
    {
       direction = 180;
    }
 
   if (Button_Up) 
    {
      direction = 0;
    }
    
      if (direction == 0) 
      {
      snakeArray[0].y ++;
      }
      if (direction == 90)
     { 
      snakeArray[0].x ++;
     }
      if (direction == 180) 
      
      {
     snakeArray[0].y --;
      }
      
      if (direction == 270) 
      
      {
     snakeArray[0].x --;
      }
      
      if (snakeArray[0].x > 7)
      
      {
      snakeArray[0].x=0;
      }
      
      if (snakeArray[0].y > 7)
      
      {
     snakeArray[0].y=0;
      }
      
      if (snakeArray[0].x < 0)
      
      {
      snakeArray[0].x=7;
      }
      
      if (snakeArray[0].y < 0)
      
      {
      snakeArray[0].y=7;
      }
      
    if (xapple == snakeArray[0].x) {
      if (yapple == snakeArray[0].y) {
        xapple = random (8);
        yapple = random (8);
        marker ++;
      }
    }

    
}

   
  
  





