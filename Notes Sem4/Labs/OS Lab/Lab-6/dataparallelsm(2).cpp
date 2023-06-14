//  parallel reduction (can be sum, max, min or any associative operation) pattern using Pthreads
#include <pthread.h>
#include <iostream>
#include <stdlib.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

// used for synchronization
pthread_mutex_t lock;

// global variable visible to all threads
int sum = 0;

// Define the max threads as X per the cores in your system
#define maxThread  2

// Define a large array of random numbers as per the input from user
const int N = 100000000;
int arr[N];

// Function to find the sum of large array with the a thread, pass the min and maximum index so that the thread can handle only that data. Find the local sum and then use pthread_mutex_lock to add it to the global sum variable
void *threadSum(void* arg)
{
    int start = *((int*)arg);
    int end = start + N/maxThread;
    int localSum = 0;
    for (int i = start; i < end; i++) {
        localSum += arr[i];
    }
    pthread_mutex_lock(&lock);
    sum += localSum;
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main()
{
    int i;
    int startIndex[maxThread];

    // Read N (number of elements) and create an array of N random numbers.
    srand(time(NULL));
    for (i = 0; i < N; i++) {
        arr[i] = rand() % 100;
    }

    // Sequential sum calculation
    auto start_time = high_resolution_clock::now();
    for (i = 0; i < N; i++) {
        sum += arr[i];
    }
    auto stop_time = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop_time - start_time);
    cout << "Sequential sum: " << sum << ", Time taken: " << duration.count() << "ms" << endl;

    // Divide the N as per maxThread and create threads with corresponding indices for sum
    sum = 0;
    for (i = 0; i < maxThread; i++) {
        startIndex[i] = i * (N / maxThread);
        pthread_create(&threads[i], NULL, threadSum, (void*)&startIndex[i]);
    }

    // Wait for threads to complete
    for (i = 0; i < maxThread; i++) {
        pthread_join(threads[i], NULL);
    }

    // Display final sum and time taken
    cout << "Parallel sum: " << sum << endl;
    
    return 0;
}


//Note that in the threadSum function, we first calculate the indices that the thread will be working on based on its thread number, then calculate the local sum over that range of indices. We then use a mutex lock to add the local sum to the global sum variable.

//In main, we first generate a large array of random integers and then calculate the sum sequentially to get a baseline. We then create the threads, calculate the sum in parallel, and display the final sum. We also calculate the time taken in both the sequential and parallel cases using the high_resolution_clock from the chrono library
