/*****************************************************************
NAME : SWATI BOTUWAR
Z-ID : Z1828087
CSCI/689/Section 1
TA NAME : NITHIN DEVANG
ASSIGNMENT NUMBER :6
DUE DATE : FRIDAY, 7th APRIL  2017
DESCRIPTION : This file contains member functions definition  of
              Name class. print() allow to print string in data member
              to textCanvas.
********************************************************************/


#include "name.h"

Name :: Name()
    {
       name = "";
    }

Name :: Name(string name1)
    {
       name = name1;
    }

void Name :: print(textCanvas& n)const
    {
       n.print_string(name);
    }
