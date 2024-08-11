#ifndef CGA_H
#define CGA_H

#include <stdlib.h>

/*
Define the cost function
The cost function is assumed to be a minimization problem
The cost function should return a double
int *x is the value of the chromosome, a.k.a, a candidate solution
int n is the size of the chromosome, aka, the number of genes or variables
*/
typedef double (*costfunction)(int *x, int n);

/*
Create a probability vector with all elements set to 0.5
chsize is the size of the chromosome
*probvector is a in/out parameter, it should be allocated before calling this function
*/
void create_probvector(int chsize, double *probvector);

/*
Sample a 0/1 vector from a probability vector
probvector is the probability vector
result is the output vector, it should be allocated before calling this function
n is the size of the chromosome
*/
void sample(double *probvector, int *result, int n);

/*
if all elements of probvector are close to 0 or 1, return 1, otherwise return 0
*/
int is_converged(double *probvector, int chsize, double pmutation);

/*
The compact genetic algorithm
chsize is the size of the chromosome
fn is the cost function
pmutation is the mutation probability
result is the output vector, it should be allocated before calling this function
maxiter is the maximum number of iterations
*/
void cga(int chsize, costfunction fn, double pmutation, int *result, int maxiter);

#endif