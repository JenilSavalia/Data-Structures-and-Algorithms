#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// we need to find maximum number of pages assigned to student to be minimum

// range would be [max_element, sum_of_elements]

// we need to find the first case where
// Each student gets at least one book.
// Each book should be allocated to only one student.
// Book allocation should be in a contiguous manner.

// and when return a maximum value of pages a student got in that case

// brute force approach

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int allocateBooks(vector<int> &arr, int maxPages)
{
    int studentCount = 1;
    int currStudentPages = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (currStudentPages + arr[i] <= maxPages)
        {
            currStudentPages += arr[i];
        }
        else
        {
            studentCount++;
            currStudentPages = arr[i];
        }
    }

    return studentCount;
}

int main()
{

    int students = 4;
    vector<int> arr = {25, 46, 28, 49, 24};

    if (students > arr.size())
        return -1;

    int maxElement = *max_element(arr.begin(), arr.end());
    int sum = accumulate(arr.begin(), arr.end(), 0);

    for (int i = maxElement; i <= sum; i++)
    {

        if (allocateBooks(arr, i) == students)
        {
            cout << i;
            return i;
        }
    }

    return 0;
}

// lets do binary search baby!!!

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>

using namespace std;

int allocateBooks(vector<int> &arr, int maxPages)
{
    int studentCount = 1;
    int currStudentPage = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > maxPages)
            return INT_MAX;

        if (currStudentPage + arr[i] <= maxPages)
        {
            currStudentPage += arr[i];
        }
        else
        {
            studentCount++;
            currStudentPage = arr[i];
        }
    }
    return studentCount;
}

int main()
{
    int students = 4;
    vector<int> arr = {25, 46, 28, 49, 24};

    if (students > arr.size())
    {
        cout << -1;
        return 0;
    }

    int left = *max_element(arr.begin(), arr.end());
    int right = accumulate(arr.begin(), arr.end(), 0);
    int answer = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (allocateBooks(arr, mid) > students)
        {
            left = mid + 1;
        }
        else
        {
            answer = mid;
            right = mid - 1;
        }
    }

    cout << answer;
    return 0;
}
