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


assign8 : assign8.o Amenity.o printAmenity.o
	$(CC) -o assign8 $(CCFLAGS)  assign8.o Amenity.o printAmenity.o

Amenity.o: Amenity.cc Amenity.h
	$(CC) -c $(CCFLAGS) -std=c++11 Amenity.cc

printAmenity.o: printAmenity.cc printAmenity.h
	$(CC) -c $(CCFLAGS) -std=c++11  printAmenity.cc

assign8.o : assign8.cc printAmenity.h Amenity.h
	$(CC) -c $(CCFLAGS) -std=c++11  assign8.cc

clean :
	-rm *.o assign8
