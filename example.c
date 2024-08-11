#include <stdio.h>
#include "cga.h"

// Define the cost function
// The cost function is the sum of the elements of the chromosome
// The goal is to maximize the number of ones in the chromosome
// So, onemax([1, 1, 0, 1, 0], 5) = 3
// and onemax([0, 0, 0, 0, 0], 5) = 0
// It's maximized when all elements are 1:
// onemax([1, 1, 1, 1, 1], 5) = 5
double onemax(int *x, int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += x[i];
    }
    return -sum;
}

#define CHSIZE 100

int main()
{
    int result[CHSIZE];
    double pmutation = 0.001;
    int maxiter = 50000;
    cga(CHSIZE, onemax, pmutation, result, maxiter);
    for (int i = 0; i < CHSIZE; ++i)
    {
        printf("%d ", result[i]);
    }
    return 0;
}