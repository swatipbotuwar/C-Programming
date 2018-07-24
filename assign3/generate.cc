/**************************************************************
NAME : SWATI BOTUWAR
Z-ID : Z1828087
CSCI/689/Section 1
TA NAME : NITHIN DEVANG
ASSIGNMENT NUMBER : 3
DUE DATE : FRIDAY, 17th FEBRUARY 2017
DESCRIPTION : This program generate file of random numbers.
************************************************************/

/**
    This function generate file of random numbers
    using rand() function.
*/

#include "threshhold.h"

int main()
{
    int seedValue, maxValue , numberOfValue;
    string  oFileName ;
    float randomValue ;
    ofstream mydata;
    cout << "Enter the random number seed value : " ;
    cin >> seedValue;
    cout << "Enter the Max value of random number : ";
    cin >> maxValue ;
    cout << "Enter the number of values to be generated : ";
    cin >> numberOfValue;
    
    srand(seedValue);  
   
    /* condition check for positive integer value */
     if (seedValue < 0 || maxValue < 0 || numberOfValue < 0)
        {
          cout << "Please enter positive values for Seed Value, Max Value and Number Of Value" << endl;
          exit(1);
        }
    
    cout << "Enter the name of output file to store values : ";
    cin >> oFileName ;
  
    mydata.open(oFileName.c_str());
    
    /*  check whether file is open or not */
   
    if(!mydata.is_open())
      {
         cerr << "Unable to open file " << oFileName;
         return -1;
      } 
    else 
      { 
         for (int i = 0; i < numberOfValue; i++)
             { 
                randomValue = float(rand ()% maxValue );
                mydata << randomValue << endl ;
             }
 
         mydata.close();
      }

   return 0;
}

