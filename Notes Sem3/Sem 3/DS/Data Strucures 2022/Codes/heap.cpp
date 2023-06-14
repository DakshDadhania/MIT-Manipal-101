#include <iostream>
// heap is complete binary tree with both the child having lesser value than root
using namespace std;

class heap
{
public:
    int arr[100];
    int size;
    heap()
    {
        arr[0] = -1;
        size = 0;
    }
    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }
    void deletefromHeap()
    {
        if (size == 0)
        {
            cout << "Nothing to delete" << endl;
            return;
        }

        // put last elem to first index
        arr[1] = arr[size];
        // rem last elem
        size--;
        // take root node to it's position
        int i = 1;

        while (i <= size)
        {
            int leftindex = 2 * i;
            int rightindex = 2 * i + 1;
            if (arr[leftindex] > arr[rightindex])
            {
                if (leftindex < size && arr[i] < arr[leftindex])
                {
                    swap(arr[i], arr[leftindex]);
                    i = leftindex;
                }
            }

            else if (rightindex <= size && arr[i] < arr[rightindex])
            {
                swap(arr[i], arr[rightindex]);
                i = rightindex;
            }
            else
            {
                return;
            }
        }
    }
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
void maxheapify(int arr[], int n,int i){
    int largest=i;
    int left=2*i;
    int right=2*i+1;
    if(left<=n && arr[largest]<arr[left]){
        largest=left;
        
    }
    if(right<=n && arr[largest]<arr[right]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        maxheapify(arr,n,largest);
    }
}
void minheapify(int arr[], int n,int i){
    int smallest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<=n && arr[smallest]>arr[left]){
        smallest=left;
        
    }
    if(right<=n && arr[smallest]>arr[right]){
        smallest=right;
    }
    if(smallest!=i){
        swap(arr[smallest],arr[i]);
        minheapify(arr,n,smallest);
    }
}
void heapsort(int arr[],int n){
    int size=n;
    while(size>1){
        swap(arr[size],arr[1]);
        size--;
        maxheapify(arr,size,1);
    }

}
int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(40);
    h.insert(234);
    h.insert(23);
    // h.print();
    h.deletefromHeap();
    // h.print();
    int arr[6]={-1,55,33,53,135,25};
    int n=5;
    for(int i=n/2;i>0;i--){
        maxheapify(arr,n,i);
    }
    // for(int i=n/2-1;i>=0;i--){
    //     minheapify(arr,n,i);
    // }
    heapsort(arr,n);
    cout<<"print the array\n";
    for (int i = 1; i <= n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;

    return 0;
}