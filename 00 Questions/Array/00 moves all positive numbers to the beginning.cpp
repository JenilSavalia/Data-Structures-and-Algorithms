// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;



// two pointer approach
int main()
{

    vector<int> v = {-1, 2, -3, -6, 5, 4, 7};

    int i = 0;
    int j = 0;

    for (i; i < v.size(); i++)
    {
        if (!(v[i] < 0))
        {
            swap(v[i], v[j]);
            j++;
        }
    }

    for (int x : v)
    {
        cout << x << " ";
    }

    return 0;
}