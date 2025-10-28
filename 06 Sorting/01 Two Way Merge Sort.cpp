#include <iostream>
#include <vector>
using namespace std;

// The merge step  runs in O(n + m) time — linear in the total number of elements.

// int main()
// {

//     vector<int> arr1 = {1, 3, 5, 7};
//     vector<int> arr2 = {2, 4, 6, 8};
//     int n = 0;
//     int m = 0;
//     int k = 0;
//     vector<int> result(arr1.size() + arr2.size());

//     while (n < arr1.size() && m < arr2.size())
//     {
//         if (arr1[n] < arr2[m])
//         {
//             result[k++] = arr1[n++];
//         }
//         else
//         {
//             result[k++] = arr2[m++];
//         }
//     }

//     while (n < arr1.size())
//     {
//         result[k++] = arr1[n++];
//     }

//     while (m < arr2.size())
//     {
//         result[k++] = arr2[m++];
//     }

//     for (int x : result)
//     {
//         cout << x << endl;
//     }

//     return 0;
// }

// -----------------------------------------------------
// Merge two sorted halves: A[l..mid] and A[mid+1..h]
// -----------------------------------------------------

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (arr[left] < arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

// -----------------------------------------------------
// Recursive Merge Sort
// -----------------------------------------------------

void mergeSort(vector<int> &arr, int low, int high)
{

    if (low >= high)
        return;
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

// -----------------------------------------------------
// Main function
// -----------------------------------------------------

int main()
{
    vector<int> arr = {5, 2, 8, 4, 1};
    mergeSort(arr, 0, arr.size() - 1);
    for (int x : arr)
        cout << x << " ";
    cout << endl;
    return 0;
}
