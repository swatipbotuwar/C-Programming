/*****************************************************************
NAME : SWATI BOTUWAR
Z-ID : Z1828087
CSCI/689/Section 1
TA NAME : NITHIN DEVANG
ASSIGNMENT NUMBER :7
DUE DATE : TUESDAY 18th APRIL  2017
DESCRIPTION: This is a Header file for class SetHelper.
             It conatins class functions declarion and its data
             members details.
******************************************************************/


#ifndef SETHELPER_H
#define SETHELPER_H

#include <iostream>
#include <string>
#include <cstdlib>
using std :: cout;
using std :: string;
using std :: endl;
using std :: ostream;

class SetHelper
   {
     int sequence;
     string value;
     public :
     SetHelper();
     SetHelper(int sequence, string value);
     string operator[] (int index) const;
     bool operator <(const SetHelper&) const;
     friend ostream& operator<<(ostream& ostr, const SetHelper& c);
    };

#endif /* end of SETHELPER_H */ 
