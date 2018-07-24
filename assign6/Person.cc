/*****************************************************************
NAME : SWATI BOTUWAR
Z-ID : Z1828087
CSCI/689/Section 1
TA NAME : NITHIN DEVANG
ASSIGNMENT NUMBER :6
DUE DATE : FRIDAY, 7th APRIL  2017
DESCRIPTION : This file contains member functions definition  of
              Person class. print() allow to print all the data member 
              values to textCanvas.
********************************************************************/

#include "person.h"

/*Default constructor */

Person :: Person()
   {
      Name lastName;
      Name firstName;
      Date birthDate;
      Place birthPlace;
      Date deathDate;
      Place deathPlace;
      fatherIndex = -1;
      motherIndex =-1;
      childIndex = -1;
   }

/* Pameterized Constructor */

Person :: Person(Name last, Name first, Date birthDay, Place birthPlace1, Date deathDay, Place deathPlace1, int fatherLink, int motherLink, int childLink)
    { 
      lastName = last;
      firstName = first;
      birthDate = birthDay;
      birthPlace = birthPlace1;
      deathDate = deathDay;
      deathPlace = deathPlace1;
      fatherIndex = fatherLink;
      motherIndex = motherLink;
      childIndex = childLink;
    }

/* getter function for father, mother and child */

int Person ::  get_father() const
    {
       return fatherIndex ;
    }

int Person ::  get_mother() const
    {
      return motherIndex ;
    }

int Person ::  get_child() const
   {
     return childIndex;
   }



/** 
    print function for writing data to 2D array by using other class print 
    function and print_string() and print_char() function of textCanvas
*/


void Person :: print(textCanvas& p) const
   {
       lastName.print(p);
       p.print_string(", ");
       firstName.print(p) ;
       p.print_char('\n');
       p.print_string("b: ");
       birthDate.print(p);
       p.print_char('\n');
       p.print_string("   ");
       birthPlace.print(p);
       p.print_char('\n');
       p.print_string("d: ");
       deathDate.print(p);
       p.print_char('\n');
       p.print_string("   ");
       deathPlace.print(p); 
       p.print_char('\n');
      
   }
