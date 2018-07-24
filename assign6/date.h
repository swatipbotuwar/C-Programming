/*****************************************************************
NAME : SWATI BOTUWAR
Z-ID : Z1828087
CSCI/689/Section 1
TA NAME : NITHIN DEVANG
ASSIGNMENT NUMBER :6
DUE DATE : FRIDAY, 7th APRIL  2017
DESCRIPTION : This header file contains, Date class definition
              along with header gaurd.
********************************************************************/



#ifndef DATE_H
#define DATE_H


#include <iostream>
#include <cstdlib>

#include <string>
#include "textCanvas.h"

using std :: cout;
using std :: endl;
using std :: string;


class Date
    {
       string day;
       string month;
       string year;
       public:
       Date();
       Date(string day1, string month1, string year1);
       void print(textCanvas&) const;
    };

#endif /* end of Date header */ 

