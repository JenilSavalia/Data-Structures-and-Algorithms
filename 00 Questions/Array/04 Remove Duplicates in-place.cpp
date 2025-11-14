#include <iostream>

#include <vector>

using namespace std;

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// using unordered set

int main()
{
    vector<int> a = {2, 2, 4, 4, 7, 8, 10};
    unordered_set<int> s;
    int idx = 0;

    for (int i = 0; i < a.size(); i++)
    {
        // find() returns end() iteratorif element is not found
        // here if element is not found then we we insert that element in set
        // and and update unique element to our index and increment that index
        if (s.find(a[i]) == s.end())
        {
            s.insert(a[i]);
            a[idx] = a[i];
            idx++;
        }
    }

    for (int x : a)
    {
        cout << x << " ";
    }

    return 0;
}

// Start with idx = 1 (idx is going to hold the index of the next distinct item. Since there is nothing before the first item, we consider it as the first distinct item and begin idx with 1.
// Loop through the array for i = 0 to n-1.
// At each index i, if arr[i] is different from arr[i-1], assign arr[idx] = arr[i] and increment idx.
// After the loop, arr[] contains the unique elements in the first idx positions.

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main()
{
    vector<int> a = {2, 2, 4, 4, 7, 8, 10};
    unordered_set<int> s;
    int idx = 1;

    for (int i = 1; i < a.size(); i++)
    {
        if (a[i - 1] != a[i])
        {
            a[idx] = a[i];
            idx++;
        }
    }

    for (int x : a)
    {
        cout << x << " ";
    }

    return 0;
}
