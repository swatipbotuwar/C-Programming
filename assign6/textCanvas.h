/*****************************************************************
NAME : SWATI BOTUWAR
Z-ID : Z1828087
CSCI/689/Section 1
TA NAME : NITHIN DEVANG
ASSIGNMENT NUMBER :6
DUE DATE : FRIDAY, 7th APRIL  2017
DESCRIPTION : This header file contains, textCanvas class definition 
              along with header gaurd.
********************************************************************/

#ifndef TEXTCANVAS_H
#define TEXTCANVAS_H

#include <iostream>
#include <string>
using std :: cout ;
using std :: endl;
using std :: string;


const int CHEIGHT = 24;
const int CWIDTH = 80;
const int  TC_OK = 0;
const int  TC_OUT_OF_BOUNDS = -1;
const int TC_CURSOR_OUT_OF_BOX = -2;

class textCanvas
   {
     char canvasArray[CHEIGHT][CWIDTH];
     int currentRow;
     int currentColumn;
     int top;
     int bottom;
     int right;
     int left;

     public:

     textCanvas(); // default constructor 
     void clear();
     void print() const;   // function to print 2D array to output screen

     int set_box(int currentColumn, int currentRow, int width, int height);  // function to set bounding box 

     int print_horizontal_line(int currentColumn, int currentRow, int width); // Function to draw horizontal line

     int print_vertical_line(int currentColumn, int currentRow, int height);  // function to draw vertical line 

     int print_char(const char );   //function to write character to array

     int print_string(string );   // fucntion to write string to an array 
   };

#endif /* end of TEXTCANVAS_H header */

    
 
     
