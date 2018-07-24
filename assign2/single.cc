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
    of a given income for Single status category.
*/ 

float single (float income)
{
        float tax ;
        if (income >= 0.0 && income <9275)
	    {
 	        tax = 0.1 * income ;
	    }
        else if (income >= 9275.00 && income < 37650.00)
	    {
	        tax = 927.50 + 0.15 * (income - 9275) ;
 	    }
        else if (income >= 37650.00 && income < 91150)
	    {
	        tax = 5183.75 + 0.25 * (income - 37650);
	    }  
        else if (income >=91150 && income < 190150)
	    {
	        tax = 18558.75 + 0.28 * (income - 91150);
	    }   
        else if ( income >=190150 && income < 413350)
	    {
	        tax = 46278.75 + 0.33 * (income -190150);
	    }
        else if (income >= 413350 && income < 415050)
	    {
	        tax = 119934.75 + 0.35 * (income - 413350);
	    }
        else if (income >= 415050 )
	    {
	        tax = 120529.75 +  0.396 * (income - 415050);
	    }

    return tax;
} 
