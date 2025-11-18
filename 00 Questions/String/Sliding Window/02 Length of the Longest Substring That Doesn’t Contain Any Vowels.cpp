// Length of the Longest Substring That Doesn’t Contain Any Vowels

// Input: arr = [-1, 2, -2, 3, 5, -7, -5], K = 3
// Output: 2, 1, 1, 1, 2

#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main()
{

    string s = "codeforintelligents";
    int maxCount = INT_MIN;
    int current = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            current = 0;
        }
        else
        {
            current++;
            maxCount = max(maxCount, current);
        }
    }

    cout << maxCount;

    return 0;
}
