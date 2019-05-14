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


void backTrack(int i, int total) {
    if (total == target) {
         printResult(result);
         return;
    }

    int j;

    for (j = i; j < 7; ++j)
    {
        if ((total + candidates[j]) > target) break;
        if (j > i && candidates[j] == candidates[j - 1]) continue;
        result[i] = candidates[j];
        backTrack(j + 1, total + candidates[j]);
        result[i]= 0;
    }
}


int main(int argc, char const *argv[])
{
    backTrack(0, 0);
    return 0;
}