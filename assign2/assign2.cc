/**************************************************************
NAME : SWATI BOTUWAR
Z-ID : Z1828087
CSCI/689/Section 1
TA NAME : NITHIN DEVANG
ASSIGNMENT NUMBER : 2
DUE DATE : WEDNESDAY, 8th FEBRUARY 2017
DESCRIPTION : This program calculte tax value for income based 
              on status category
************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>
#include "tax_calculator.h" 
using std :: cout;
using std ::cin;
using std :: endl;
using std :: setw;
using std :: left;
using std :: setprecision;
using std ::fixed ;
using std :: right ;

/* constant variable defined here */

const int table_field_width = 13;
const int field_width = 30;
const int first_col = 6;

/* 
    Main function Will take input from user.
    Contains  call for other function to calculate tax as per status.
    Loop for printing tax value table for range of 1000
*/

int main()
{
    float income;
    int i, startvalue , range , income_value;
    cout << "Please enter the Income value ? " ;
    cin >> income;
    cout << "Exact Tax" << endl;
    cout << left << setw(field_width) << fixed << setprecision(2) <<  "Single:" << single (income)<< endl;
    cout << left << setw(field_width) << "Married Filing Jointly:" << Married_filing_jointly(income) << endl; 
    cout << left << setw(field_width) << "Married Filing Seperately:" << Maried_filing_seperately(income) << endl; 
    cout << left << setw(field_width) << "Head Of Household:" << Head_of_household(income) << endl<< endl;;
    cout << left << setw(table_field_width) << "Income"<< "|" ;
    cout << right <<  setw(table_field_width) << " " << setw(table_field_width) << "Married" ;
    cout << setw(table_field_width) << "Married" << setw(table_field_width) <<  "Head" <<endl;  
    cout << left << setw(table_field_width) << "Range" << "|";
    cout << right << setw(table_field_width) << " " << setw(table_field_width) << "Filing" ;
    cout << setw(table_field_width) << "Filing" << setw(table_field_width) << "of" <<endl;
    cout << setw(table_field_width) << " " << "|" << setw(table_field_width) << "Single" << setw(table_field_width) << "Jointly" ; 
    cout << setw(table_field_width) << "Seperately" << setw(table_field_width) << "Household" << endl;
    cout << "**********************************************************************************************************" << endl;
    
       /*  calculate start and range value for table to be printed */
   
    startvalue = (int)(income / 1000) * 1000;
    
    range = startvalue + 1000;

       /* Printing Tax table for range of $1000 which represents income range of $50.00  */
    for ( i = startvalue ; i  < range ;)
    { 
        income_value = i + 25;
        cout << setw(first_col) << i << "-" << setw(first_col) << i+50  <<  "|" ;
        cout << setw(table_field_width) << int(round(single (income_value))) << setw(table_field_width) << int(round(Married_filing_jointly(income_value))) ;
        cout << setw(table_field_width) << int(round( Maried_filing_seperately(income_value))) ;
        cout << setw(table_field_width) << int(round( Head_of_household(income_value)))<< endl; 
        i = i+50;  
    }

    return 0;
}

