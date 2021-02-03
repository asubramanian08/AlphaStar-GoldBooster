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
struct book
{
    unsigned int hgt;
    unsigned int wth;
};

int main(void)
{
    unsigned int numOfbooks = getNum();
    unsigned int maxWidth = getNum();
    book *books = (book *)malloc(sizeof(book) * numOfbooks);
    for (unsigned int i = 0; i < numOfbooks; i++)
    {
        books[i].hgt = getNum();
        books[i].wth = getNum();
    }
    unsigned int *preSum = (unsigned int *)malloc(sizeof(unsigned int) * numOfbooks);
    unsigned int sumWidth = 0;
    for (unsigned int i = 0; i < numOfbooks; i++)
    {
        preSum[i] = sumWidth;
        sumWidth += books[i].wth;
    }
    for (unsigned int i = 0; i < numOfbooks; i++)
    {
        for (int k = i; (k >= 0) && (); k--)
    }
}