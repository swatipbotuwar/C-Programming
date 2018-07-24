/*****************************************************************
NAME : SWATI BOTUWAR
Z-ID : Z1828087
CSCI/689/Section 1
TA NAME : NITHIN DEVANG
ASSIGNMENT NUMBER :5 
DUE DATE : FRIDAY, 10th MARCH  2017
DESCRIPTION : This program takes Input file as a argument,
              and write a vector of class object. Also, print the data
              from vector as output in increasing and decresing order of field. 
********************************************************************/

#include "readStormHeader.h"

/* list of function prototype */

void  printVector(vector<Storm>& vec);
void printHeader();
void  readInStormData(ifstream& inputFile, Storm& st, vector<Storm>& vec);
void  printVector(vector<Storm>& vec);
bool compareStorm(Storm& st1,Storm& st2);
void sortByDate(vector<Storm>& vec);
bool compareWind(Storm& st1,Storm& st2);
void sortByWindSpeed(vector<Storm>& vec);
bool comparePressure(Storm& st1,Storm& st2);
void sortByPressure(vector<Storm>& vec);



/* Function to print Header */

void printHeader()
   {
     cout <<left << setw(35) <<  "Storm" << setw(20)<< "Name" << setw(15) << "Date" << setw(10) <<"Wind"<<setw(5) <<right<< "mbar" <<endl;
     cout << "----------------------------------------------------------------------------------------------------------------"<<endl;
   }

/* Function to read data from file into vector */

void  readInStormData(ifstream& inputFile, Storm& st, vector<Storm>& vec)
   {
        char  basin;
        string name;
        int sequenceNumber;
        int year;
        int windSpeed;
        int airPressure;
        char type; 
        Storm  st1;
        int count =0;
        while(!inputFile.eof())
         {   
             count += 1;
             inputFile  >> basin;
             inputFile  >> name;
             inputFile  >> sequenceNumber;
             inputFile  >> year;
             inputFile  >> windSpeed;
             inputFile  >> airPressure;
             inputFile  >> type;
             st1 =  Storm(basin, name, sequenceNumber , year , windSpeed, airPressure, type);
             vec.push_back(st1); 
        }
      cout << "Total number of records read from file is: " << count << endl;

    inputFile.close();
  }

/* Function to print vector value */

void  printVector(vector<Storm>& vec)
    {
        vector <Storm> :: iterator it;
        int count =0;
        for( it = vec.begin(); it != vec.end() ; ++it)
          {
             count += 1;
             Storm s = *it;
             s.print();
             if(count%lineNumber == 0)
               {
                  cout << endl<< endl;
                  printHeader();
                  continue;
               }
          }

     }
   
/* Comaprision function to check for year value */

bool compareStorm(Storm& st1,Storm& st2)
    { 
        if(st1.getStormYear() < st2.getStormYear())
           return true;
   
        else 
        if(st1.getStormYear()== st2.getStormYear())
          {
              if(st1.getStormSequenceNumber() < st2.getStormSequenceNumber())
                return true;
              else
                return  false;
          }
        else
        return false;
    } 

/* Sorting data by Year value or sequence number*/

void sortByDate(vector<Storm>& vec)
    {
       int minIndex;
       Storm tempVec;
       for(unsigned int  b=0; b< vec.size()-1; b++)
          {
              minIndex = b;
              for(unsigned int i = b+1 ; i < vec.size(); i++)
                 { 
                     if(compareStorm(vec[i],vec[b]))
                       {
                            minIndex = i;
                            tempVec = vec[b];
                            vec[b] = vec[minIndex];
                            vec[minIndex] = tempVec;
                       }
                 } 
          }
  
     }

/* comparision for wind value */

bool compareWind(Storm& st1,Storm& st2)
    {
        if(st1.getMaxWindSpeed() < st2.getMaxWindSpeed())
        return true;
        else
        return false;
    }

/*sorting dat by Wind speed value descending order */

void sortByWindSpeed(vector<Storm>& vec)
   {
       int minIndex;
       Storm tempVec;
       for(unsigned int  b=0; b< vec.size()-1; b++)
         {
            minIndex = b;
            for(unsigned int i = b+1 ; i < vec.size(); i++)
               {
                  if(compareWind(vec[b],vec[i]))
                    {
                       minIndex = i;
                       tempVec = vec[b];
                       vec[b] = vec[minIndex];
                       vec[minIndex] = tempVec;
                    }
               }
          }
    }

/* Comparision function for pressure value */

bool comparePressure(Storm& st1,Storm& st2)
    {  
        if(st1.getMinAirPressure() < st2.getMinAirPressure())
          return true;
        else
          return false;
    }

/* sorting data by Air pressure in incresing order */

void sortByPressure(vector<Storm>& vec)
   {
       int minIndex;
       Storm tempVec;
       for(unsigned int  b=0; b< vec.size()-1; b++)
         {
             minIndex = b;
             for(unsigned int i = b+1 ; i < vec.size(); i++)
               {
                 if(comparePressure(vec[i],vec[b]))
                   { 
                      minIndex = i;
                      tempVec = vec[b];
                      vec[b] = vec[minIndex];
                      vec[minIndex] = tempVec;
                   }

                }
          }

    } 


/* main function */

int main(int argc, char * argv[])
  {
     if( argc < 2)
      {
         cerr << "Progrram :" << argv[0] << "  Needs Input File Name as a argument" << endl;
         exit(1);
      }
   
     ifstream inputFile;
     vector<Storm> vec ;
     string fileName = argv[1];
     Storm st, st1, st2;
     inputFile.open(fileName.c_str());

     if(! inputFile.is_open())
      {
         cerr << "Unable to Open a " << inputFile << endl;
         exit(1);
      }
     readInStormData(inputFile, st, vec);
     printHeader();
   
     printVector(vec);
     cout << endl;
     
     sortByDate(vec);  
     cout << "output Sorted by date value" << endl<< endl ;   
     printHeader();
     printVector(vec);
     cout << endl<< endl;

     cout <<"Output Sorted by Wind" << endl<< endl;
     sortByWindSpeed(vec);
     printHeader();
     printVector(vec);
     cout << endl<< endl;

     cout << "Output Sorted by Air pressure "<< endl<< endl;
     sortByPressure(vec);
     printHeader();
     printVector(vec);


return 0;
}


