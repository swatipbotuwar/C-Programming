/*****************************************************************
NAME : SWATI BOTUWAR
Z-ID : Z1828087
CSCI/689/Section 1
TA NAME : NITHIN DEVANG
ASSIGNMENT NUMBER :6
DUE DATE : FRIDAY, 7th APRIL  2017
DESCRIPTION : This header file contains, Place class definition
              along with header gaurd.
********************************************************************/

#ifndef PLACE_H
#define PLACE_H

#include "name.h"
#include "textCanvas.h"

class Place
    {
      Name city;
      Name county;
      Name state;

      public:

      Place();
      Place(string city1, string  county1, string state);
      void print(textCanvas& ) const;
    };

#endif /* end of PLACE_H header */


