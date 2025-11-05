// 2️⃣ Build Max Heap

// converting an unsorted array into a heap is called Heap Construction or Heapify Process.

// 🧩 Concept: Building a Heap from an Array

// You can build a heap in O(n) time using a bottom-up heapify process.

#include <iostream>
#include <vector>
using namespace std;

void maxHeapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void buildMaxHeap(vector<int> &arr)
{
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        maxHeapify(arr, n, i);
    }
}

int main()
{
    vector<int> arr = {5, 3, 8, 4, 1, 2};
    buildMaxHeap(arr);

    cout << "Max Heap Array: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}
