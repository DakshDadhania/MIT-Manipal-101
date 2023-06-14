#include <iostream>
using namespace std;
int count = 0;
void bubblesort(int arr[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        count++;
        count++;
        for (int j = 0; j < n - i - 1; j++)
        {
            count++;
            count++;
            if (arr[j + 1] < arr[j])
            {
                count++;
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
            count++;
        }
        count++;
    }
    count++;
}
int main()
{
    int n;
    cout << "Enter the no of elements in array";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the " << i + 1 << "th element";
        cin >> arr[i];
    }
    bubblesort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the " << i + 1 << "th element -";
        cout << arr[i] << "\n";
    }

    cout << "\n"
         << "No of steps for the ->" << n << " -> elements is -> " << count;
    cout << "\n"
         << " The time complexicity is n^2 where n = " << n;
    return 0;
}
