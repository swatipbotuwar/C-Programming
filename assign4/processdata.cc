/*****************************************************************
NAME : SWATI BOTUWAR
Z-ID : Z1828087
CSCI/689/Section 1
TA NAME : NITHIN DEVANG
ASSIGNMENT NUMBER : 4
DUE DATE : Monday, 27th FEBRUARY 2017
DESCRIPTION : This function convert line comment to block comment 
              and write it to output file.
********************************************************************/


#include "linecommenting.h"

int process_data(string value, ofstream& OutputFile, int& flag)
{

   string val = " */"; 

   for(unsigned  i=1; i <value.length() ;i++)
      { 
        cout << flag << endl;
       if(value.at(0) == '/' && value.at(1) == '/' && flag ==0 ) 
          {
              value.replace(i, 1, "*") ;
              value.append(val);
              break;
          }
       else

       if(value.at(i-1) == '/' && value.at(i) == '/' && flag == 0)
          { cout << "enter in this loop"<< endl;
              value.replace(i, 1, "*") ;
              value.append(val);

          }
        else
        if(value.at(i-1) =='"' && flag ==0) 
          { cout<< "enter in first"<< value.at(i) <<  endl;
            flag =2;
            continue;
//             break;
          }
       else
        if(value.at(i-1) =='"' && flag ==2)
          { cout << "enter in second" << value.at(i)<<endl; 
           flag =0;
           continue;
          }
       else 
       if(value.at(i-1) == '/' && value.at(i)== '*' && flag ==0)
         { 
             flag = 1;
             break;    
             
         }
       else
       if(value.at(i-1)=='*' &&  value.at(i) == '/' && flag==1)
         {
             flag =0; 
             continue;
         }
       else 
       if(value.at(i-1) == '\\' && value.at(i) == '"')
         { flag =0;
           continue;

          }
           
      }     
   
 OutputFile << value << endl; 


return flag;
}
