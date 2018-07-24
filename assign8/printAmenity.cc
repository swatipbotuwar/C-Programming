/*****************************************************************
NAME : SWATI BOTUWAR
Z-ID : Z1828087
CSCI/689/Section 1
TA NAME : NITHIN DEVANG
ASSIGNMENT NUMBER :8
DUE DATE : WEDNESDAY 26th APRIL  2017
DESCRIPTION: This file has defination of Constructor and functions
              to  print top and bottom values of amenity.
             Along with function object definition

******************************************************************/

#include "printAmenity.h"
#include "Amenity.h"

//function prototype for non member function

void print_top_bottom_n(vector<Amenity>& ,int n, const printAmenity&);

//Default constructor

printAmenity::printAmenity()
{
    amenityField = 0;
}

//Parameterized constructor

printAmenity::printAmenity(int value)
{
    amenityField = value;
}

//Setter for class data member amenityField

void printAmenity :: set_amenityField(int val)
{ 
    amenityField = val;
}

//function object defination with Amenity as parameter

void printAmenity :: operator()(const Amenity& a) const
{
//check value for amenityField for current instance and display result accordingly.

    switch(amenityField)
    {
        case JANTEMP : cout <<right<<setw(15)<<a.get_countyName()<<setw(4)<<a.get_stateName()<<setw(10)<< a.get_janTemp() << endl ;
                       break;
                       
        case JANSUN : cout <<right<<setw(15)<<a.get_countyName()<<setw(4)<<a.get_stateName()<<setw(10)<< a.get_janSun() << endl ;
                       break;

        case JULYTEMP : cout <<right<<setw(15)<<a.get_countyName()<<setw(4)<<a.get_stateName()<<setw(10)<< a.get_julyTemp() << endl ;
                       break;

        case JULYHUM : cout <<right<<setw(15)<<a.get_countyName()<<setw(4)<<a.get_stateName()<<setw(10)<< a.get_julyHum() << endl ;
                       break;

        case LANDTYPE : cout <<right<<setw(15)<<a.get_countyName()<<setw(4)<<a.get_stateName()<<setw(10)<< a.get_landType() << endl ;
                       break;
                       
        case TERRAMT : cout <<right<<setw(15)<<a.get_countyName()<<setw(4)<<a.get_stateName()<<setw(10)<< a.get_terrAmt() << endl ;
                       break;                
                       
        case COMPVAL : cout <<right<<setw(15)<<a.get_countyName()<<setw(4)<<a.get_stateName()<<setw(10)<< a.get_compVal() << endl ;
                       break;
                       
        default: cout <<"Please provide correct Amenity field value";
                 break;
    }

    
}

//compare two amenity for Composite amenity value and return bool value

bool printAmenity :: operator()(const Amenity& a , const Amenity& b) 
 {
    if(a.get_compVal() > b.get_compVal())
        return true;
    else
        return false;
 }

// function to print top and bottom n values using STL algorithm and lambda function

void print_top_bottom_n(vector<Amenity>& amenityDetails , int n, const printAmenity& p)
{
    for_each(amenityDetails.begin(),amenityDetails.begin()+n,[amenityDetails,p] (Amenity a) 
                                                                {  p(a);});
    cout << "..."<< endl;

    for_each(amenityDetails.end()-n ,amenityDetails.end(),[amenityDetails,p](Amenity b){ p(b);});
    
}

