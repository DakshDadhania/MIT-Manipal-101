#include <bits/stdc++.h>
using namespace std;

#define N 8

int col[N];
int row[N];
int diag1[2 * N - 1];
int diag2[2 * N - 1];
int queens[N];
int count;

bool can_place(int r, int c) {
    return !row[r] && !col[c] && !diag1[r + c] && !diag2[r - c + N - 1];
}

void place_queen(int r, int c) {
    queens[r] = c;
    row[r] = col[c] = diag1[r + c] = diag2[r - c + N - 1] = 1;
}

void remove_queen(int r, int c) {
    row[r] = col[c] = diag1[r + c] = diag2[r - c + N - 1] = 0;
}

void backtrack(int r) {
    if (r == N) {
        count++;
        return;
    }
    for (int c = 0; c < N; c++) {
        if (can_place(r, c)) {
            place_queen(r, c);
            backtrack(r + 1);
            remove_queen(r, c);
        }
    }
}

int main() {
    backtrack(0);
    cout << count << "\n";
    return 0;
}
