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
struct stack
{
    unsigned int conn;
    unsigned int order;
    bool is_true;
    stack *next;
};
struct cow
{
    stack *conns;
    unsigned int group;
    bool honesty;
    bool vis;
};
unsigned int numOfCows;
cow *cows;
bool floodFill(unsigned int cow, bool honesty, unsigned int group)
{
    if ((cows[cow].vis) && (cows[cow].group == group))
        return cows[cow].honesty == honesty;
    cows[cow].vis = true;
    cows[cow].honesty = honesty;
    cows[cow].group = group;
    stack *conn = cows[cow].conns;
    /* while (conn)
    {
        if (floodFill(conn.conn))
    }*/
}
bool iscorrect(unsigned int questions)
{

    for (unsigned int i = 0; i < numOfCows; i++)
    {
        cows[i].honesty = true;
        cows[i].group = i;
        cows[i].vis = false;
    }
    for (unsigned int i = 0; i < numOfCows; i++)
    {
        if (!cows[i].vis && floodFill(i, true, i))
            return false;
    }
}
int main(void)
{
    numOfCows = getNum();
    unsigned int statements = getNum();
    cows = (cow *)malloc(sizeof(cow) * numOfCows);
    for (unsigned int i = 0; i < numOfCows; i++)
        cows[i].conns = NULL;
    stack *temp;
    unsigned int c1;
    for (unsigned int i = 0; i < statements; i++)
    {
        c1 = getNum();
        temp = (stack *)malloc(sizeof(stack));
        temp->next = cows[c1].conns;
        cows[c1].conns = temp;
        temp->conn = getNum();
        temp->is_true = getchar() == 'T';
        temp->order = i;
    }

    unsigned int min = 0, max = statements - 1;
    while (min - max > 1)
    {
    }
    return 0;
}