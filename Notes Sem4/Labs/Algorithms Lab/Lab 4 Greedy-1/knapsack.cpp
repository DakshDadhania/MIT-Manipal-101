#include <iostream>
using namespace std;

// Function to sort items based on profit/weight ratio
void bubbleSort(int weights[], int profits[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            // If the profit/weight ratio of the current item is less than that of the next item
            if((profits[j] / weights[j]) < (profits[j+1] / weights[j+1])) {
                // Swap the items to sort them in descending order of profit/weight ratio
                int tempProfit = profits[j];
                profits[j] = profits[j+1];
                profits[j+1] = tempProfit;

                int tempWeight = weights[j];
                weights[j] = weights[j+1];
                weights[j+1] = tempWeight;
            }
        }
    }
}

// Function to solve 0/1 knapsack problem
int knapsack(int weights[], int profits[], int n, int capacity) {
    int solution = 0;
    bubbleSort(weights, profits, n); // Sort the items based on profit/weight ratio

    // Loop through the items and add them to the knapsack until it is full
    for(int i = 0; i < n; i++) {
        if(weights[i] <= capacity) {
            // If the entire item can fit in the knapsack, add its profit to the solution
            solution += profits[i];
            capacity -= weights[i]; // Reduce the remaining capacity of the knapsack
        } else {
            // If the item cannot fit entirely in the knapsack, add a fraction of it to the solution
            solution += (profits[i] / weights[i]) * capacity;
            break; // Stop adding items to the knapsack since it is full
        }
    }

    return solution; // Return the maximum profit that can be obtained
}

int main() {
    int n, capacity;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    int weights[n], profits[n];
    cout << "Enter the weights and profits of the items:" << endl;
    for(int i = 0; i < n; i++) {
        cin >> weights[i] >> profits[i];
    }

    int maxProfit = knapsack(weights, profits, n, capacity); // Solve the knapsack problem
    cout << "The maximum profit is: " << maxProfit << endl;

    return 0;
}
