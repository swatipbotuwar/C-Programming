/*****************************************************************
NAME : SWATI BOTUWAR
Z-ID : Z1828087
CSCI/689/Section 1
TA NAME : NITHIN DEVANG
ASSIGNMENT NUMBER :6
DUE DATE : FRIDAY, 7th APRIL  2017
DESCRIPTION : This header file contains, Name class definition
              along with header gaurd.
********************************************************************/

#ifndef NAME_H
#define NAME_H

#include <iostream>
#include <cstdlib>
#include <string>
#include "textCanvas.h"
using std :: cout;
using std :: endl;
using std :: string;


class Name
    {
      string name;
      public :

      Name();
      Name( string name1);
      void print(textCanvas& ) const ;
    };

#endif /* end of NAME_H header  */     
