/*****************************************************************
NAME : SWATI BOTUWAR
Z-ID : Z1828087
CSCI/689/Section 1
TA NAME : NITHIN DEVANG
ASSIGNMENT NUMBER :8
DUE DATE : WEDNESDAY 26th APRIL  2017
DESCRIPTION: This file has Amenity details, constructor and functions
             to compare each amenity type. Also, setter to set 
             composite Amenity value
******************************************************************/

#include "Amenity.h"

//function prototype for all non member function

   bool compJanTemp(const Amenity& t1,const Amenity& t2);
   bool compJanSun(const Amenity& t1,const Amenity& t2);
   bool compJulyTemp(const Amenity& t1,const Amenity& t2);
   bool compJulyHum(const Amenity& t1,const Amenity& t2);
   bool complandformType(const Amenity& t1,const Amenity& t2);
   bool compTerrainAmt(const Amenity& t1,const Amenity& t2);


//default constructor
Amenity::Amenity()
 {
    janTemp = 0.0;
    janSunshine = 0.0;
    julyTemp = 0.0;
    julyHumidity = 0.0;
    landformType = 0;
    terrainAmount = 0.0;
    ID = 0;
    countyName = "";
    stateName = "";
    compAmenityVal = 0.0;
 }

//parameterized constructor

Amenity::Amenity(int ID1,string stateName1,string countyName1, float janTemp1,float janSunshine1,float julyTemp1,float julyHumidity1,int landformType1,float terrainAmount1,float compVal)
 {
    janTemp = janTemp1;
    janSunshine = janSunshine1;
    julyTemp = julyTemp1;
    julyHumidity = julyHumidity1;
    landformType = landformType1;
    terrainAmount = terrainAmount1;
    ID = ID1;
    countyName = countyName1;
    stateName = stateName1;
    compAmenityVal= compVal;
 }

//setter for Composite Amenity type value

void Amenity :: set_ComAmnVal(float comp)
 {
    compAmenityVal = comp;
 }

//getters for each amenity type

float Amenity :: get_compVal(void ) const
 {
    return compAmenityVal ;
 }

string Amenity :: get_countyName(void) const
 {
    return countyName;
 }

string Amenity :: get_stateName(void) const
 {
    return stateName;
 }

float Amenity :: get_janTemp(void) const
 {
    return janTemp;
 }

float Amenity :: get_janSun(void) const
 {
    return janSunshine;
 }

float Amenity :: get_julyTemp(void) const
 {
    return julyTemp;
 }

float Amenity :: get_julyHum(void) const
 {
    return julyHumidity;
 }

int Amenity :: get_landType(void) const
 {
    return landformType;
 }

float Amenity :: get_terrAmt(void) const
 {
    return terrainAmount;
 }


// Comparision functions to compare two amenity of type janTemp and return bool value

 bool compJanTemp(const Amenity& t1,const Amenity& t2)
  {
    if(t1.janTemp > t2.janTemp)
       return true;
    else
       return false;
  }

// Comparision functions to compare two amenity of type janSunshine and return bool value
 
 bool compJanSun(const Amenity& t1,const Amenity& t2)
  {
     if(t1.janSunshine > t2.janSunshine)
          return true;
    else
       return false;
  }
  
// Comparision functions to compare two amenity of type julyTemp and return bool value

bool compJulyTemp(const Amenity& t1,const Amenity& t2)
 {
     if(t1.julyTemp < t2.julyTemp)
          return true;
    else
       return false;
 }

// Comparision functions to compare two amenity of type july Humidity and return bool value

bool compJulyHum(const Amenity& t1,const Amenity& t2)
 {
     if(t1.julyHumidity < t2.julyHumidity)
          return true;
    else
       return false;
 }

// Comparision functions to compare two amenity of type landformType  and return bool value

bool complandformType(const Amenity& t1,const Amenity& t2)
 {
     if(t1.landformType > t2.landformType)
          return true;
    else
       return false;
 }

// Comparision functions to compare two amenity of type Terrain Amount and return bool value

bool compTerrainAmt(const Amenity& t1,const Amenity& t2)
 {
     if(t1.terrainAmount > t2.terrainAmount)
          return true;
    else
       return false;
 }


