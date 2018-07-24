/*****************************************************************
NAME : SWATI BOTUWAR
Z-ID : Z1828087
CSCI/689/Section 1
TA NAME : NITHIN DEVANG
ASSIGNMENT NUMBER :8
DUE DATE : WEDNESDAY 26th APRIL  2017
DESCRIPTION: This is a header file for class Amenity.
             It contains Amenity data member details and function 
             prototype.
******************************************************************/


#ifndef AMENITY_H
#define AMENITY_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using std :: string;
using std :: vector;
using std :: for_each;
using std :: transform;
using std :: sqrt;
using std :: cout;
using std :: endl;

class Amenity 
{
    int ID;
    string stateName;
    string countyName;
    float janTemp;
    float janSunshine;
    float julyTemp;
    float julyHumidity;
    int landformType;
    float terrainAmount;
    float compAmenityVal;
 
public:
    Amenity(); //default constructor

    Amenity(int ID,string stateName,string countyName, float janTemp,float janSunshine,float julyTemp,float julyHumidity,int landformType,float terrainAmount,float compAmenityVal);  //parameterized constructor

//list of getter function for each data member

    string get_countyName(void)const;
    string get_stateName(void) const;
    float get_janTemp(void) const;
    float get_janSun(void) const;
    float get_julyTemp(void) const;
    float get_julyHum(void) const;
    int get_landType(void) const;
    float get_terrAmt(void) const;
    void set_ComAmnVal(float comp);
    float get_compVal(void) const;


//comparision function made friends to class Amenity
    
    friend bool compJanTemp(const Amenity& t1,const Amenity& t2);
    friend bool compJanSun(const Amenity& t1,const Amenity& t2);
    friend bool compJulyTemp(const Amenity& t1,const Amenity& t2);
    friend bool compJulyHum(const Amenity& t1,const Amenity& t2);
    friend bool complandformType(const Amenity& t1,const Amenity& t2);
    friend bool compTerrainAmt(const Amenity& t1,const Amenity& t2);
};

//comparision functions to compare amenity os each type

   bool compJanTemp(const Amenity& t1,const Amenity& t2);
   bool compJanSun(const Amenity& t1,const Amenity& t2);
   bool compJulyTemp(const Amenity& t1,const Amenity& t2);
   bool compJulyHum(const Amenity& t1,const Amenity& t2);
   bool complandformType(const Amenity& t1,const Amenity& t2);
   bool compTerrainAmt(const Amenity& t1,const Amenity& t2);

#endif /* AMENITY_H */
