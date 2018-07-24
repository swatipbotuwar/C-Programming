###############################################
# NAME : SWATI BOTUWAR                        #
# Z-ID : Z1828087			      #
# CSCI/689/Section 1			      #
# TA NAME : NITHIN DEVANG                     #
# ASSIGNMENT NUMBER : 2                       #
# DUE DATE : WEDNESDAY , 8th FEBRUARY  2017   #
###############################################


#    Defining make file variables.
 
    
CC = g++
CCFLAGS = -Wall -Werror


#    Makefile rules start here


assign2 : assign2.o single.o Married_filing_jointly.o Maried_filing_seperately.o Head_of_household.o
	$(CC) -o assign2  $(CCFLAGS) assign2.o single.o Married_filing_jointly.o Maried_filing_seperately.o Head_of_household.o -lm 

single.o : single.cc tax_calculator.h
	$(CC) -c $(CCFLAGS) single.cc

Married_filing_jointly.o : Married_filing_jointly.cc tax_calculator.h
	$(CC) -c $(CCFLAGS) Married_filing_jointly.cc

Maried_filing_seperately.o : Maried_filing_seperately.cc tax_calculator.h
	$(CC) -c $(CCFLAGS) Maried_filing_seperately.cc

Head_of_household.o : Head_of_household.cc tax_calculator.h
	$(CC) -c $(CCFLAGS) Head_of_household.cc

assign2.o : assign2.cc tax_calculator.h
	$(CC) -c $(CCFLAGS) assign2.cc

clean : 
	-rm *.o assign2
