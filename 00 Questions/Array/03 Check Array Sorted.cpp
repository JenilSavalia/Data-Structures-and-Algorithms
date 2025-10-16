#include <iostream>
using namespace std;

int main()
{
    int arr[] = {2, 1, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    bool isSorted = true;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            isSorted = false;
            break;
        }
    }

    if (isSorted)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

    return 0;
}
