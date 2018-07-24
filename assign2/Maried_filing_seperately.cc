/**************************************************************
NAME : SWATI BOTUWAR
Z-ID : Z1828087
CSCI/689/Section 1
TA NAME : NITHIN DEVANG
ASSIGNMENT NUMBER : 2
DUE DATE : WEDNESDAY, 8th FEBRUARY 2017
************************************************************/

/**
    This function contains the formula for calculating tax value
    of a given income for status as Married Filing Seperately.
*/


float Maried_filing_seperately( float income)
{
    float tax;
    if(income >=0 && income < 9275)
        {
	    tax = 0.1 * income ;
	}
    else if(income >=9275 && income < 37650)
	{
	    tax = 927.50 + 0.15 * (income - 9275);
	}
    else if(income >= 37650 && income < 75950)
	{
	    tax = 5183.75 + 0.25 * (income - 37650);
	}
    else if(income >= 75950 && income < 115725)
	{
	    tax = 14758.75 + 0.28 * (income - 75950);
	}
    else if(income >= 115725 && income < 206675)
	{
	    tax = 25895.75 + 0.33 * (income - 115725);
	}
    else if(income >= 206675 && income < 233475)
	{
	    tax = 55909.25 + 0.35 * (income - 206675);
	}
    else if(income >= 233475)
	{
	    tax = 65289.25 + 0.396 * (income - 233475);
	}
    return tax;
}
	  
