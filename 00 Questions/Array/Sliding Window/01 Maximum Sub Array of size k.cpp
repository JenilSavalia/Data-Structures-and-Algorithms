#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{

    vector<int> a = {3, 5, 2, 1, 7};
    int k = 0;

    int sum = 0;
    int maxSum = INT_MIN;
    int j = 0;
    int i = 0;

    while (i < a.size())
    {
        sum += a[i];
        if (j - i + 1 == k)
        {
            maxSum = max(sum, maxSum);
            sum = sum - a[j];
        }
        i++;
    }

    cout << maxSum;

    return 0;
}