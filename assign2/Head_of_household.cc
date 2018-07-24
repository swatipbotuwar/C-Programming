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
    of a given income for  Head Of Household  category.
*/


float Head_of_household(float income)
{
    float tax;
    if(income >= 0 &&  income < 13250)
        {
	    tax = 0.1 * income;
	}
    else if(income >= 13250 && income < 50400)
	{
	    tax = 1325.00 + 0.15 * (income - 13250);
	}
    else if(income >= 50400 && income < 130150)
	{
	    tax = 6897.50 + 0.25 * (income - 50400);
	}
    else if(income >= 130150 && income < 210800)
	{
	    tax = 26835.00 + 0.28 * (income - 130150);
	}
    else if(income >= 210800 && income < 413350)
	{
	    tax = 49417.00 + 0.33 * ( income - 210800);
	}
    else if(income >= 413350 &&  income < 441000)
	{
	    tax = 116258.50 + 0.35 * (income - 413350);
	}
    else if( income >= 441000)
	{
	    tax = 125936.00 + 0.396 * (income - 441000);
	}
    return tax;
}
