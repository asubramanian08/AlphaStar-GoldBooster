#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
unsigned long long getNum()
{
    unsigned long long total = 0;
    char ch = getchar();
    while ((ch != ' ') && (ch != '\n'))
    {
        total = (total * 10) + (ch - '0');
        ch = getchar();
    }
    return total;
}
int compareFunc(const void *p1, const void *p2)
{
    return *((unsigned int *)p1) - *((unsigned int *)p2);
}
unsigned int convertchar(char ch)
{
    if ((ch <= 'z') && (ch >= 'a'))
        return ch - 'z';
    return ch - 'Z';
}
unsigned int ***dp;
bool **pair;
int main(void)
{
    unsigned int upper = getNum(), lower = getNum(), pairs = getNum();
    dp = (unsigned int ***)malloc(sizeof(unsigned int **) * upper);
    for (unsigned int i = 0; i < upper; i++)
    {
        dp[i] = (unsigned int **)malloc(sizeof(unsigned int *) * lower);
        for (unsigned int j = 0; j < lower; j++)
            dp[i][j] = (unsigned int *)malloc(sizeof(unsigned int) * 52);
    }
    pair = (bool **)malloc(sizeof(bool *) * 52);
    for (unsigned int i = 0; i < 52; i++)
        pair[i] = (bool *)calloc(52, sizeof(bool));
    unsigned int ch1, ch2;
    for (unsigned int i = 0; i < pairs; i++)
    {
        ch1 = convertchar(getchar());
        ch2 = convertchar(getchar());
        pair[ch1][ch2] = true;
    }
    return 0;
}