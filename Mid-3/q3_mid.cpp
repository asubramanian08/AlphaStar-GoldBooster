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

unsigned int *bTree;
unsigned int elements;
void init(unsigned int elem)
{
    elements = elem;
    bTree = (unsigned int *)calloc(elem, sizeof(unsigned int));
}
/*BIT(unsigned int elem, unsigned int *initialize, unsigned int numInit)
    {
        elements = elem;
        bTree = (unsigned int *)malloc(sizeof(unsigned int) * elem);
        for (unsigned int i = 0; i < numInit; i++)
            updt(i, initialize[i]);
    }*/
unsigned int query(unsigned int node)
{
    unsigned int sum = 0;
    for (unsigned int i = node - 1; i >= 0; i -= (i & -i))
        sum += bTree[i];
    return sum;
}
void updt(unsigned int node, unsigned int val)
{
    for (unsigned int i = node - 1; i < elements; i += (i & -i))
        bTree[i] += val;
}

int compareFunc(const void *p1, const void *p2)
{
    return *((unsigned int *)p2) - *((unsigned int *)p1);
}
struct ele
{
    double distRun;
    unsigned int byDec;
    double remainder;
    unsigned int orgLoc;
};
int compareFuncRev(const void *p1, const void *p2)
{
    return ((ele *)p2)->remainder - ((ele *)p1)->remainder;
}
int compareFuncOrg(const void *p1, const void *p2)
{
    return ((ele *)p1)->orgLoc - ((ele *)p2)->orgLoc;
}
unsigned int numOfCows;
double *preSum;
unsigned int passes(unsigned int cow, unsigned int lenght)
{
    if (preSum[numOfCows - 1] - preSum[cow] < lenght)
        return 0;
    unsigned int min = cow;
    unsigned int max = numOfCows - 1;
    while (max - min > 1)
    {
        if (preSum[(max + min) / 2] - preSum[cow] < lenght)
            min = (max + min) / 2;
        else
            max = (max + min) / 2;
    }
    return numOfCows - max;
}

int main(void)
{
    numOfCows = getNum();
    unsigned int laps = getNum();
    double lenght = getNum();
    unsigned int *cowSpeed = (unsigned int *)malloc(sizeof(unsigned int) * numOfCows);
    for (unsigned int i = 0; i < numOfCows; i++)
        cowSpeed[i] = getNum();
    qsort(cowSpeed, numOfCows, sizeof(unsigned int), compareFunc);
    double mult = (double)laps * (double)lenght / (double)cowSpeed[0];
    ele *finish = (ele *)malloc(sizeof(ele) * numOfCows);
    for (unsigned int i = 0; i < numOfCows; i++)
        finish[i].distRun = mult * (double)cowSpeed[i];
    unsigned int ans = 0, sumSoFar = finish[0].distRun / lenght;
    for (unsigned int i = 1; i < numOfCows; i++)
    {
        ans += ((finish[i].distRun / lenght) * i) - sumSoFar;
        sumSoFar += finish[i].distRun / lenght;
        finish[i].orgLoc = i;
    }
    finish[0].orgLoc = 0;
    for (unsigned int i = 0; i < numOfCows; i++)
        finish[i].remainder = (finish[i].distRun / lenght) - (unsigned int)(finish[i].distRun / lenght);
    qsort(finish, numOfCows, sizeof(ele), compareFuncRev);
    for (unsigned int i = 0; i < numOfCows; i++)
        finish[i].byDec = i;
    qsort(finish, numOfCows, sizeof(ele), compareFuncOrg);
    init(numOfCows);
    for (unsigned int i = 0; i < numOfCows; i++)
    {
        ans -= query(finish[i].byDec);
        updt(finish[i].byDec, 1);
    }
    /*preSum = (double *)malloc(sizeof(double) * numOfCows);
    preSum[0] = 0;
    for (unsigned int i = 1; i < numOfCows; i++)
        preSum[i] = preSum[i - 1] + (finish[i - 1] - finish[i]);
    unsigned int ans = 0, curr;
    for (unsigned int i = 0; i < numOfCows; i++)
        for (unsigned int j = 1; (curr = passes(i, lenght * j)) != 0; j++)
            ans += curr;*/
    /*unsigned int ans = 0;
    for (unsigned int i = 0; i < numOfCows; i++)
        for (unsigned int j = i + 1; j < numOfCows; j++)
            ans += abs((finish[i] - finish[j]) / lenght);*/
    printf("%d", ans);
    return 0;
}