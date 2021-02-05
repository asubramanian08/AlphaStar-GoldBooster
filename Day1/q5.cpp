#include <stdio.h>
#include <stdlib.h>
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
unsigned long long getNum()
{
    unsigned long long total = 0;
    char ch;
    while (((ch = getchar()) != ' ') && (ch != '\n'))
        total = (total * 10) + (ch - '0');
    return total;
}

int main(void)
{
    unsigned int numOfTiles = getNum();
    unsigned int corrSize = getNum();
    unsigned int *tiles = (unsigned int *)malloc(sizeof(unsigned int) * numOfTiles);
    unsigned int **costs = (unsigned int **)malloc(sizeof(unsigned int *) * numOfTiles);
    for (unsigned int i = 0; i < numOfTiles; i++)
    {
        costs[i] = (unsigned int *)malloc(sizeof(unsigned int) * corrSize);
        tiles[i] = getNum();
    }
    costs[0][0] = 0;
    return 0;
}