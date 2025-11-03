class Solution
{

public:
    string frequencySort(string s)
    {
        unordered_map<char, int> m;
        vector<pair<char, int>> v;
        for (char x : s)
        {
            m[x]++;
        }
        for (auto x : m)
        {
            v.push_back(x);
        }

        // important thing to note here is that we need to sort our map according to value,
        // to do that we would first map <char,int> character:frequency in map then insert all in vector of pair
        // then we would sort the vector (using a additional lambda in sort function )

        // Sort by descending frequency
        sort(v.begin(), v.end(),
             [](const pair<char, int> &a, const pair<char, int> &b)
             {
                 return a.second > b.second;
             });

        // above third argument is lambda function

        string result;
        for (auto x : v)
        {
            if (x.second > 1)
            {
                for (int j = 0; j < x.second; j++)
                {
                    result += x.first;
                }
            }
            else
            {
                result += x.first;
            }
        }

        return result;
    }
};
