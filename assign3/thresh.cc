/*****************************************************************
NAME : SWATI BOTUWAR
Z-ID : Z1828087
CSCI/689/Section 1
TA NAME : NITHIN DEVANG
ASSIGNMENT NUMBER : 3
DUE DATE : FRIDAY, 17th FEBRUARY 2017
DESCRIPTION : This program check for number of values in a file 
              greater than threshhold value and report the result.
********************************************************************/

/*
   This function check for number of values in a file greater
   than given threshhold value and report the result.
*/

#include "threshhold.h"

int main()
{
    int threshHoldValue;
    string fileName;
    ifstream mydata;
    int randomValue , count = 0, fileCount = 0;
    cout << "Enter the name of file to be check for threshhold value : ";
    cin >> fileName;
    cout << "Enter Threshhold value : ";
    cin >> threshHoldValue ;

    /* condition check whether threshhold value is positive or not */

    while(threshHoldValue < 0)
      {
         cout << "Threshhold Value should be positive, Please enter new positive value : " << endl;
         cin >> threshHoldValue ;
      }
 
    mydata.open(fileName.c_str());

    /* check whether file is open or not */

    if (! mydata.is_open())
       {
          cerr << "Unable to open a file or file " <<fileName << " does not exist." <<  endl;
          exit(1);
       }
    else 
       { 
           mydata >> randomValue ;
           while (! mydata.eof())
              { 
               /* check whether file value is greater than threshhold value */
 
                  if(randomValue > threshHoldValue)
                    {
                       count += 1;
                    }
                fileCount += 1;
                mydata >> randomValue;
              }  
           cout << count << " of " << fileCount  << " values in " << fileName << " are greater than " << threshHoldValue <<endl;
           mydata.close ();
       }
return 0;
}
