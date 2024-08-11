#include "cga.h"

void create_probvector(int chsize, double *probvector)
{
    for (int i = 0; i < chsize; ++i)
    {
        probvector[i] = 0.5;
    }
}

void sample(double *probvector, int *result, int n)
{
    for (int i = 0; i < n; ++i)
    {
        double r = (double)rand() / RAND_MAX;
        if (r < probvector[i])
        {
            result[i] = 1;
        }
        else
        {
            result[i] = 0;
        }
    }
}

int is_converged(double *probvector, int chsize, double pmutation)
{
    int sum = 0;
    for (int i = 0; i < chsize; ++i)
    {
        if (probvector[i] + pmutation >= 1 || probvector[i] - pmutation <= 0)
        {
            sum += 1;
        }
    }
    return sum == chsize;
}

void cga(int chsize, costfunction fn, double pmutation, int *result, int maxiter)
{

    double *probvector = (double *)malloc(chsize * sizeof(double));
    int *parent1 = (int *)malloc(chsize * sizeof(int));
    int *parent2 = (int *)malloc(chsize * sizeof(int));
    int *winner;
    int *loser;

    create_probvector(chsize, probvector);

    int iter = 0;

    while (iter < maxiter)
    {
        iter++;
        sample(probvector, parent1, chsize);
        sample(probvector, parent2, chsize);
        double cost1 = fn(parent1, chsize);
        double cost2 = fn(parent2, chsize);
        if (cost1 < cost2)
        {
            winner = parent1;
            loser = parent2;
        }
        else
        {
            winner = parent2;
            loser = parent1;
        }
        for (int i = 0; i < chsize; ++i)
        {
            if (winner[i] != loser[i])
            {
                if (winner[i] == 1)
                {
                    probvector[i] += pmutation;
                }
                else
                {
                    probvector[i] -= pmutation;
                }
            }
        }
        if (is_converged(probvector, chsize, pmutation))
        {
            break;
        }
    }
    sample(probvector, result, chsize);
    free(probvector);
    free(parent1);
    free(parent2);
}
