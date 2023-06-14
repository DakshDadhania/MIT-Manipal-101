#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, L;
    cin >> n >> L;

    vector<int> programs(n);
    for (int i = 0; i < n; i++) {
        cin >> programs[i];
    }

    sort(programs.begin(), programs.end(), greater<int>());

    int used1 = 0, used2 = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (used1 + programs[i] <= L) {
            used1 += programs[i];
        } else if (used2 + programs[i] <= L) {
            used2 += programs[i];
        } else {
            break;
        }
        count++;
    }

    cout << count << endl;

    return 0;
}
