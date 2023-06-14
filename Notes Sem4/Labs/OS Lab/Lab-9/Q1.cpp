#include <iostream>
#include <vector>
using namespace std;

void bestFit(vector<int> blocks, int m, vector<int> processes, int n) {
    vector<int> alloc(n, -1);
    for(int i=0; i<n; i++) {
        int best = -1;
        for(int j=0; j<m; j++) {
            if (blocks[j] >= processes[i]) {
                if (best == -1 || blocks[best] > blocks[j])
                    best = j;
            }
        }
        if (best != -1) {
            alloc[i] = best;
            blocks[best] -= processes[i];
        }
    }
    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for(int i=0; i<n; i++) {
        cout << "   " << i + 1 << "\t\t" << processes[i] << "\t\t";
        if (alloc[i] != -1)
            cout << alloc[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}

void firstFit(vector<int> blocks, int m, vector<int> processes, int n) {
    vector<int> alloc(n, -1);
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if (blocks[j] >= processes[i]) {
                alloc[i] = j;
                blocks[j] -= processes[i];
                break;
            }
        }
    }

    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for(int i=0; i<n; i++) {
        cout << " " << i + 1 << "\t\t"
             << processes[i] << "\t\t";
        if (alloc[i] != -1)
            cout << alloc[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}

int main() {
    int m, n;
    cout << "Enter number of blocks: " << endl;
    cin >> n;
    cout << "Enter number of processes: " << endl;
    cin >> m;

    vector<int> blocks(n), processes(m);

    for(int i=0; i<n; i++) cin >> blocks[i];
    for(int i=0; i<m; i++) cin >> processes[i];

    bestFit(blocks, m, processes, n);
    firstFit(blocks, m, processes, n);
    return 0;
}
