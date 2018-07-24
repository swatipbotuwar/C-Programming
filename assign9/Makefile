###############################################
# NAME : SWATI BOTUWAR                        #
# Z-ID : Z1828087                             #
# CSCI/689/Section 1                          #
# TA NAME : NITHIN DEVANG                     #
# ASSIGNMENT NUMBER : 9                       #
# DUE DATE : THURSDAY , 4th MAY 2017          #
###############################################


#    Defining make file variables.


CC = g++ 
CCFLAGS =  -g -Wall -Werror 

#    Makefile rules start here


assign9 : assign9.o  
	$(CC) -o assign9 $(CCFLAGS)  assign9.o 

assign9.o : assign9.cc vectorN.h 
	$(CC) -c $(CCFLAGS) -std=c++11  assign9.cc 

clean : 
	-rm *.o assign9
