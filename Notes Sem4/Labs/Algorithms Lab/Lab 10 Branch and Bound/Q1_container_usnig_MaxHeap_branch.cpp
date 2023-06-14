#include <bits/stdc++.h>
using namespace std;

struct Item {
    int weight;
    int value;
};

struct Node {
    int level;
    int profit;
    int weight;
    float bound;
};

bool cmp(Item a, Item b) {
    return (a.value / a.weight) > (b.value / b.weight);
}

float bound(Node u, int n, int W, Item arr[]) {
    if (u.weight >= W)
        return 0;

    float profit_bound = u.profit;
    int j = u.level + 1;
    int tot_weight = u.weight;

    while ((j < n) && (tot_weight + arr[j].weight <= W)) {
        tot_weight += arr[j].weight;
        profit_bound += arr[j].value;
        j++;
    }

    if (j < n) {
        profit_bound += (W - tot_weight) * (arr[j].value / arr[j].weight);
    }

    return profit_bound;
}

int knapsack(int W, Item arr[], int n) {
    sort(arr, arr + n, cmp);

    priority_queue<Node> Q;
    Node u, v;

    u.level = -1;
    u.profit = u.weight = 0;
    Q.push(u);

    int maxProfit = 0;

    while (!Q.empty()) {
        u = Q.top();
        Q.pop();

        if (u.level == -1) {
            v.level = 0;
        }
        else if (u.level != n - 1) {
            v.level = u.level + 1;
        }

        v.weight = u.weight + arr[v.level].weight;
        v.profit = u.profit + arr[v.level].value;

        if (v.weight <= W && v.profit > maxProfit) {
            maxProfit = v.profit;
        }

        v.bound = bound(v, n, W, arr);

        if (v.bound > maxProfit) {
            Q.push(v);
        }

        v.weight = u.weight;
        v.profit = u.profit;

        v.bound = bound(v, n, W, arr);

        if (v.bound > maxProfit) {
            Q.push(v);
        }
    }

    return maxProfit;
}

int main() {
    int W, n;
    cout << "Enter the capacity of the container: ";
    cin >> W;
    cout << "Enter the number of items: ";
    cin >> n;
    Item arr[n];
    cout << "Enter the weight and value of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i].weight >> arr[i].value;
    }
    int maxProfit = knapsack(W, arr, n);
    cout << "The maximum value that can be loaded into the container is: " << maxProfit << endl;
    return 0;
}
