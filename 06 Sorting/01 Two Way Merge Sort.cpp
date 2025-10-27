#include <iostream>
#include <vector>
using namespace std;

// The merge step  runs in O(n + m) time — linear in the total number of elements.

int main()
{

    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {2, 4, 6, 8};
    int n = 0;
    int m = 0;
    int k = 0;
    vector<int> result(arr1.size() + arr2.size());

    while (n < arr1.size() && m < arr2.size())
    {
        if (arr1[n] < arr2[m])
        {
            result[k++] = arr1[n++];
        }
        else
        {
            result[k++] = arr2[m++];
        }
    }

    while (n < arr1.size())
    {
        result[k++] = arr1[n++];
    }

    while (m < arr2.size())
    {
        result[k++] = arr2[m++];
    }

    for (int x : result)
    {
        cout << x << endl;
    }

    return 0;
}

// -----------------------------------------------------
// Merge two sorted halves: A[l..mid] and A[mid+1..h]
// -----------------------------------------------------
void merge(int A[], int temp[], int l, int mid, int h)
{
    int i = l;       // pointer for left half
    int j = mid + 1; // pointer for right half
    int k = l;       // pointer for temp array

    // Merge elements from both halves into temp[]
    while (i <= mid && j <= h)
    {
        if (A[i] <= A[j])
            temp[k++] = A[i++];
        else
            temp[k++] = A[j++];
    }

    // Copy any remaining elements from left half
    while (i <= mid)
        temp[k++] = A[i++];

    // Copy any remaining elements from right half
    while (j <= h)
        temp[k++] = A[j++];

    // Copy merged section back into original array
    for (int p = l; p <= h; p++)
        A[p] = temp[p];
}

// -----------------------------------------------------
// Recursive Merge Sort
// -----------------------------------------------------
void mergeSort(int A[], int temp[], int l, int h)
{

    if (l < h)
    {
        int mid = (l + h) / 2;

        // Recursively sort both halves
        mergeSort(A, temp, l, mid);
        mergeSort(A, temp, mid + 1, h);

        // Early exit: if already sorted, skip merge
        if (A[mid] <= A[mid + 1])
            return;

        // Merge the two sorted halves
        merge(A, temp, l, mid, h);
    }
}

// -----------------------------------------------------
// Main function
// -----------------------------------------------------
int main()
{
    int A[] = {38, 27, 43, 3, 9, 82, 10, 50, 41, 12};
    int n = sizeof(A) / sizeof(A[0]);

    cout << "Unsorted array: ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << "\n";

    int temp[n]; // single reusable buffer
    mergeSort(A, temp, 0, n - 1);

    cout << "Sorted array:   ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << "\n";

    return 0;
