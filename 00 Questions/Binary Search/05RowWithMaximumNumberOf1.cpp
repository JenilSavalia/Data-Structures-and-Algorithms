#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <numeric>
using namespace std;

int findFirstOccurance(vector<int> row)
{
    int left = 0;
    int right = row.size() - 1;
    int ans = row.size(); // default if no 1 is found

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (row[mid] == 1)
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return ans;
}

int main()
{

    int m = 3;
    vector<vector<int>> arr = {{1, 1, 1},
                               {0, 0, 1},
                               {0, 0, 0}};

    // what we would do is , we would iterate normally on all rows
    // and in each row we would find first occurance of 1 using binary search, this would help us find
    // frequencr of 1's in a row wihh less log(m) time complecity and overall complexicity of (n * log(m))

    int maxFrequency = 0;
    int minIndex = -1;
    for (int i = 0; i < arr.size(); i++)
    {

        int firstIndex = findFirstOccurance(arr[i]);
        if (arr[i][firstIndex] == arr[i].size())
        {
            continue;
        }
        else
        {
            int frequency = (arr[i].size() - 1) - firstIndex + 1;
            if (frequency > maxFrequency)
            {
                maxFrequency = frequency;
                minIndex = i;
            }
        }
        cout << minIndex;
    }
}