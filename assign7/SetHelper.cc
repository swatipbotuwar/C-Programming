/*****************************************************************
NAME : SWATI BOTUWAR
Z-ID : Z1828087
CSCI/689/Section 1
TA NAME : NITHIN DEVANG
ASSIGNMENT NUMBER :7
DUE DATE : TUESDAY 18th APRIL  2017
DESCRIPTION: This is a source file for Class SetHelper, which 
             contains class functions defination.
******************************************************************/

#include "SetHelper.h"

//default constructor 

SetHelper :: SetHelper()
   {
     sequence = 0;
     value = "";
   }

//Parameterized constructor defination 

SetHelper :: SetHelper(int sequence1, string value1)
   {
     sequence = sequence1;
     value = value1;
   }


//Subscript []  operator overloading 

string SetHelper :: operator[](int index) const
   {
     return value;
   }

// less than '<' operator overloading

bool SetHelper ::operator < (const SetHelper& a) const
  {
    return sequence < a.sequence ;
  }

//output stream '<<' operator overloading 

ostream& operator<< (ostream& ostr,const SetHelper& c)
  {
    if(c[c.sequence] == "\\n")
    {
        cout << endl;
    }
    else
    {
        ostr << c[c.sequence] << " ";
    }
    return ostr; 
 }
