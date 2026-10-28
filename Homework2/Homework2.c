#include <math.h>
#include <stdio.h>

double distance (double x1, double y1, double x2, double y2);
int main() {

    //figure out how to do inputs in C

    //Variables and user input
    double x1;
    double y1;
    double x2;
    double y2;

    //asks for the x and y coordinates of the first point
    printf("Enter the x and y coordinates of the first point (x1 y1): ");
    scanf("%lf %lf", &x1, &y1);
    
    //asks for the x and y coordinates for the second point
    printf("Enter the x and y coordinates of the second point (x2 y2): ");
    scanf("%lf %lf", &x2, &y2);

    //runs the method that solves the distance between the two points
    double result = distance(x1, y1, x2, y2);

    //prints the answer the the problem posed
    printf("The distance between the two points is: %lf\n", result);

    return 0;
}

double distance (double x1, double y1, double x2, double y2)
{
    // this calculates the distance between the two points given. First it find the range of the x and y values, squares them both using the pow function, then adds them together before taking the square root using the sqrt function.
    double dist = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    return dist;
}