###############################################
# NAME : SWATI BOTUWAR                        #
# Z-ID : Z1828087                             #
# CSCI/689/Section 1                          #
# TA NAME : NITHIN DEVANG                     #
# ASSIGNMENT NUMBER : 3                       #
# DUE DATE : FRIDAY , 17th FEBRUARY  2017     #
###############################################


#    Defining make file variables.


CC = g++
CCFLAGS = -Wall -Werror


#    Makefile rules start here


assign4 : assign4.o processdata.o
	$(CC) -o assign4 $(CCFLAGS)  assign4.o processdata.o

assign4.o : assign4.cc linecommenting.h
	$(CC) -c $(CCFLAGS) assign4.cc

processdata.o : processdata.cc linecommenting.h
	$(CC) -c $(CCFLAGS) processdata.cc

clean : 
	-rm *.o assign4 *.txt
