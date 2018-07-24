/*****************************************************************
NAME : SWATI BOTUWAR
Z-ID : Z1828087
CSCI/689/Section 1
TA NAME : NITHIN DEVANG
ASSIGNMENT NUMBER :8
DUE DATE : WEDNESDAY 26th APRIL  2017
DESCRIPTION: This is a header file for class printAmenity.
             It contains printAmenity data member, two function object
             and a function print_top_bottom_n value whcih is made 
             friend to printAmenity class.
******************************************************************/

#ifndef PRINTAMENITY_H
#define PRINTAMENITY_H

#include <iostream>
#include <iomanip>
#include "Amenity.h"
using std :: setw;
using std :: left;
using std :: right;
const int JANTEMP = 1;
const int JANSUN = 2;
const int JULYTEMP = 3;
const int JULYHUM = 4;
const int LANDTYPE = 5;
const int TERRAMT = 6;
const int COMPVAL = 7;

class printAmenity 
{
    int amenityField;
    
    
public:
    printAmenity(); //default constructor
    printAmenity(int value); //parameterized constructor

//Setter function to set printAmenity class member

    void set_amenityField(int val); 

//function object with Amenity as parameter

    void operator()(const Amenity&) const;

//function object with two instance of Amenity as parameter

    bool operator()(const Amenity& ,const Amenity&); 

//function made friend to class to print top and bottom n values

    friend void print_top_bottom_n(vector<Amenity>& ,int n, const printAmenity&);
};

//function to print top and bottom n values

void print_top_bottom_n(vector<Amenity>& ,int n, const printAmenity&);

#endif /* PRINTAMENITY_H */


