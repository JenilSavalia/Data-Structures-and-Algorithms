#include <iostream>

#include <vector>

#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// union of two arrays

int main()
{

    int arr1[] = {
        1,
        2,
        3,
        4,
        5,
        6,
        7,
        8,
        9,
        10};
    int arr2[] = {
        2,
        3,
        4,
        4,
        5,
        11,
        12};

    set<int> s;
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);

    for (int i = 0; i < m; i++)
    {
        s.insert(arr1[i]);
    }
    for (int i = 0; i < n; i++)
    {
        s.insert(arr2[i]);
    }

    for (auto x : s)
        cout << x << endl;

    return 0;
}

// intersection of two arrays using two sets

// first we will take a unordered_set (as it has constant addition,and searching) and add all elements of first array to id
// then we will create a new resultant set
// then we will iterate our second array and check for each elemnet, that id  element from second array exist in set created from first array
// if it exists then we will add that element to our resultant set

// why we are taking two sets?
// as in second array if we have duplicate elements then , we would have duplicate elements in our intersection result

vector<int> a = {1, 2, 3, 4};
vector<int> intersectionOfArrays(vector<int> &a, vector<int> &b)
{
    unordered_set<int> s;
    unordered_set<int> resultant;

    // Insert elements of array a into set s
    for (int x : a)
    {
        s.insert(x);
    }

    // Find intersection with array b
    for (int x : b)
    {
        if (s.find(x) != s.end())
        {
            resultant.insert(x);
        }
    }

    // Convert resultant set to a vector
    vector<int> result(resultant.begin(), resultant.end());
    return result;
}

// intersection of two arrays using hashmap

vector<int> a = {1, 2, 3, 4};
vector<int> b = {3, 4, 5, 6};
unordered_map<int, int> s;
int idx = 1;

for (int x : a)
{
    s[x]++;
}
for (int x : b)
{
    s[x]++;
}

for (auto x : s)
{
    if (x.second == 2)
    {
        cout << x.first << " ";
    }
}