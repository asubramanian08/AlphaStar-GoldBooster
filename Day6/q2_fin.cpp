#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
using namespace std;
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
struct stack
{
    unsigned int len;
    unsigned int cap;
    unsigned int toNode;
    stack *next;
};

struct graph
{
    unsigned int length;
    unsigned int minCap_soFar;
    bool beenTo;
    stack *conns;
};

int main(void)
{
    unsigned int numNodes = getNum(), numRoads = getNum(), cows = getNum();
    priority_queue<pair<pair<unsigned int, unsigned int>, pair<unsigned int, unsigned int>>> pque;
    graph *nodes = (graph *)malloc(sizeof(graph) * numNodes);
    for (unsigned int i = 0; i < numNodes; i++)
    {
        nodes[i].conns = NULL;
        nodes[i].length = 0;
        nodes[i].minCap_soFar = 0;
        nodes[i].beenTo = false;
    }
    unsigned int n1, n2, len, cap;
    stack *temp;
    for (unsigned int i = 0; i < numRoads; i++)
    {
        n1 = getNum() - 1;
        n2 = getNum() - 1;
        len = getNum();
        cap = getNum();

        temp = (stack *)malloc(sizeof(stack));
        temp->cap = cap;
        temp->len = len;
        temp->next = nodes[n1].conns;
        temp->toNode = n2;
        nodes[n1].conns = temp;

        temp = (stack *)malloc(sizeof(stack));
        temp->cap = cap;
        temp->len = len;
        temp->next = nodes[n2].conns;
        temp->toNode = n1;
        nodes[n2].conns = temp;
    }
    pque.push(make_pair(make_pair(0, 0), make_pair(0, 0)));
    nodes[0].beenTo = true;
    unsigned int barn = numNodes - 1, currNode;
    while (nodes[barn].beenTo == false)
    {
        currNode = pque.top().first.second;
        if (!nodes[currNode].beenTo)
        {
            /*nodes[currNode].beenTo
                temp = nodes[currNode].conns;
            while (temp)
                if ()
                    temp = temp->next;*/
        }
    }
    return 0;
}