###############################################
# NAME : SWATI BOTUWAR                        #
# Z-ID : Z1828087                             #
# CSCI/689/Section 1                          #
# TA NAME : NITHIN DEVANG                     #
# ASSIGNMENT NUMBER : 6                       #
# DUE DATE : FRIDAY , 7th APRIL  2017         #
###############################################


#    Defining make file variables.


CC = g++ 
CCFLAGS =  -g -Wall -Werror 

#    Makefile rules start here


assign6 : assign6.o textCanvas.o Person.o Date.o Name.o Place.o 
	$(CC) -o assign6 $(CCFLAGS)  assign6.o textCanvas.o Person.o Date.o Name.o Place.o 

textCanvas.o: textCanvas.cc textCanvas.h
	$(CC) -c $(CCFLAGS) textCanvas.cc

Person.o: Person.cc person.h date.h place.h
	$(CC) -c $(CCFLAGS) Person.cc

Date.o: Date.cc date.h textCanvas.h
	$(CC) -c $(CCFLAGS) Date.cc

Name.o: Name.cc name.h textCanvas.h
	$(CC) -c $(CCFLAGS) Name.cc

Place.o: Place.cc place.h textCanvas.h
	$(CC) -c $(CCFLAGS) Place.cc

assign6.o : assign6.cc textCanvas.h person.h date.h  name.h place.h
	$(CC) -c $(CCFLAGS) -std=c++11  assign6.cc 

clean : 
	-rm *.o assign6
