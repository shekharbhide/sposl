/* 
   NAME: LUNGADEKIRAN
   ROLL NO.: 39
   PRACTICAL NO.: 08
   TITLE: DISK SCHEDULING
*/

#include<stdio.h>
#include<stdlib.h>

int main() {
    int RQ[100], i, n, TotalHeadMoment = 0, initial;

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    printf("Enter the request sequence: \n");
    for (i = 0; i < n; i++) {
        scanf("%d", &RQ[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &initial);

    for (i = 1; i < n; i++) {
        TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);
        initial = RQ[i];
    }

    printf("Total head moment is %d\n", TotalHeadMoment);

    return 0;
}
