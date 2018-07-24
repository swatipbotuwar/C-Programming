/*****************************************************************
NAME : SWATI BOTUWAR
Z-ID : Z1828087
CSCI/689/Section 1
TA NAME : NITHIN DEVANG
ASSIGNMENT NUMBER : 4
DUE DATE : Monday, 27th FEBRUARY 2017
DESCRIPTION : This program takes Input file and output file name
              as command line argument, and convert line comment into
              block comment and write it to output file.
********************************************************************/

#include "linecommenting.h"

/**
   This main function will take two command line argument
   first is Input file, second Output file 
*/

int main(int argc, char* argv[])
{  
    ifstream InputFile;
    ofstream OutputFile;
 
    if(argc < 3)
      {
          cout << "Program : " << argv[0] <<" Need two input argument, Input File Name and Output File Name" << endl ;
          exit(1);
      }

    string ifile = argv[1];
    string ofile = argv[2];
    string value;
    int flag =0,tempFlag = 0;
    InputFile.open(ifile.c_str());
    OutputFile.open(ofile.c_str());

    if(! InputFile.is_open())
      {
          cerr << "Unable to open a" << InputFile << "file."<<endl;
          return -1;
      }
    if(! OutputFile.is_open())
      {
          cerr << "Unable to open a"<< OutputFile << "File." << endl;
          return -1;
      }
    getline(InputFile, value);
    
    while (!InputFile.eof())
         {
            
            tempFlag = process_data(value, OutputFile, flag);
            flag = tempFlag;
            
            getline(InputFile , value);
         } 

    OutputFile.close();
    InputFile.close();

    return 0;
}
