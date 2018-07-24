###############################################
# NAME : SWATI BOTUWAR                        #
# Z-ID : Z1828087                             #
# CSCI/689/Section 1                          #
# TA NAME : NITHIN DEVANG                     #
# ASSIGNMENT NUMBER : 5                       #
# DUE DATE : FRIDAY , 10th MARCH  2017        #
###############################################


#    Defining make file variables.


CC = g++
CCFLAGS = -Wall -Werror


#    Makefile rules start here


assign5 : assign5.o 
	$(CC) -o assign5 $(CCFLAGS)  assign5.o 

assign5.o : assign5.cc readStormHeader.h
	$(CC) -c  $(CCFLAGS) assign5.cc

clean : 
	-rm *.o assign5
