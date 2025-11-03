class Solution
{
public:
    void reverse(string &s, int start, int end)
    {
        while (start < end)
        {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }

    bool rotateString(string s, string goal)
    {

        int k = s.length();
        string temp = s;
        for (int i = 0; i < k; i++)
        {

            reverse(s, 0, k - 1);
            reverse(s, 0, k - i - 1);
            reverse(s, k - i, k - 1);

            if (s == goal)
            {
                return true;
            }
            s = temp;
        }

        return false;
    }
};

// single liner approach
return s.size() == goal.size() && (s + s).find(goal) != string::npos;
