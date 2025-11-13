// Double the first element and move zero to end

// For a given array of n integers and assume that '0' is an invalid number and all others a valid number.
// Convert the array in such a way that if both current and next element is valid and both have same value
// then double current value and replace the next number with 0. After the modification, rearrange the array
//  such that all 0’s shift to the end.

// Input : arr[] = {2, 2, 0, 4, 0, 8}
// Output : 4 4 8 0 0 0

// Input : arr[] = {0, 2, 2, 2, 0, 6, 6, 0, 0, 8}
// Output :  4 2 12 8 0 0 0 0 0 0

#include <iostream>
#include <vector>
using namespace std;

int main()
{

    vector<int> arr = {0, 2, 2, 2, 0, 6, 6, 0, 0, 8};
    int i = 0;
    for (i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i] == arr[i + 1] && (arr[i] > 0 && arr[i + 1] > 0))
        {
            arr[i] = arr[i] * 2;
            arr[i + 1] = 0;
        }
    }

    // when ever we are using two pointer , keep in mind what are roles of pointers

    // here j pointer keeps track of where next non zero element should go ,
    // and i scans every element and whenever a non-zero element is seen , we swap elements (j pointing 0 and i pointing non zero element)
    // and we increment the j

    int j = 0;
    for (i = 0; i < arr.size(); i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }

    for (int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}
