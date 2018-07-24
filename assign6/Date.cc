/*****************************************************************
NAME : SWATI BOTUWAR
Z-ID : Z1828087
CSCI/689/Section 1
TA NAME : NITHIN DEVANG
ASSIGNMENT NUMBER :6
DUE DATE : FRIDAY, 7th APRIL  2017
DESCRIPTION : This file contains member functions definition  of
              Date class. By using print() we can print date value
              to textCanvas. 
********************************************************************/

#include "date.h"

Date ::Date()
   {
     day = '\0';
     month = '\0';
     year = '\0';
   }

Date ::Date(string day1, string month1, string year1)
   {
     day = day1;
     month = month1;
     year = year1;
   }

void Date :: print(textCanvas& d ) const
   {
     d.print_string(day);
     d.print_char(' ');
     d.print_string(month);
     d.print_char(',');
     d.print_string(year);

   }
