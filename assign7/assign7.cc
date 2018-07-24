/*****************************************************************
NAME : SWATI BOTUWAR
Z-ID : Z1828087
CSCI/689/Section 1
TA NAME : NITHIN DEVANG
ASSIGNMENT NUMBER :7
DUE DATE : TUESDAY 18th APRIL  2017
DESCRIPTION: this file have logic to read data from input file 
             and write the data into SET container. Also display 
             content of SET to output stream.
******************************************************************/

#include <iostream>
#include <cstdlib>
#include <set>
#include <string>
#include <fstream>
#include <iterator>
#include "SetHelper.h"
using std :: cout;
using std :: cerr;
using std :: stoi;
using std :: ifstream;
using std :: endl;
using std :: set;
using std :: string;
using std :: iterator;

/**
    Main() start here, which take file name 
    as a command line argument
*/

int main(int argc, char* argv[])
   {

//Check for number of argument at command line
      if(argc < 2)
       {
         cerr << " Program: "<< argv[0] <<" required file name as command line argument." << endl;
         exit(1);
       }
     
       ifstream inputFile;
       string filename= argv[1];

//open input file and check whether file is open or not

       inputFile.open(filename.c_str());
       if(!inputFile.is_open())
          {
              cerr << "unable to open a input file "<< filename << endl;
              return -1;
          }
       set <SetHelper> setData;
       SetHelper SH;
       string text;
       string seqNumber;

// Read the data from file till EOF, and insert that data into SET
       while(!inputFile.eof())
          {  
             
              inputFile >>  seqNumber;
              inputFile >> text;
              int seq = stoi(seqNumber);
              SH = SetHelper(seq, text);
              setData.insert(SH);

           }
    
       inputFile.close();
       set <SetHelper> :: iterator it;

       for(it = setData.begin(); it != setData.end(); ++it)
           { 
              
                  cout << *it;
           }
   
    return 0;
  }              
         
