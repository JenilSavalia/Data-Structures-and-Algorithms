#include <iostream>
#include <vector>
using namespace std;

int binarySearch(int l, int r, vector<int> arr, int key)
{
    if (l > r)
        return -1;
    int mid = l + (r - l) / 2; // To prevent potential overflow
    if (arr[mid] == key)
    {
        return mid;
    }

    if (arr[mid] > key)
    {
        return binarySearch(l, mid - 1, arr, key);
    }
    else
    {
        return binarySearch(mid + 1, r, arr, key);
    }
}

int main()
{

    vector<int> arr = {1, 2, 8, 9, 16, 25, 36, 75, 88, 99};

    int l = 0;
    int r = arr.size() - 1;
    int mid = (r - l) / 2;
    int key = 88;

    cout << binarySearch(l, r, arr, key);
    return 0;
}