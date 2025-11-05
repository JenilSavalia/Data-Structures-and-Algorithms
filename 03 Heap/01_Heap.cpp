#include <iostream>
#include <vector>
using namespace std;

// A Heap is a complete binary tree that satisfies the heap property:

// In a Min Heap, the parent node's value is smaller than or equal to the values of its children.
// In a Max Heap, the parent node's value is greater than or equal to the values of its children.

// Insert: 𝑂(log⁡𝑛)
// O(logn) — Because inserting an element may require bubbling it up from a leaf node.

// Delete (Extract Min/Max): 𝑂(log⁡𝑛)
// O(logn) — Removing the root element requires bubbling down to maintain heap properties.

// Heapify: O(n)
// O(n) — Building a heap from an unsorted array.

// Heap Sort: O(nlogn)
// O(nlogn) — Repeatedly extracting the root element and rebuilding the heap.

// heap is represented as array [50,30,20,15,10,8,16]
// therefore to get left child , right child or parent of node at index (i) is :

// parent : i - 1 / 2
// left child : 2i + 1;
// right child : 2i + 2;

// Insertion Operation in MAX Heap

// Insert the element at last in the array and compare with its parents and swap elements till condidion of (MAX or MIN heap) is satisfied
// Time Complexicity for Insertion :  minimum : O(log n) , minimium : O(1)

// in Insertion adjustment is done (Uppward) from down to upward

// Delete Operation in MAX Heap

// in Deletion adjustment is done (Downward) from upward to downward
// When we delete a element from Max Heap (we can only delete root element), we get the largest element (that is root element is deleted) vice versa for MIN Heap

// Time Complexicity for Deletion :  minimum : O(log n) , minimium : O(1)

class Heap
{
private:
    vector<int> heap;

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    void heapify(int i)
    {
        int largest = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < heap.size() && heap[left] > heap[largest])
        {
            largest = left;
        }

        if (right < heap.size() && heap[right] > heap[largest])
        {
            largest = right;
        }

        if (largest != i)
        {
            swap(heap[i], heap[largest]);
            heapify(largest);
        }
    }

public:
    void insert(int value)
    {
        heap.push_back(value);
        int i = heap.size() - 1;

        // Bubble up to restore heap property
        while (i > 0 && heap[parent(i)] < heap[i])
        {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    int extractMax()
    {
        if (heap.size() == 0)
            return -1; // or throw an exception

        if (heap.size() == 1)
        {
            int root = heap[0];
            heap.pop_back();
            return root;
        }

        // Replace the root with the last element and heapify
        int root = heap[0];
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        heapify(0);

        return root;
    }

    // Heap sort
    void heapSort()
    {
        vector<int> sorted;
        while (!heap.empty())
        {
            sorted.push_back(extractMax());
        }

        // Print sorted array (descending order)
        for (int i : sorted)
        {
            cout << i << " ";
        }
        cout << endl;
    }
};