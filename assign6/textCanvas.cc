/*****************************************************************
NAME : SWATI BOTUWAR
Z-ID : Z1828087
CSCI/689/Section 1
TA NAME : NITHIN DEVANG
ASSIGNMENT NUMBER :6
DUE DATE : FRIDAY, 7th APRIL  2017
DESCRIPTION : This file contains member functions definition  of
              class textCanvas for flexibly formating  output on
              the screen.
********************************************************************/

#include "textCanvas.h"

/* default constructor */

textCanvas :: textCanvas()
   { 
     for (int i = 0; i < CHEIGHT; ++i) 
        {
           for (int j = 0; j < CWIDTH; ++j)
            {
               canvasArray[i][j] = ' ';
            }
        }
     currentRow = 0;
     currentColumn = 0;
     top = 0;
     bottom = CHEIGHT;
     right = CWIDTH;
     left = 0;
   }

/* It set 2D array in canvas  to spaces and set values for other data member */ 

void textCanvas :: clear()
   {
     for (int i = 0; i < CHEIGHT; ++i) 
     {
        for (int j = 0; j < CWIDTH; ++j)
        {
            canvasArray[i][j] = ' ';
        }
     } 
     
     currentRow = 0;
     currentColumn = 0;
     top = 0;
     bottom = CHEIGHT;
     right = CWIDTH;
     left = 0;
   }

/* funtion to print 2D array to ouput screen */

void textCanvas ::  print() const
   {
     for (int i = 0 ; i < CHEIGHT ; i++)
       {
         for( int j = 0; j < CWIDTH ; j++)
           {
             cout << canvasArray[i][j];
           }
         cout << endl;
       }
   }


/* set bounding box for printing character into array */

int textCanvas :: set_box(int currentColumn1, int currentRow1, int width, int height)
    {

       right = width + currentColumn1;
       bottom = height + currentRow1;
       currentColumn = currentColumn1;
       currentRow= currentRow1;

      if( right > CWIDTH  || bottom > CHEIGHT  || currentRow < 0 || currentColumn < 0 )
        return TC_OUT_OF_BOUNDS;
      else 
        {
          left = currentColumn1;
          top = currentRow1;
          return TC_OK;
        }
     }

/* This function print horizontal line from current column position to right */

int textCanvas :: print_horizontal_line( int currentColumn, int currentRow, int length)
    {
        int new_width = currentColumn + length;
       if(currentRow > bottom || currentColumn > right || currentRow < 0 || currentColumn < 0)
        {
           return TC_OUT_OF_BOUNDS;
        }
       else
        {
           for(int i = currentColumn; i <= new_width ;  i++)
             {
                canvasArray[currentRow][i] = '-';
             }
           return TC_OK;
        }
    }


/* This function print vertical line  from current Row position to bottom */

int textCanvas :: print_vertical_line( int currentColumn, int currentRow, int height)
    {
       int new_height = currentRow +  height;
        if(currentRow > bottom || currentColumn > right || currentRow < 0 || currentColumn < 0)
        {
           return TC_OUT_OF_BOUNDS;
        }
       else
       
         for(int i = currentRow ; i <= new_height ; i++)
           
            canvasArray[i][currentColumn] = '|';
            
            return TC_OK;  
       
    }


/* check for char value in switch case and perform the corresponding action */

int textCanvas :: print_char(const char c)
    {
      int returnValue =0;
     
      switch(c)
        {
          case '\n' : currentRow += 1;
                      currentColumn =  left;
                      break;

          case '\r' : currentColumn = left;
                      break;
  
          default :if(currentRow > bottom-1 || currentColumn > right-1 || currentRow < 0 || currentColumn < 0)
                     
                         returnValue =  TC_CURSOR_OUT_OF_BOX;
                   else
                    { 
                       canvasArray[currentRow][currentColumn] = c;
                       currentColumn = currentColumn + 1;
                       returnValue =  TC_OK;
                    }
                             
         }
  return returnValue;
    }        
      

/* this function read string value as input to write into array */

int textCanvas :: print_string(string val)
     {
        int returnValue;
        for(unsigned int i = 0; i < val.length() ; i++)
          {
           returnValue =  print_char(val[i]);
          }
        return returnValue;
     }

                
        
