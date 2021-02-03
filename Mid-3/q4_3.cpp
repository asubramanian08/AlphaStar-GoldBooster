#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <set>
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
unsigned int lowestX = ~((unsigned int)0), highestX = 0,
             lowestY = ~((unsigned int)0), highestY = 0;
set<pair<pair<unsigned int, unsigned int>, bool>> grid;

unsigned int floodfill(unsigned int x, unsigned int y)
{
    if (grid.find(make_pair(make_pair(x, y), false)) == grid.end())
    {
        grid.erase(make_pair(make_pair(x, y), false));
        grid.insert(make_pair(make_pair(x, y), true));
        return 1;
    }
    if (grid.find(make_pair(make_pair(x, y), true)) == grid.end())
        return 0;
    grid.insert(make_pair(make_pair(x, y), true));
    unsigned int total = 0;
    if (x > lowestX)
        total += floodfill(x - 1, y);
    if (x + 1 < highestX)
        total += floodfill(x + 1, y);
    if (y > lowestY)
        total += floodfill(x, y - 1);
    if (y + 1 < highestY)
        total += floodfill(x, y + 1);
    return total;
}
int main(void)
{
    unsigned int numOfBales = getNum(), bx, by;
    for (unsigned int i = 0; i < numOfBales; i++)
    {
        bx = getNum();
        by = getNum();
        if (bx < lowestX)
            lowestX = bx;
        if (bx > highestX)
            highestX = bx;
        if (by < lowestY)
            lowestY = by;
        if (by > highestY)
            highestY = by;
        grid.insert(make_pair(make_pair(bx, by), false));
    }
    lowestX--;
    lowestY--;
    highestX++;
    highestY++;
    printf("%d", floodfill(highestX, highestY));
}