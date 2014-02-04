/****************************/
/**Ryan Evenstad Homework 1**/
/****************************/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    float r=.25, B=2000.0, P, interest, total_interest=0.0, prev_interest;
    int n=1;

    printf("Enter monthly payment: ");
    scanf("%f", &P);

    while(B >= 0)
    {
        if (n == 1)
        {
            interest=(r/12)*B;
	    printf("%d %.2f %.2f\n", n, interest, B);
	    total_interest=total_interest+interest;
        }
        else
        {
	    prev_interest=interest;
            interest=(r/12)*(B-P+interest);
	    B=B-P+prev_interest;
            printf("%d %.2f %.2f\n", n, interest, B);
	    if (interest>0)
	    {
		total_interest=total_interest+interest;
	    }
        }
        n++;
    }
    printf("\nTotal Interest Paid: %.2f\n", total_interest);
    return 0;
}
