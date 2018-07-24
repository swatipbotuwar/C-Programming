###############################################
# NAME : SWATI BOTUWAR                        #
# Z-ID : Z1828087                             #
# CSCI/689/Section 1                          #
# TA NAME : NITHIN DEVANG                     #
# ASSIGNMENT NUMBER : 7                       #
# DUE DATE : TUESDAY , 18th APRIL  2017       #
###############################################


#    Defining make file variables.


CC = g++ 
CCFLAGS =  -g -Wall -Werror 

#    Makefile rules start here


assign7 : assign7.o SetHelper.o 
	$(CC) -o assign7 $(CCFLAGS)  assign7.o SetHelper.o 

SetHelper.o: SetHelper.cc SetHelper.h 
	$(CC) -c $(CCFLAGS) SetHelper.cc

assign7.o : assign7.cc SetHelper.h 
	$(CC) -c $(CCFLAGS) -std=c++11  assign7.cc 

clean : 
	-rm *.o assign7
