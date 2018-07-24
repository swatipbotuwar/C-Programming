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

all : generate thresh 

generate : generate.o
	$(CC) -o generate $(CCFLAGS)  generate.o

thresh : thresh.o
	$(CC) -o thresh $(CCFLAGS) thresh.o

generate.o : generate.cc threshhold.h
	$(CC) -c $(CCFLAGS) generate.cc

thresh.o : thresh.cc threshhold.h
	$(CC) -c $(CCFLAGS) thresh.cc

clean : 
	-rm *.o generate thresh *.dat
