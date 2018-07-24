/*****************************************************************
NAME : SWATI BOTUWAR
Z-ID : Z1828087
CSCI/689/Section 1
TA NAME : NITHIN DEVANG
ASSIGNMENT NUMBER :8
DUE DATE : WEDNESDAY 26th APRIL  2017
DESCRIPTION: This file has logic to read data from input file.
             Calcultae composite Amenity value and print the sorted
             data by each amenity type.
******************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "Amenity.h"
#include "printAmenity.h"
#include <vector>
#include <iterator>
#include "math.h"
#include <algorithm>
#include <sstream>

using std :: cout;
using std :: cin;
using std :: endl;
using std :: string;
using std :: ifstream;
using std :: cerr;
using std :: vector;
using std :: stoi;
using std :: stof;
using std :: transform;
using std :: log;
using std :: iterator;
using std :: sort;
using std :: stable_sort;
using std :: istringstream ;

//list of Function Prototype
void inputFunction(ifstream& inputFile, Amenity& amenityObj, vector <Amenity>& amenityDetails);
float mathFun1(vector <float> v );
float mathFun2(vector <float> v, float avg);
void compositeAmenity(vector <Amenity>& amenityDetails);


//Function read input file and push data to vector of Amenity type

void inputFunction(ifstream& inputFile, Amenity& amenityObj, vector <Amenity>& amenityDetails)
{
    string line;
    int id1;
    string stateNm;
    string countyNm;
    float janTemp;
    float janSun;
    float julyTemp;
    float julyHum;
    int landType;
    float terrainAmt;
    string sname;
    float compVal = 0.0;
    
    while(getline(inputFile,line))
    {
        istringstream streamLine(line);
        vector<string> field;
        string fieldValue;
//writing line to vector of string
        while(getline(streamLine,fieldValue,','))
        {
            field.push_back(fieldValue);
        }
        id1 = stoi(field[0]);
        stateNm = field[1];
        countyNm = field[2];
        janTemp = stof(field[3]);
        janSun = stof(field[4]);
        julyTemp = stof(field[5]);
        julyHum = stof(field[6]);
        landType = stoi(field[7]);
        terrainAmt = stof(field[8]);
        amenityObj = Amenity(id1,stateNm,countyNm,janTemp,janSun,julyTemp,julyHum,landType,terrainAmt,compVal);
        amenityDetails.push_back(amenityObj);
        field.clear();
    }
}

//Function to calculate average of each amenity type

float mathFun1(vector <float> v )
 {
     float sum = 0.0;
     
     std::for_each(v.begin(), v.end(), [=, &sum] (float n) {
                                                    sum += n;});
     float avg = sum/v.size();
     return avg;
     
 }

//Function to calculate Standard Deviation for each Amenity type 

 float mathFun2(vector <float> v, float avg)
 {
     float sumVal = 0.0;
     float stdDev = 0.0;
     for_each(v.begin(),v.end(),
               [=,&sumVal] (float x)
               {
                 return sumVal += ((x-avg)*(x-avg));
                 
               });
     stdDev = sqrt(sumVal/(v.size() -1));
     return stdDev;
}

//Function which calculate Composite Amenity Value
 
void compositeAmenity(vector <Amenity>& amenityDetails)
{
    float janTempAverage, janSunAverage, julyTempAvg, julyHumAvg,landTypeAvg, terrAmtAvg;
    float janTempStdDev, julyTempStdDev, janSunStdDev, julyHumStdDev, landTypeStdDev,terrAmtStdDev;
      
    vector <float> newVec(amenityDetails.size());

// Using algorithm for JanTemp amenity to read into vector<float> and then calculating average and standard deviation
    transform(amenityDetails.begin(),amenityDetails.end(),newVec.begin(),[] (Amenity& a)-> float{ return a.get_janTemp();});
    janTempAverage = mathFun1(newVec);
    janTempStdDev = mathFun2(newVec, janTempAverage);


// Using algorithm for JanSunshine amenity to read into vector<float> and then calculating average and standard deviation  
    transform(amenityDetails.begin(),amenityDetails.end(),newVec.begin(),[] (Amenity& a)-> float{ return a.get_janSun();});
    janSunAverage = mathFun1(newVec);
    janSunStdDev = mathFun2(newVec, janSunAverage);
    
// Using algorithm for JulyTemp amenity to read into vector<float> and then calculating average and standard deviation
    transform(amenityDetails.begin(),amenityDetails.end(),newVec.begin(),[] (Amenity& a)-> float{ return a.get_julyTemp();});
    julyTempAvg = mathFun1(newVec);
    julyTempStdDev = mathFun2(newVec, julyTempAvg);
    
// Using algorithm for JulyHumidity amenity to read into vector<float> and then calculating average and standard deviation
    transform(amenityDetails.begin(),amenityDetails.end(),newVec.begin(),[] (Amenity& a)-> float{ return a.get_julyHum();});
    julyHumAvg = mathFun1(newVec);
    julyHumStdDev = mathFun2(newVec, julyHumAvg);
    
// Using algorithm for landForm Type amenity to read into vector<float> and then calculating average and standard deviation
    transform(amenityDetails.begin(),amenityDetails.end(),newVec.begin(),[] (Amenity& a)-> float{ return a.get_landType();});
    landTypeAvg = mathFun1(newVec);
    landTypeStdDev = mathFun2(newVec, landTypeAvg);
    
// Using algorithm for Terrain Amount  amenity to read into vector<float> and then calculating average and standard deviation
    transform(amenityDetails.begin(),amenityDetails.end(),newVec.begin(),[] (Amenity& a)-> float{ return log(a.get_terrAmt()*100);});
    terrAmtAvg =  mathFun1(newVec);
    terrAmtStdDev = mathFun2(newVec, terrAmtAvg);
    
    
//loop to calculate Composite Amenity value and writing back to vector
    
    for(unsigned int i=0; i < amenityDetails.size() ; i++)
    {
        float compAmenityVal;
        float ZTemp = (amenityDetails[i].get_janTemp() - janTempAverage)/janTempStdDev ;
        float zSun = (amenityDetails[i].get_janSun() - janSunAverage)/janSunStdDev ;
        float ZJTemp = (amenityDetails[i].get_julyTemp() - julyTempAvg)/julyTempStdDev ;
        float ZJHum = (amenityDetails[i].get_julyHum() - julyHumAvg)/julyHumStdDev ;
        float ZLand = (amenityDetails[i].get_landType() - landTypeAvg)/landTypeStdDev ;
        float ZTAmt = (log(amenityDetails[i].get_terrAmt() *100) - terrAmtAvg)/terrAmtStdDev; 
        compAmenityVal = ZTemp+ zSun +ZLand +ZTAmt - ZJTemp -ZJHum ; 
        
        amenityDetails[i].set_ComAmnVal(compAmenityVal);
    }
    
 }



// main start here

int main(int argc, char* argv[])
{

//check for number of command line argument

    if(argc < 2)
       {
          cout << "Program: " << argv[0] << " expect File Name as a parameter" << endl;
          exit(1);
       }
    
    ifstream inputFile;
    string filename= argv[1];
    inputFile.open(filename.c_str());

//check if file is open 
       
    if(!inputFile.is_open())
       {
          cerr << "unable to open a input file"<< filename << endl;
          return -1;
       }
    
    vector <Amenity> amenityDetails;
  
    Amenity amenityObj;
    printAmenity p;
    inputFunction(inputFile,amenityObj,amenityDetails);
    inputFile.close();
    compositeAmenity(amenityDetails);

//Perform sorting and print data for each amenity type by using printAmenity class object 
    
    cout << "Ranking By January Temperature" << endl;
    cout << "===========================================" << endl;
    stable_sort(amenityDetails.begin(),amenityDetails.end(),compJanTemp);
    p.set_amenityField(JANTEMP);
    print_top_bottom_n(amenityDetails ,12, p);
    cout << endl<< endl;
    
    cout << "Ranking By January Sunshine" << endl;
    cout << "===========================================" << endl;
    stable_sort(amenityDetails.begin(),amenityDetails.end(), compJanSun);
    p.set_amenityField(JANSUN);
    print_top_bottom_n(amenityDetails ,12, p);
    cout << endl<< endl;
    
    cout << "Ranking By July Temperature" << endl;
    cout << "===========================================" << endl;
    stable_sort(amenityDetails.begin(),amenityDetails.end(), compJulyTemp);
    p.set_amenityField(JANTEMP);
    print_top_bottom_n(amenityDetails ,12, p);
    cout << endl<< endl;
    
    cout << "Ranking By July Humidity" << endl;
    cout << "===========================================" << endl;
    stable_sort(amenityDetails.begin(),amenityDetails.end(), compJulyHum);
    p.set_amenityField(JULYHUM);
    print_top_bottom_n(amenityDetails ,12, p);
    cout << endl<< endl;
            
    cout << "Ranking By Landform Type" << endl;
    cout << "===========================================" << endl;
    stable_sort(amenityDetails.begin(),amenityDetails.end(),complandformType);
    p.set_amenityField(LANDTYPE);
    print_top_bottom_n(amenityDetails ,12, p);
    cout << endl<< endl;
    
    cout << "Ranking By Water Area " << endl;
    cout << "===========================================" << endl;
    sort(amenityDetails.begin(),amenityDetails.end(),compTerrainAmt);
    p.set_amenityField(TERRAMT);
    print_top_bottom_n(amenityDetails ,12, p);
    cout << endl<< endl;
    
    cout << "Composite Ranking  " << endl;
    cout << "===========================================" << endl;
    stable_sort(amenityDetails.begin(),amenityDetails.end(),p);
    p.set_amenityField(COMPVAL);
    print_top_bottom_n(amenityDetails ,10, p);
    cout << endl<< endl;
   
    
    return 0;
 }
