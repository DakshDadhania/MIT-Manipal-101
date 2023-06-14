// Program to implement 0/1 Knapsack using Dynamic Programming using Bottom-Up Approach
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;


class item{
    public:
    int weight;
    int value;
};


// void load_knapsack(int max, item items[], int n ){
//     int table[n][max];
//     for (int i = 0; i <= n; i++) { 
//         for (int w = 0; w <= max; w++) { 
//             if (i == 0 || w == 0) 
//                 table[i][w] = 0; 
//             else if (items[i-1].weight <= w) 
//                 table[i][w] = std::max(items[i-1].value + table[i-1][w-(items[i - 1].weight)], table[i - 1][w]); 
//             else
//                 table[i][w] = table[i - 1][w]; 
//         } 
//     }
//     cout<<"Profit obtained: "<<table[n][max];

//}

void load_knapsack(int max, item items[], int n ){
    int table[n+1][max+1];
    bool selected[n];
    memset(selected, false, sizeof(selected));
    
    for (int i = 0; i <= n; i++) { 
        for (int w = 0; w <= max; w++) { 
            if (i == 0 || w == 0) {
                table[i][w] = 0; 
            } else if (items[i-1].weight <= w) {
                int val1 = items[i-1].value + table[i-1][w-(items[i-1].weight)];
                int val2 = table[i-1][w];
                if (val1 > val2) {
                    table[i][w] = val1;
                    selected[i-1] = true;
                } else {
                    table[i][w] = val2;
                }
            } else {
                table[i][w] = table[i-1][w]; 
            }
        } 
    }
    
    cout << "Profit obtained: " << table[n][max] << "\n";
    cout << "Selected items: ";
    for (int i = n-1; i >= 0; i--) {
        if (selected[i]) {
            cout << "1 ";
        } else {
            cout << "0 ";
        }
    }
}


int main(){
    int max;
    cout<<"Enter max weight:";
    cin>>max;
    int n;
    cout<<"Enter number of objects:";
    cin>>n;
    cout<<"Enter weight value pairs: \n";
    item items[n];
    for(int i=0;i<n;i++)
        cin>>items[i].weight>>items[i].value;
    load_knapsack(max, items, n);
}