#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void sstf(int Array[], int header, int n);
void scan(int Array[], int header, int n , int lb, int ub);
void cscan(int Array[], int header, int n , int lb, int ub);
void clook(int Array[], int header, int n);

int main()
{
    int array[200], n, header;
    printf("Enter the total number of requests:\n");
    scanf("%d", &n);
    printf("Enter the array of requests:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    printf("Enter the header:\n");
    scanf("%d", &header);

    int choice;
    do
    {
        printf("\nPlease select a disk scheduling algorithm:\n");
        printf("1. SSTF\n");
        printf("2. SCAN\n");
        printf("3. C-SCAN\n");
        printf("4. C-LOOK\n");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("SSTF Ordering:\n");
                sstf(array, header, n);
                break;
            case 2:
                printf("Enter the range of cylinders:\n");
                int lb,ub;
                scanf("%d %d",&lb, &ub);
                printf("SCAN Ordering:\n");
                scan(array, header, n, lb, ub);
                break;
            case 3:
                printf("Enter the range of cylinders:\n");
                scanf("%d %d",&lb, &ub);
                printf("C-SCAN Ordering:\n");
                cscan(array, header, n, lb, ub);
                break;
            case 4:
                printf("C-LOOK Ordering:\n");
                clook(array, header, n);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    } while (choice != 5);

    return 0;
}

void sstf(int Array[], int header, int n)
{
    printf("%d->",header );
    long mvmt=0;
    int temp[n];
    for (int i=0;i<n;i++)
    {
        temp[i] = Array[i];
    }

    for (int i=0;i<n;i++)
    {
        int min_distance = INT_MAX;
        int index = -1;
        for (int j=0;j<n;j++)
        {
            if(temp[j]!=-1)
            {
                int distance = abs(header-temp[j]);
                if(distance<min_distance)
                {
                    min_distance = distance;
                    index = j;
                }
            }
        }
        printf("%d->", temp[index]);
        mvmt+=abs(temp[index]-header);
        header=temp[index];
        temp[index]=-1;
    }
    printf("\nTotal movement of header: %ld\n",mvmt);
}

void scan(int Array[], int header, int n , int lb, int ub)
{
    printf("%d->",header );
    long mvmt=0;
    int temp[n+2],pos[n+2];
    for (int i=0;i<n;i++)
    {
        temp[i] = Array[i];
    }
    temp[n]=lb;
    temp[n+1]=ub;

    for (int i=0;i<n+2;i++)
    {
        pos[i]=i;
    }

    for (int i=0;i<n+1;i++)
    {
        for (int j=0;j<n-i-1;j++)
        {
            if(temp[j]>temp[j+1])
            {
                int temp_val=temp[j];
                temp[j]=temp[j+1];
                temp[j+1]=temp_val;

                int temp_pos=pos[j];
                pos[j]=pos[j+1];
                pos[j+1]=temp_pos;
            }
        }
    }

    int index = 0;
    for (int i=0;i<n+2;i++)
    {
        if(temp[i]==header)
        {
            index=i;
            break;
        }
    }

    for (int i=index;i<n+2;i++)
    {
        printf("%d->",temp[i]);
        mvmt+=abs(header-temp[i]);
        header=temp[i];
    }
    printf("%d->",ub);
    mvmt+=abs(header-ub);
    header=ub;

    for (int i=n+1;i>=0;i--)
    {
        if(i==index)
    {
    break;
    }
    printf("%d->",temp[i]);
    mvmt+=abs(header-temp[i]);
    header=temp[i];
    }
    printf("%d->",lb);
    mvmt+=abs(header-lb);

    printf("\nTotal movement of header: %ld\n",mvmt);

    }

    void cscan(int Array[], int header, int n , int lb, int ub)
    {
    printf("%d->",header );
    long mvmt=0;
    int temp[n+2],pos[n+2];
    for (int i=0;i<n;i++)
    {
    temp[i] = Array[i];
    }
    temp[n]=lb;
    temp[n+1]=ub;

    for (int i=0;i<n+2;i++)
    {
        pos[i]=i;
    }

    for (int i=0;i<n+1;i++)
    {
        for (int j=0;j<n-i-1;j++)
        {
            if(temp[j]>temp[j+1])
            {
                int temp_val=temp[j];
                temp[j]=temp[j+1];
                temp[j+1]=temp_val;

                int temp_pos=pos[j];
                pos[j]=pos[j+1];
                pos[j+1]=temp_pos;
            }
        }
    }

    int index = 0;
    for (int i=0;i<n+2;i++)
    {
        if(temp[i]==header)
        {
            index=i;
            break;
        }
    }

    for (int i=index;i<n+2;i++)
    {
        printf("%d->",temp[i]);
        mvmt+=abs(header-temp[i]);
        header=temp[i];
    }
    printf("%d->%d->",ub,lb);
    mvmt+=ub-lb;

    for (int i=0;i<index;i++)
    {
        printf("%d->",temp[i]);
        mvmt+=abs(header-temp[i]);
        header=temp[i];
    }

    printf("\nTotal movement of header: %ld\n",mvmt);

    }

    void clook(int Array[], int header, int n)
    {
    printf("%d->",header );
    long mvmt=0;
    int temp[n];
    for (int i=0;i<n;i++)
    {
    temp[i] = Array[i];
    }

    for (int i=0;i<n-1;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            if(temp[i]>temp[j])
            {
                int temp_val=temp[i];
                temp[i]=temp[j];
                temp[j]=temp_val;
            }
        }
    }

    int index = 0;
    for (int i=0;i<n;i++)
    {
        if(temp[i]>=header)
        {
            index=i;
            break;
        }
    }
//continuerbwmerwkqjfrkhwq
    for (int i=index;i<n;i++)
    {
        printf("%d->",temp[i]);
        mvmt+=abs(header-temp[i]);
        header=temp[i];
    }

    for (int i=0;i<index;i++)
    {
        printf("%d->",temp[i]);
        mvmt+=abs(header-temp[i]);
        header=temp[i];
    }

    printf("\nTotal movement of header: %ld\n",mvmt);

}

/*
Enter the total number of requests:
8
Enter the array of requests:
98 183 37 122 14 124 65 67
Enter the header:
53

Please select a disk scheduling algorithm:
1. SSTF
2. SCAN
3. C-SCAN
4. C-LOOK
5. Exit
Choice: 1
SSTF Ordering:
53->65->67->37->14->98->122->124->183->
Total movement of header: 236

Please select a disk scheduling algorithm:
1. SSTF
2. SCAN
3. C-SCAN
4. C-LOOK
5. Exit
Choice: 2
Enter the range of cylinders:
0 199
SCAN Ordering:
53->65->67->98->122->124->183->199->185->124->122->98->67->65->37->14->
Total movement of header: 1155

Please select a disk scheduling algorithm:
1. SSTF
2. SCAN
3. C-SCAN
4. C-LOOK
5. Exit
Choice: 3
Enter the range of cylinders:
0 199
C-SCAN Ordering:
53->65->67->98->122->124->183->199->0->14->37->50->185->
Total movement of header: 783

Please select a disk scheduling algorithm:
1. SSTF
2. SCAN
3. C-SCAN
4. C-LOOK
5. Exit
Choice: 4
C-LOOK Ordering:
53->65->67->98->122->124->185->14->37->
Total movement of header: 322

Please select a disk scheduling algorithm:
1. SSTF
2. SCAN
3. C-SCAN
4. C-LOOK
5. Exit
Choice: 5
Exiting...
*/
