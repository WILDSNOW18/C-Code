/*
PROJECT PLAN:

1. write methods to calculate the mean, the variance, the standard dev, and the standard error of a data set. 
2. Test the above methods with a data set of 10 numbers and check on TI 84

3. Write a method that simulates a dice roll, by generating a random number betweeen 1 and the max value of the dice

4. Write the main method where you get how many sides the users wants the dice to have, and how many times they want to roll said dice. 
5. write a for loop that runs the roll dice method x times

6. all the print methods should be inside of the calculation methods,so this is the end of the program. 

Take your computer to work and write the code then, it shouldn't be too hard.


Google how to add certain math functions to a C program

DON'T FORGET TO COMMENT CODE!!

*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

//function prototypes
double findSum(int data[], int size);
double findMean(int data[], int size, double sum);
double findVar(int data[], int size, double mean);
double findSTDDEV(int data[], int size, double var);
double findSTDERROR(int data[], int size, double stddev);

int main()
{
    //variables
    int diceSides, numRolls;

    //user questions
    while (1)
    {
        printf("How many sides will your dice have? 1-100: ");
        scanf("%d", &diceSides);
        if (diceSides < 1 || diceSides > 100)
        {
            printf("Please enter a number between 1 and 100.\n");
            continue;
        }
        else
        {
            break;
        }
    }
 
    printf("How many times would you like to roll the dice? ");
    scanf("%d", &numRolls);

    //allocates memory for the array, used VS codes AI for help on this line. 
    int *data = (int *)malloc(numRolls * sizeof(int));
    //builds the array
    for (int i = 0; i < numRolls; i++)
    {
        int roll = (rand() % (diceSides )) +1;
        //printf("Roll %d: %d\n", i + 1, roll);

        data[i] = roll;
    }
    
    //the variables used in the print statements below
    double sum = findSum(data, numRolls);
    double mean = findMean(data, numRolls, sum);
    double variance = findVar(data, numRolls, mean);
    double standDev = findSTDDEV(data, numRolls, variance);
    double standError = findSTDERROR(data, numRolls, standDev);

    //prints out the statistics of the rolls
    printf("\n\nThe average roll value is %.6lf\n", mean);
    printf("The variance of the rolls is %.6lf\n", variance);
    printf("The standard deviation of the rolls is %.6lf\n", standDev);
    printf("The standard error of the rolls is %.6lf\n", standError);

    return 0;
}

//finds the sum of the data set
double findSum(int data[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += data[i];
    }
    return sum;
}

//finds the mean of the data set
double findMean (int data[], int size, double sum)
{
    double mean = sum / size;
    return mean;
}

//finds the variance of the data set
double findVar(int data[], int size, double mean)
{
    double var = 0;
    for (int i = 0; i < size; i++)
    {
        var += pow((data[i] - mean), 2);
    }
    var = var / size;
    return var;

}

//finds the Standard Deviation of the data set
double findSTDDEV(int data[], int size, double var)
{
    double stddev = sqrt(var);
    return stddev;
}

//finds the Standard Error of the data set
double findSTDERROR(int data[], int size, double stddev)
{
    double theSTDERROR = stddev / sqrt(size);
    return theSTDERROR;
}


