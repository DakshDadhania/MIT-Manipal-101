// CPP Code to find rank of elements
#include <bits/stdc++.h>
using namespace std;

// Function to find rank
void rankify(int* A , int n) {

	// Rank Vector
	float R[n] = {0};

	// Sweep through all elements in A for each
	// element count the number of less than and
	// equal elements separately in r and s.
	for (int i = 0; i < n; i++) {
		int r = 1, s = 1;

		for (int j = 0; j < n; j++) {
			if (j != i && A[j] < A[i])
				r += 1;

			if (j != i && A[j] == A[i])
				s += 1;
		}

		// Use formula to obtain rank
		R[i] = r + (float)(s - 1) / (float) 2;

	}

	for (int i = 0; i < n; i++)
		cout << R[i] << ' ';

	}

// Driver Code
int main() {
	int n;
	cout<<"Enter the no of elements in the array";
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
        cout<<"Enter the "<<i<<"th element";
        cin>>arr[i];
        cout<<"\n";
	}
	cout<<"elements "<< "\n";
	for (int i = 0; i < n; i++){
	cout << arr[i] << ' ';
	cout << '\n';
	}
	cout<<"ranks "<< "\n";
	rankify(arr, n);

	return 0;
}
