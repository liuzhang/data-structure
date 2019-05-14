#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int candidates[] = {1,2,3};
int result[] = {0, 0, 0};


void printResult(int a[]) {
    int i;

    printf("[");
    for (i = 0; i < 3; ++i)
    {
        if (a[i]) {
            printf("%d,", a[i]);
        }
    }
    printf("]");
    printf("\n");
}


void backTrack(int i) {

    if (i == 3) {
        printResult(result);
        return;
    }
    result[i] = candidates[i];
    backTrack(i+1);
    result[i] = 0;
    backTrack(i+1);
}


int main(int argc, char const *argv[])
{
    backTrack(0);
    return 0;
}