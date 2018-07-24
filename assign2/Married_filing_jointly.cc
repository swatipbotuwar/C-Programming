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
    of a given income for Married Filing Jointly status category.
*/


float Married_filing_jointly( float income)
{
    float tax;
    if( income >= 0 && income < 18550)
	{
	    tax = 0.1 * income ;
	}
    else if (income >= 18550 && income < 75300 )
	{
	    tax = 1855.00 + 0.15 * (income - 18550);
	}
    else if (income >= 75300 && income < 151900)
	{
	    tax = 10367.50 + 0.25 * (income - 75300);
	}
    else if (income >= 151900 && income < 231450)
	{
	    tax = 29517.50 + 0.28 * (income - 151900);
	}
    else if(income >= 231450 && income < 413350)
	{
	    tax = 51791.50 + 0.33 * (income - 231450);
	}
    else if( income >= 413350 && income < 466950)
	{
	    tax = 111818.50 + 0.35 * (income - 413350);
	}
    else if (income >= 466950)
	{
	    tax = 130578.50 + 0.396 * (income - 466950);
	}
    return tax ;

}
    
