class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {

        vector<string> result;
        generate("", n, result, 0, 0);
        return result;
    }
    void generate(string str, int n, vector<string> &result, int openCnt,
                  int closeCnt)
    {
        if (str.size() == 2 * n)
        {
            result.push_back(str);
            return;
        }

        if (openCnt < n)
            generate(str + "(", n, result, openCnt + 1, closeCnt);

        // Think of openCnt - closeCnt as the number of currently open
        // parentheses.
        // You’re not allowed to close if that number is zero.
        if (openCnt > closeCnt)
            // You can only add a closing parenthesis if there are more opens
            // than closes so far.
            generate(str + ")", n, result, openCnt, closeCnt + 1);
    }
};