#include <stdio.h>
#include <stdlib.h>
long long getNum()
{
    long long total = 0;
    char ch;
    while (((ch = getchar()) != ' ') && (ch != '\n'))
        total = (total * 10) + (ch - '0');
}
struct spot
{
    bool is_spot;
    unsigned int stopType;
};

int main(void)
{
    unsigned int rows = getNum();
    unsigned int cols = getNum();
    spot **grid = (spot **)malloc(sizeof(spot *) * rows);
    for (unsigned int i = 0; i < rows; i++)
    {
        grid[i] = (spot *)malloc(sizeof(spot) * cols);
        for (unsigned int j = 0; j < cols; j++)
        {
            grid[i][j].is_spot = (getchar() == 'X');
            grid[i][j].stopType = 0;
        }
        getchar();
    }

    return 0;
}