// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

int main()
{

    vector<vector<int>> M = {{0, 1}, {1, 0}};

    // 1. identify a persion who does not know any one
    // 2. then check if everyone knows that person

    // check each row => when ever row with all 0 is encountered ,breakout

    // that is a brute force approach

    int rowNum = -1;
    for (int i = 0; i < M.size(); i++)
    {
        bool allZeros = true;
        for (int j = 0; j < M.size(); j++)
        {
            if (M[i][j] != 0)
            {
                allZeros = false;
                break;
            }
        }
        if (allZeros)
        {
            rowNum = i;
            break;
        };
    }

    if (rowNum == -1)
    {
        cout << "No Celebrity";
        return -1;
    }

    bool allKnows = true;
    for (int i = 0; i < M.size(); i++)
    {
        if (i == rowNum)
            continue;
        if (M[i][rowNum] != 1)
        {
            allKnows = false;
            break;
        }
    }

    if (allKnows)
    {
        cout << "Celebrity Pseson : " << rowNum;
    }
    else
    {
        cout << "No Celebrity";
    }

    return 0;
}