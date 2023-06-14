// CPP Code to find rank of elements
#include<iostream>
using namespace std;
int count=0;

// Function to find rank
void rankify(int* A , int n) {


	// Rank Vector
	float R[n] = {0};
	count++;

	// Sweep through all elements in A for each
	// element count the number of less than and
	// equal elements separately in r and s.
	for (int i = 0; i < n; i++) {
            count++;count++;
		int r = 1, s = 1;
    count++;

		for (int j = 0; j < n; j++) {
                count++;count++;
			if (j != i && A[j] < A[i])
                {count++;
				r += 1;
                }
			if (j != i && A[j] == A[i])
				{
				    count++;
				    s += 1;
				}
		}
		count++;
        count++;
		// Use formula to obtain rank
		R[i] = r + (float)(s - 1) / (float) 2;

	}
	count++;

	for (int i = 0; i < n; i++)
    {
        count++;
        count++;
        cout << R[i] << ' ';
    }
    count++;

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


	  cout<<"\n"<<"No of steps for the ->"<< n<<" -> elements is -> "<<count;
	  cout<<"\n"<<" The time complexicity is n^2 where n = "<<n;
	return 0;
}
