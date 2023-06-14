#include <iostream> // recursive binary search
int count = 0;
using namespace std;
int binarysearch(int arr[], int h, int l, int ele)
{   int mid = (h + l) / 2;
    count++;
    if (l > h)
    {count++;return -2;
    }
    if (arr[mid] == ele)
    {   count++;
        return mid;
    }
    else if (arr[mid] > ele)
    {   count++;
        binarysearch(arr, mid - 1, l, ele);
    }
    else
    {   count++;
        binarysearch(arr, h, mid + 1, ele);
    } }
int main()
{   cout << "Binary Search program \n";
    cout << "Enter the no of elements in the array \n";
    int h;
    cin >> h;
    int arr[h];
    int l = 0;
    for (int i = 0; i < h; i++)
    {   cout << "Enter " << i + 1 << "th element";
        cin >> arr[i];}
    cout << "Enter the element to be searched? ";
    int ele;
    cin >> ele;
    cout << "Element at position " << binarysearch(arr, h - 1, l, ele) + 1;
    cout << "\n"<< "No of steps for the ->" << h << " -> elements is -> " << count;
    cout << "\n"<< " The time complexicity is log n where n = " << h;
    return 0;}
