/*****************************************************************
NAME : SWATI BOTUWAR
Z-ID : Z1828087
CSCI/689/Section 1
TA NAME : NITHIN DEVANG
ASSIGNMENT NUMBER :6
DUE DATE : FRIDAY, 7th APRIL  2017
DESCRIPTION : This source code file contains main() and print_pedigree()
              to print small genealogical database. main ()reads input 
              file name as command line argument.
*******************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "person.h"
#include "place.h"
#include "date.h"
#include "textCanvas.h"
#include "name.h"

using std :: cout;
using std :: cin; 
using std :: ifstream;
using std :: vector;
using std :: string;
using std :: cerr;
using std :: stoi;
using std :: endl;

 /* Print pedigree function */

void print_pedigree(textCanvas& tc, const vector<Person> & person, int root)
{
  
  tc.clear();
  
  // Print tree diagram

  const int boxwidth = CWIDTH / 3;     // Three generations
  const int boxheight = CHEIGHT / 4;   // Four ancestors in third generation

  const int root_x = 0;
  const int root_y = int(1.5 * boxheight);

  const int father_x = boxwidth;
  const int father_y = int(0.5 * boxheight);
  
  const int mother_x = boxwidth;
  const int mother_y = int(2.5 * boxheight);

  const int pgf_x = 2 * boxwidth;  // Paternal grandfather
  const int pgf_y = 0;

  const int pgm_x = 2 * boxwidth;  // Paternal grandmother
  const int pgm_y = boxheight;

  const int mgf_x = 2 * boxwidth;  // Maternal grandfather
  const int mgf_y = 2 * boxheight; 

  const int mgm_x = 2 * boxwidth;  // Maternal grandmother
  const int mgm_y = 3 * boxheight;


  // Line for root
  tc.print_horizontal_line(root_x, root_y, boxwidth);

  // Horizontal line for father
  tc.print_horizontal_line(father_x, father_y, boxwidth);

  // Horizontal line for mother
  tc.print_horizontal_line(mother_x, mother_y, boxwidth);
		       
  // Horizontal lines for grandparents
  tc.print_horizontal_line(pgf_x, pgf_y, boxwidth);
  tc.print_horizontal_line(pgm_x, pgm_y, boxwidth);
  tc.print_horizontal_line(mgf_x, mgf_y, boxwidth);
  tc.print_horizontal_line(mgm_x, mgm_y, boxwidth);

  // Vertical lines
  tc.print_vertical_line(father_x, father_y, 2 * boxheight);
  tc.print_vertical_line(pgf_x, pgf_y, boxheight);
  tc.print_vertical_line(mgf_x, mgf_y, boxheight);

  // Print the pedigree
  int person_id = root;
  tc.set_box(root_x, root_y, boxwidth, boxheight);
  person[person_id].print(tc);

  // Print father's line
  if(person[person_id].get_father() != -1){
    person_id = person[root].get_father();
    tc.set_box(father_x, father_y, boxwidth, boxheight);
    person[person_id].print(tc);
    
    if(person[person_id].get_father() != -1){
      tc.set_box(pgf_x, pgf_y, boxwidth, boxheight);
      person[person[person_id].get_father()].print(tc);
    }
    if(person[person_id].get_mother() != -1){
      tc.set_box(pgm_x, pgm_y, boxwidth, boxheight);
      person[person[person_id].get_mother()].print(tc);
    }
  }

  // Print mother's line
  if(person[root].get_mother() != -1){
    person_id = person[root].get_mother();
    tc.set_box(mother_x, mother_y, boxwidth, boxheight);
    person[person_id].print(tc);
    
    if(person[person_id].get_father() != -1){
      tc.set_box(mgf_x, mgf_y, boxwidth, boxheight);
      person[person[person_id].get_father()].print(tc);
    }
    if(person[person_id].get_mother() != -1){
      tc.set_box(mgm_x, mgm_y, boxwidth, boxheight);
      person[person[person_id].get_mother()].print(tc);
    }
  }

  tc.print();
}


/* Main fucntion start here */



