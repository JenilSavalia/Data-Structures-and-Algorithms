// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

int n = 2;
void getSubtrings(string str, int pos)
{

    // base case => pos = n
    if (pos == n)
    {
        cout << str << endl;
        return;
    }
    getSubtrings(str + "0", pos + 1);
    if (str.empty() || str.back() != '1')
    {
        getSubtrings(str + "1", pos + 1);
    }
}

int main()
{

    string str = "";
    int pos = 0;
    getSubtrings(str, pos);

    return 0;
}