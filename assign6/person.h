/*****************************************************************
NAME : SWATI BOTUWAR
Z-ID : Z1828087
CSCI/689/Section 1
TA NAME : NITHIN DEVANG
ASSIGNMENT NUMBER :6
DUE DATE : FRIDAY, 7th APRIL  2017
DESCRIPTION : This header file contains, Person class definition
              along with header gaurd.
********************************************************************/

#ifndef PERSON_H
#define PERSON_H
 
#include <iostream>
#include <cstdlib>
#include <string>
#include "date.h"
#include "name.h"
#include "place.h"
#include "textCanvas.h"
using std :: cout;
using std :: endl;
using std :: string;


class Person
   {
     Name lastName;
     Name firstName;
     Date birthDate;
     Place birthPlace;
     Date deathDate;
     Place deathPlace;
     int fatherIndex;
     int motherIndex;
     int childIndex;

     public:
      Person(); //default constructor
   
      /* parameterized constructor */
      Person(Name lastName, Name firstName, Date birthDate, Place birthPlace, Date deathDate, Place deathPlace, int fatherIndex, int motherIndex, int childIndex);

      /* getter function for father, mother and child */

      int get_father() const;
      int get_mother() const;
      int get_child() const;

      void print(textCanvas&) const;  
    };
#endif /* end of person header */
