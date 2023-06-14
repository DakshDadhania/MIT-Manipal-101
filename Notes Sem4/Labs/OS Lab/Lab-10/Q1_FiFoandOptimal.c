#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int j;

int positions_are_empty(int *arr, int frame)
{
    int ret = 0;
    for (int i = 0; i < frame; i++)
    {
        if (arr[i] == -1)
        {
            ret = 1;
            break;
        }
    }
    return ret;
}

void print_dist(int *arr, int frame)
{
    printf("Frame Table\n");
    for (int i = 0; i < frame; i++)
    {
        printf("%d ", arr[i]);
    }
}

int hit(int page, int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == -1)
        {
            continue;
        }
        else if (arr[i] == page)
        {
            return i;
        }
    }
    return -1;
}

void append(int *arr, int frame, int value)
{
    arr[j] = value;
    j = (j + 1) % frame;
}

void fifo_page_rep(int *str, int lstr, int frame)
{
    int *arr = (int *) malloc(frame * sizeof(int));
    memset(arr, -1, frame * sizeof(int));

    int pf = 0, ph = 0;
    for (int i = 0; i < lstr; i++)
    {
        if (hit(str[i], arr, frame) >= 0)
        {
            ph += 1;
        }
        else
        {
            if (positions_are_empty(arr, frame))
            {
                append(arr, frame, str[i]);
                pf += 1;
            }
            else
            {
                append(arr, frame, str[i]);
                pf += 1;
            }
        }
    }

    printf("Page Hits for FIFO Page Replacement Algorithm: %d\n", ph);
    printf("Page Faults for FIFO Page Replacement Algorithm: %d\n", pf);

    free(arr);
}

int get_first_occurrence(int page, int *str, int lstr, int position)
{
    for (int i = position; i < lstr; i++)
    {
        if (str[i] == page)
        {
            return i;
        }
    }
    return lstr;
}

void get_distance(int *dist, int *arr, int *str, int lstr, int frame, int position)
{
    for (int i = 0; i < frame; i++)
    {
        dist[i] = get_first_occurrence(arr[i], str, lstr, position) - position;
    }
}

int get_max_pos(int *arr, int frame)
{
    int max = arr[0], maxpos = 0;
    for (int i = 1; i < frame; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            maxpos = i;
        }
    }
    return maxpos;
}

void optimal_page_rep(int *str, int lstr, int frame)
{
    int *arr = (int *) malloc(frame * sizeof(int));
    memset(arr, -1, frame * sizeof(int));

    int pf = 0, ph = 0;
    for (int i = 0; i < lstr; i++)
    {
        if (hit(str[i], arr, frame) >= 0)
        {
            ph += 1;
        }
        else
        {
            if (positions_are_empty(arr, frame))
            {
                append(arr, frame, str[i]);
                pf += 1;
            }
            else
            {
                int *dist = (int *) malloc(frame * sizeof(int));
                get_distance(dist, arr, str, lstr, frame, i);
                arr[get_max_pos(dist, frame)] = str[i];
                pf += 1;
                free(dist);
            }
        }
    }

    printf("Page Hits for Optimal Page Replacement Algorithm: %d\n", ph);
    printf("Page Faults for Optimal Page Replacement Algorithm: %d\n", pf);

    free(arr);
}

int main()
{
    int lstr, frame;

    printf("Enter the length of the page request string: ");
    scanf("%d", &lstr);

    int *str = (int *) malloc(lstr * sizeof(int));
    printf("Enter the pages requested:\n");
    for (int i = 0; i < lstr; i++)
    {
        scanf("%d", &str[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &frame);

    fifo_page_rep(str, lstr, frame);
    optimal_page_rep(str, lstr, frame);

    free(str);

return 0;
}
/*
Input:

Enter the length of the page request string: 4
Enter the pages requested:
10
30
40
50
Enter the number of frames: 3

Output:

Page Hits for FIFO Page Replacement Algorithm: 0
Page Faults for FIFO Page Replacement Algorithm: 4
Page Hits for Optimal Page Replacement Algorithm: 0
*/
