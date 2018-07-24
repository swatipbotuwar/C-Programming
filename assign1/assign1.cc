/******************************************************************
NAME : SWATI BOTUWAR
Z-ID : Z1828087
CSCI/689/Section 1
TA NAME : NITHIN DEVANG
ASSIGNMENT NUMBER : 1
DUE DATE : FRIDAY , 27 JANUARY 2017
DESCRIPTION : Program is for calculating the WindChill 
              value for given range of Temperature and Wind Speed.
*******************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>
using std :: cout;
using std :: cin;
using std :: showpoint;
using std :: fixed;
using std :: setprecision;
using std :: setw;
using std :: endl;

/*Function to calculate Wind Chill value */
float  WindChillcalculator( float  Tempstartvalue,float Wspeedstartvalue)
 {
   float WindChill;
   if(Tempstartvalue < 50.0 && Wspeedstartvalue > 3.0)
   
	WindChill= 35.74 + 0.6215 * Tempstartvalue - 35.75 * powf(Wspeedstartvalue,0.16) + 0.4275 * Tempstartvalue * powf(Wspeedstartvalue,0.16);
   else
        WindChill = Tempstartvalue;   
      
   return WindChill;
 }

void PrintTable(float Hightemp, float  Lowtemp,float  Whighspeed,float Wlowspeed,float TempDecrement,float WspeedIncrement)
{
  float  Tempstartvalue = 0.0, Wspeedstartvalue = 0.0;
  float WindChill;
  cout << "Wind Chill Table " << endl;
  cout << setw(9)<< "Air temperature"<< endl ;
  cout << setw(9) << "(deg. F)  " ;

    for (Tempstartvalue= Hightemp ; Tempstartvalue >=Lowtemp;) 
     {
        cout << fixed << setprecision(3) <<showpoint << setw(9) << Tempstartvalue ;
        Tempstartvalue= Tempstartvalue - TempDecrement;
     } 
  cout << endl <<  "----------------------------------------------------------------------------------" << endl;
  cout << setw(9) << "Wind Speed" << endl;
  cout << setw(9) << "(mph)" << endl;
 
/************************************************************************************************************************************
For loop will call Windchillcalculator function which will calculate WindChill  value for different temperature and Wind speed value 
**************************************************************************************************************************************/
   
  for ( Wspeedstartvalue=Wlowspeed ;  Wspeedstartvalue<= Whighspeed;)
     {
          cout << setw(9) << Wspeedstartvalue << "|";
       for (Tempstartvalue = Hightemp ; Tempstartvalue >= Lowtemp;)
         {
	
             WindChill =WindChillcalculator(Tempstartvalue,Wspeedstartvalue); /*Calling function to calculate Wind Chill value */
	     cout <<fixed << setprecision(3) << showpoint << setw(9) << WindChill ;
	     Tempstartvalue= Tempstartvalue - TempDecrement ;
         }  
       Wspeedstartvalue= Wspeedstartvalue + WspeedIncrement;
       cout << endl;
     }
}


int main()
{

  float  Hightemp=0.0 , Lowtemp=0.0 , Whighspeed=0.0 , Wlowspeed=0.0 , TempDecrement = 0.0, WspeedIncrement=0.0 ;
  cout  << "This program print out a table for selected range of wind chill factors " << endl;
  cout << endl;
  cout << "Enter Temperature high range value (degree F) ? ";
  cin >> Hightemp;
  cout << "Enter Temperature Low range value (degree F) ?" ;
  cin >> Lowtemp;
  cout << "Temperature decrement by (degree F) ?";
  cin >> TempDecrement;

  /* Constraint Check for Temperature range values */
    if(Hightemp < Lowtemp)
      {  	
	cout << "Temperature range should be High to Low"  << endl ;
	return 0 ;
      }  
    else if (TempDecrement <= 0)
      {
	cout << "Temperature decremental value should be positive or Invalid value entered" << endl;
	return 0;
      }  

  cout << "Enter wind speed low value (mph) ?" ;
  cin >> Wlowspeed;
  cout << "Enter wind speed high value (mph) ?" ;
  cin >> Whighspeed;
  cout << "Wind speed increment by (mph) ?" ;
  cin >> WspeedIncrement ;

  /* Constraint Check for Wind speed range value */
    if(Whighspeed < Wlowspeed)
      {	
	cout << "Wind Speed range should be Low to High" << endl;
	return 0 ;
      }
    else if (WspeedIncrement <= 0)
      {  
	cout << "Wind speed Incremental value should be positive or Invalid value entered" << endl;
	return 0;
      }
  cout << endl;
  /*Function call to print Wind Chill  table */
   PrintTable(Hightemp, Lowtemp, Whighspeed,Wlowspeed, TempDecrement,WspeedIncrement);
}

