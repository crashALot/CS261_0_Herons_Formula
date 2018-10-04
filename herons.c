/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        10/01/2018
** Description: This program finds the area of a triangle with all its
*               three sides given as a,b and c. It uses Heron's formula 
*               to calculate the area of the triangle.
*********************************************************************/

#include <stdio.h>
#include <stdlib.h> // Used for struct triangle
#include <math.h>   // Used for sqrt function

struct triangle
{
    double side1;
    double side2;
    double side3;
    double area;
};

// Function prototypes below
void solveSemiperimeter(struct triangle* userTriangle);
void solveArea(double semiPerimeter, struct triangle* userTriangle); 

int main()
{
	int userIn; // Menu selection value
    
    // Introduction menu
    printf("\n  *********** Welcome to the wonderful world of Heron's Triangle! ***********\n\n");
    printf("  This program will solve the area of a triangle given user specified inputs.\n\n");
    printf("  Would you like to: \n");
    printf("     1. Solve for the area of a triangle \n");
    printf("       2. Exit program \n");
    printf("  -> ");
    scanf("%d", &userIn); // Store user input
    
    // Determine program action based on user input
    switch (userIn)
    {
        // Start program
        case 1:
        printf("\n  *** Please enter each side of your triangle as a positive integer. Remember the triangle inequality theorem!\n\n");
        struct triangle userTriangle;
        solveSemiperimeter(&userTriangle);
        printf("\n  -- Your triangle's Area is: %.2lf ", userTriangle.area);
        printf("\n\n");
        break;
        
        // End program
        case 2:
        printf("  See you again soon!\n\n");
        break;
    }
	return 0;
}

/********************************************************************* 
** Description: void solveSemiperimeter(struct triangle *userTriangle)
*               This function prompts the user for the sides of a 
*               triangle and calaculates the triangle's 
*               semiperimeter. The original triangle struct is passed
*               by reference to access its individual components
*********************************************************************/
void solveSemiperimeter(struct triangle *userTriangle)
{
    double semiPerimeter;
    
    printf("  Enter the value for side 1\n");
    printf("  -> ");
    scanf("%lf", &userTriangle->side1);
    
    printf("\n  Enter the value for side 2\n");
    printf("  -> ");
    scanf("%lf", &userTriangle->side2);
    
    printf("\n  Enter the value for side 3\n");
    printf("  -> ");
    scanf("%lf", &userTriangle->side3);
    
    semiPerimeter=((userTriangle->side1)+(userTriangle->side2)+(userTriangle->side3))/(double)2;
    printf("\n  -- Semiperimeter is %.2lf\n", semiPerimeter);
    solveArea(semiPerimeter, userTriangle); // Calls next function to solve for triangle area
}

/********************************************************************* 
** Description: void solveArea(double semiPerimeter, struct triangle* userTriangle)
*               Solves for triangle area given triangle semiperimeter
*               and triangle struct as parameters.
*********************************************************************/
void solveArea(double semiPerimeter, struct triangle* userTriangle)
{
    double magnitude;
    magnitude=(semiPerimeter*(semiPerimeter-userTriangle->side1)*(semiPerimeter-userTriangle->side2)*(semiPerimeter-userTriangle->side3));
    userTriangle->area=sqrt(magnitude);
}
