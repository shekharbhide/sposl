#include <stdio.h>

int main()
{
    int i, j, n, ref_str[50], frame[10], no, k, avail, fcount = 0;

    printf("Enter the number of pages: ");
    scanf("%d", &n);

    printf("Enter the page numbers: ");
    for (i = 1; i <= n; i++)
        scanf("%d", &ref_str[i]);

    printf("Enter the number of frames: ");
    scanf("%d", &no);

    for (i = 0; i < no; i++)
        frame[i] = -1;

    j = 0;

    printf("\nRef String\tPage Frames\tHit/Fault\n");
    for (i = 1; i <= n; i++)
    {
        printf("%d\t\t", ref_str[i]);

        avail = 0;
        for (k = 0; k < no; k++)
        {
            if (frame[k] == ref_str[i])
            {
                avail = 1;
                break;
            }
        }

        if (avail == 1)
        {
            for (k = 0; k < no; k++)
                printf("%d\t", frame[k]);
            printf("\t\tH");
        }
        else
        {
            frame[j] = ref_str[i];
            j = (j + 1) % no;
            fcount++;

            for (k = 0; k < no; k++)
                printf("%d\t", frame[k]);
            printf("\t\tF");
        }

        printf("\n");
    }

    printf("Page Faults: %d\n", fcount);

    return 0;
}
