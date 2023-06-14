/* 
   NAME: LUNGADEKIRANSANJAY
   ROLL NO.: 39
   PRACTICAL NO.: 06
   TITLE: DEADLOCK PREVENTION ALGORITHM
*/

#include<stdio.h>

int max[10][10], allocation[10][10], need[10][10];
int avail[10];
int np, nr;

void read_matrix(int matrix[10][10]) {
    int i, j;
    for (i = 0; i < np; i++)
        for (j = 0; j < nr; j++)
            scanf("%d", &matrix[i][j]);
}

void display_matrix(int matrix[10][10]) {
    int i, j;
    for (i = 0; i < np; i++) {
        printf("\nP%d", i);
        for (j = 0; j < nr; j++) {
            printf("%d", matrix[i][j]);
        }
    }
}

void calculate_need() {
    int i, j;
    for (i = 0; i < np; i++)
        for (j = 0; j < nr; j++)
            need[i][j] = max[i][j] - allocation[i][j];
}

void banker() {
    int i, j, k = 0, flag;
    int finish[10], safe_seq[10];
    for (i = 0; i < np; i++) {
        finish[i] = 0;
    }
    for (i = 0; i < np; i++) {
        flag = 0;
        if (finish[i] == 0) {
            for (j = 0; j < nr; j++) {
                if (need[i][j] > avail[j]) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                finish[i] = 1;
                safe_seq[k] = i;
                k++;
                for (j = 0; j < nr; j++)
                    avail[j] += allocation[i][j];
                i = -1;
            }
        }
    }
    flag = 0;
    for (i = 0; i < np; i++) {
        if (finish[i] == 0) {
            printf("\nThe system is in a deadlock");
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        printf("\nThe system is in a safe state!\nSafe sequence is ==> ");
        for (i = 0; i < np; i++)
            printf("P%d ", safe_seq[i]);
    }
}

int main() {
    int j;
    {
        printf("\nEnter number of processes: ");
        scanf("%d", &np);
        printf("\nEnter number of resources: ");
        scanf("%d", &nr);

        printf("\nEnter initial allocation matrix: ");
        read_matrix(allocation);

        printf("\nEnter max requirement matrix: ");
        read_matrix(max);

        printf("\nEnter available resources: ");
        for (j = 0; j < nr; j++)
            scanf("%d", &avail[j]);
    }

    {
        printf("\n*********** Entered Data is ***********\n\n");
        printf("\nInitial allocation:\n");
        display_matrix(allocation);

        printf("\n\n\nMaximum Requirement\n");
        display_matrix(max);

        printf("\nAvailable Resources\n");
        for (j = 0; j < nr; j++)
            printf("%d", avail[j]);
    }

    {
        calculate_need();
        printf("\n\n\nNeed is\n");
        display_matrix(need);
    }

    banker();
    printf("\n\n\n");

    return 0;
}

/****************** OUTPUT ****************************
   Enter number of processes: 3
   Enter number of resources: 3

   Enter initial allocation matrix: 
   2 1 3
   4 2 6
   2 5 24

   Enter max requirement matrix: 
   2 1 6
   4 2 1
   2 2 2

   Enter available resources: 
   4 2 1

   *********** Entered Data is ***********

   Initial allocation:
   P0 2 1 3
   P1 4 2 6
   P2 2 5 24

   Maximum Requirement
   P0 2 1 6
   P1 4 2 1
   P2 2 2 2

   Available Resources
   4 2 1

   Need is
   P0 0 0 3
   P1 0 0 -5
   P2 -3 -2 -2

   The system is in a safe state!!
   Safe sequence is ==> P1 P0 P2
*/
