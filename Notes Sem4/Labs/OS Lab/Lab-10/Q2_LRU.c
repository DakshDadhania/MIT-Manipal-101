#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Modules independent of Algorithm
int j;

int positionsAreEmpty(int arr[], int frame)
{
    int ret=0;
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

void printDist(int arr[], int frame)
{
    printf("Frame Table\n");
    for (int i = 0; i < frame; i++)
    {
        printf("%d ", arr[i]);
    }
}

int hit(int page, int arr[], int size)
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

void append(int arr[], int frame, int value)
{
    arr[j] = value;
    j = (j + 1) % frame;
}

//
// LRU Page Replacement
//

int getOccurrence(int page, int str[], int lstr, int position)
{
    for (int i = position; i >= 0; i--)
    {
        if (str[i] == page)
        {
            return i;
        }
    }
    return -1;
}

int getRevDistance(int dist[], int arr[], int str[], int lstr, int frame, int position)
{
    for (int i = 0; i < frame; i++)
    {
        dist[i] = abs(getOccurrence(arr[i], str, lstr, position) - position);
    }
}

int getMinPos(int arr[], int frame)
{
    int min = arr[0], minpos = 0;
    for (int i = 1; i < frame; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            minpos = i;
        }
    }
    return minpos;
}

void lruPageRep(int str[], int lstr, int frame)
{
    int *arr = (int*)malloc(frame * sizeof(int));
    int pf = 0, ph = 0;

    memset(arr, -1, frame * sizeof(int));

    for (int i = 0; i < lstr; i++)
    {
        int temp = hit(str[i], arr, frame);

        if (temp >= 0)
        {
            // Update the element's position in the array
            int page = arr[temp];
            for (int k = temp; k > 0; k--)
            {
                arr[k] = arr[k-1];
            }
            arr[0] = page;

            ph += 1;
        }
        else
        {
            if (positionsAreEmpty(arr, frame))
            {
                append(arr, frame, str[i]);
                pf += 1;
            }
            else
            {
                int dist[frame];
                getRevDistance(dist, arr, str, lstr, frame, i);
                arr[getMinPos(dist, frame)] = str[i];
                pf += 1;
            }
        }
    }

    free(arr);

    printf("\nPage Hits For Least Recently Used Page Replacement Algorithm: %d\n", ph);
    printf("Page Fault For Least Recently Used Page Replacement Algorithm: %d\n", pf);
}

int main()
{
    int lstr, frame;

    printf("Enter the length of the page request string: ");
    scanf("%d", &lstr);

    int *str = (int*)malloc(lstr * sizeof(int));

    printf("Enter the pages requested:\n");
    for (int i = 0; i < lstr; i++)
    {
        scanf("%d", &str[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &frame);

    lruPageRep(str, lstr, frame);

    free(str);

    return 0;
}
/*
Input:

Enter the length of the page request string: 20
Enter the pages requested:
1
2
3
4
5
6
7
8
9
10
1
2
3
4
5
6
7
8
9
10
Enter the number of frames: 3

Output:

Page Hits For Least Recently Used Page Replacement Algorithm: 3
Page Fault For Least Recently Used Page Replacement Algorithm: 17

*/
