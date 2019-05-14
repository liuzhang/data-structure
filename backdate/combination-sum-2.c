#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//int candidates[] = {10,1,2,7,6,1,5};
int candidates[] = {1,1,2,5,6,7,10};
int result[] = {0, 0, 0, 0, 0, 0, 0};
int target = 8;

int sum(int a[]) {

    int total = 0, i;
    for (i = 0; i < 7; ++i)
    {
        total += a[i];
    }

    return total;
}


void printResult(int a[]) {
    int i;

    for (i = 0; i < 7; ++i)
    {
        if (a[i]) {
            printf("%d ", a[i]);
        }
    }
    printf("----------------------------------------------\n");
}


void backTrack(int i) {

    if (i == 7) return;

    if ((sum(result) + candidates[i]) < target) {
         result[i] = candidates[i];
        backTrack(i+1);
    } else if ((sum(result) + candidates[i]) == target) {
        printf("i is %d\n", i);
         result[i] = candidates[i];
         printResult(result);
    }

    result[i] = 0;
    backTrack(i+1);
    return;
}


int main(int argc, char const *argv[])
{
    backTrack(0);
    return 0;
}