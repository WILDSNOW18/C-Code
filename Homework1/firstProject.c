
#include <stdio.h>
double calc_F (double c);
int main()
{
    printf("Hello world.\n\n");

   double cel = calc_F(100);
    printf("Temperature in Fahrenheit: %.2f\n", cel);
    int age = -6;
    if (age)
    {
        printf ("You are born\n");
    }

    /*
    block of comments

    < less than
    > greater than
     <= less than or equal to
     >= greater than or equal to
     == equal to
     != not equal to

    */
    // line of coments
    return 0;
}

double calc_F (double c)
{
    double f = (c * 9.0/5.0) + 32.0;
    return f;
}