int main(int argc, char* argv[])
   {  
      /*  condition check for number of argument */

      if(argc < 2)
       {
          cout << "Program: " << argv[0] << " expect File Name as a parameter" << endl;
          exit(1);
       }

      string first, last;
      Date birth;
      string bday,bmonth, byear; 
      Place birthPlace;
      string  bcity, bcounty, bstate;
      Date death;
      string dday, dmonth, dyear;
      Place deathPlace;
      string dcity,dcounty, dstate;
      string findex, mindex, cindex;
      int root = 0;
      vector <Person> personDetails;
      Person personObj;
      textCanvas tc;
      Name lname , fname;      
      int root1;
      char val = ' ';
 
      ifstream inputFile;
      string fileName = argv[1];

      inputFile.open(fileName.c_str()) ;
      
 // check for whether file is open or not 

      if(! inputFile.is_open())
         {
           cerr << "Unable to open a" << fileName << " file." << endl;
           return -1;
         }

 // read file content till end of file line by line 
     
      while(! inputFile.eof())
       {
          getline(inputFile, last);
          getline(inputFile, first) ;
          getline(inputFile, bday);
          getline(inputFile, bmonth);
          getline(inputFile, byear);
          getline(inputFile, bcity);
          getline(inputFile, bcounty);
          getline(inputFile, bstate);
          getline(inputFile, dday);
          getline(inputFile, dmonth);
          getline(inputFile, dyear);
          getline(inputFile, dcity);
          getline(inputFile, dcounty);
          getline(inputFile, dstate);
          getline(inputFile, findex);
          getline(inputFile, mindex);
          getline(inputFile, cindex);

          last = (last == "") ? " " : last;
          first= (first == "") ? " " : first;
          bday =(bday == "") ? " " : bday;
          bmonth =(bmonth == "") ? " " : bmonth;
          byear =(byear == "") ? " " : byear;
          bcity =(bcity == "") ? " " : bcity;
          bcounty =(bcounty == "") ? " " : bcounty;
          bstate =(bstate == "") ? " " : bstate; 
          dday =(dday == "") ? " " : dday;
          dmonth =(dmonth == "") ? " " : dmonth;
          dyear =(dyear == "") ? " " : dyear;
          dcity =(dcity == "") ? " " : dcity;
          dcounty =(dcounty == "") ? " " : dcounty;
          dstate=(dstate == "") ? " " : dstate; 
          findex = (findex == "") ? " " : findex;
          mindex = (mindex == "") ? " " : mindex;
          cindex = (cindex == "") ? " " : cindex;
          int clink = stoi(cindex);
          int flink = stoi(findex);
          int mlink = stoi(mindex);
          
 // Initialize  object of person class data member by values read from file.  
  
          lname = Name(last);
          fname = Name(first);  
          birth = Date(bday,bmonth,byear);
          death = Date(dday,dmonth,dyear);
                    
          birthPlace = Place(bcity,bcounty,bstate);
          deathPlace = Place(dcity,dcounty ,dstate);
          personObj  = Person(lname, fname, birth,birthPlace , death, deathPlace , flink, mlink, clink);

//Push complete person object to vector of Person class

          personDetails.push_back(personObj);

       }

     inputFile.close();

//call print_pedigree function to print pedigree anchored at root position 

     print_pedigree(tc,  personDetails, root);

//Loop for asking user for value that whose pedigree should be print 

     while(val != 'q')
      {        
        cout << "Move to F)ather, M)other, C)hild or Q)uit?" <<  endl;
        cin >> val;
               
        switch(tolower(val))
         {
           case 'f': if( personDetails[root].get_father() != -1)
                       { 
                         root1 = personDetails[root].get_father();
                         print_pedigree(tc,  personDetails, root1 );
                         root = root1;
                       }
                       break;
           
           case 'm': if( personDetails[root].get_mother() != -1)
                       { 
                         root1 = personDetails[root].get_mother();
                         print_pedigree(tc,  personDetails, root1 );
                         root = root1;
                       }
                       break;
                        
           case 'c': if( personDetails[root].get_child() != -1)
                       { 
                         root1 = personDetails[root].get_child();
                         print_pedigree(tc,  personDetails, root1 );
                         root = root1;
                         
                       }
                       break;
                     
           case 'q': exit(0);

           default: cout << "Please enter value as F or M or C or Q" << endl;
                    
         }
     
     }
    
	     
    return 0; 
     
}
