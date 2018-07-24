/*****************************************************************
NAME : SWATI BOTUWAR
Z-ID : Z1828087
CSCI/689/Section 1
TA NAME : NITHIN DEVANG
ASSIGNMENT NUMBER :6
DUE DATE : FRIDAY, 7th APRIL  2017
DESCRIPTION : This file contains member functions definition  of
              class Place. print() allow to print value to textCanvas.
********************************************************************/

#include "place.h"

Place :: Place()
   { 
     Name city ;
     Name county;
     Name state;
   }
 

Place :: Place(string city1, string county1, string  state1)
    { 
      city =  city1;
      county = county1;
      state = state1;
    }

void Place :: print( textCanvas& p) const
   { 
     city.print(p);
     p.print_string(", ");
     county.print(p);
     p.print_string(", ");
     state.print(p);
   }


   
