/*****************************************************************
NAME : SWATI BOTUWAR
Z-ID : Z1828087
CSCI/689/Section 1
TA NAME : NITHIN DEVANG
ASSIGNMENT NUMBER :5
DUE DATE : FRIDAY, 10th MARCH  2017
DESCRIPTION : This is a header file conatin Storm class with its data
              member, constructor  and member function. 
********************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <iomanip>
#include <iterator>
using std :: cout;
using std :: cin;
using std :: endl;
using std :: vector;
using std :: ifstream;
using std :: istringstream;
using std :: setw;
using std :: cerr;
using std :: string;
using std :: left;
using std :: right;
using std :: iterator;
const int lineNumber = 20;

#ifndef READSTORMHEADER_H
#define READSTORMHEADER_H

class Storm
    {
        char  basinName;
        string stormName;
        int stormSequenceNumber;
        int stormYear;
        int maxWindSpeed;
        int minAirPressure;
        char stormType;

       public :

       Storm(); //Default Constructor
       Storm(char  basinName, string stormName, int stormSequenceNumber, int stormYear, int maxWindSpeed, int minAirPressure, char  stormType);
       string  getStormType();
       int getStormSequenceNumber() const;
       int getStormYear() const;
       int getMaxWindSpeed();
       int  getMinAirPressure();
       void print();
    };
                         
#endif

/* Default Constructor Defination and its default values */
 Storm :: Storm()
   {
      basinName = 'N';
      stormName = "None";
      stormSequenceNumber = 0;
      stormYear = 0;
      maxWindSpeed = 0;
      minAirPressure = 0;
      stormType = 'N';
   }

/* Defining Constructor with Argument */

 Storm :: Storm(char basin, string name, int sequenceNumber, int year, int windSpeed, int airPressure, char type)
   {
     basinName = basin;
     stormName = name;
     stormSequenceNumber = sequenceNumber;
     stormYear = year;
     maxWindSpeed = windSpeed ;
     minAirPressure = airPressure;
     stormType = type;
   }


/* Definig Accessor method */

string  Storm :: getStormType() 
   {
     string tempStormType;
      
     if(stormType == 'H')
      tempStormType = "Hurrican";
      else
      if(stormType == 'S')
       tempStormType = "Storm";
      else
      if(stormType == 'D')
       tempStormType = "Depression";
      else
       tempStormType = " ";
       return tempStormType;
   }


int Storm :: getStormSequenceNumber() const
   {
      return stormSequenceNumber;
   }

int Storm :: getStormYear() const
   {
     return stormYear;
   }

int Storm :: getMaxWindSpeed() 
  {
    return maxWindSpeed;
  }

int  Storm :: getMinAirPressure()
  {
    if(minAirPressure != 10000)
     return minAirPressure;
   else 
     return 0;
  }


void  Storm :: print()
   {
     string tempBasin;
     if(basinName == 'A')
      tempBasin = "Atlantic";
     else
     if(basinName == 'E')
      tempBasin  = "Eastern Pacific";
     else
     if(basinName == 'C')
       tempBasin  = "Central Pacific";
    
  // string tempPressure;
 // if (getMinAirPressure() == 10000) 
   // tempPressure =  " ";
// else
 // tempPressure =  getMinAirPressure();
     cout <<left << setw(20)<< tempBasin <<setw(15)<< getStormType() << setw(20) << stormName ;
     cout <<right << getStormSequenceNumber() << "/" <<left << setw(15) << stormYear << setw(10) <<getMaxWindSpeed();
    cout <<left << setw(10) << getMinAirPressure()  << endl;
   //  cout <<left << setw(10) << tempPressure<<endl;
   }

