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

int xplayer = 3;         //coordinate of player dot 
int yplayer = 4;
int direction = 0;        //possible values are 0,90,180,270
int xapple = random (8);
int yapple = random (8);
void setup()  
{
   MeggyJrSimpleSetup(); 
   Serial.begin (9600);
}

void loop ()

{
   Serial.print ("X is ");
  Serial.println (xplayer);
  Serial.print ("Y is ");
  Serial.println (yplayer);
  Serial.println ();
  
  DrawPx(xplayer, yplayer,Blue); 
  DisplaySlate();
  delay(100);
  ClearSlate();
  
  DrawPx(xapple, yapple, Green);
   DisplaySlate();
 
  
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
      yplayer ++;
      }
      if (direction == 90)
     { 
      xplayer ++;
     }
      if (direction == 180) 
      
      {
      yplayer --;
      }
      
      if (direction == 270) 
      
      {
      xplayer --;
      }
      
      if (xplayer > 7)
      
      {
      xplayer=0;
      }
      
      if (yplayer > 7)
      
      {
      yplayer=0;
      }
      
      if (xplayer < 0)
      
      {
      xplayer=7;
      }
      
      if (yplayer < 0)
      
      {
      yplayer=7;
      }
      
    if (xapple == xplayer) {
      if (yapple == yplayer) {
        xapple = random (8);
        yapple = random (8);
      }
    }

    
}

   
  
  





