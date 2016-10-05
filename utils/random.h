#include<cstdlib>
#include<ctime>

int random()
{
    srand(time(0));
    int i = rand() % 15 + 1;

    return i;
}
