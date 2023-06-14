#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 3000

int numbers[MAX_NUMBERS];

void *LinearSearch(void *arg)
{
    int search_element = *(int*)arg;
    clock_t start_time = clock();
    int i;
    for (i = 0; i < MAX_NUMBERS; i++) {
        if (numbers[i] == search_element) {
            printf("Linear search found the element %d at index %d.\n", search_element, i);
            break;
        }
    }
    if (i == MAX_NUMBERS) {
        printf("Linear search could not find the element %d in the array.\n", search_element);
    }
    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Time taken for linear search: %lf seconds.\n", elapsed_time);
    return NULL;
}

void *BinarySearch(void *arg)
{
    int search_element = *(int*)arg;
    clock_t start_time = clock();
    int left = 0, right = MAX_NUMBERS - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (numbers[mid] == search_element) {
            printf("Binary search found the element %d at index %d.\n", search_element, mid);
            break;
        }
        else if (numbers[mid] < search_element) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    if (left > right) {
        printf("Binary search could not find the element %d in the array.\n", search_element);
    }
    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Time taken for binary search: %lf seconds.\n", elapsed_time);
    return NULL;
}

int main(int argc, char** argv)
{
    int search_element = 50;
    srand(time(NULL));
    int i;
    for (i = 0; i < MAX_NUMBERS; i++) {
        numbers[i] = rand() % 100;
    }
    printf("Inside main thread before computation\n");
    // Linear search
    printf("Performing linear search for element %d in the array...\n", search_element);
    pthread_t tid_linear;
    pthread_create(&tid_linear, NULL, LinearSearch, &search_element);
    pthread_join(tid_linear, NULL);

    // Binary search
    printf("Performing binary search for element %d in the array...\n", search_element);
    pthread_t tid_binary;
    pthread_create(&tid_binary, NULL, BinarySearch, &search_element);
    pthread_join(tid_binary, NULL);

    return 0;
}


// The above code performs a linear and binary search of the element 50 in an array of 3000 random integers. It measures the time taken for the search and displays the result. It also creates two threads for performing the search and uses the pthread_create, pthread_join, and pthread_cancel functions.

//In the main function, we first initialize the random array of integers. Then, we create two threads for performing the linear and binary search using the pthread_create function. We pass the search element 50 as an argument to the thread functions using the &search_element

