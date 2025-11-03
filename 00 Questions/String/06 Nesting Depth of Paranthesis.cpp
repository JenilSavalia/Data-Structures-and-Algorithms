class Solution {
public:
    int maxDepth(string s) {
        int MaxCnt = 0;
        int cnt = 0;
        for (char x : s) {
            if (x == '(') {
                cnt++;
            } else {
                if (x == ')') {
                    cnt--;
                }
            }
            MaxCnt = max(cnt, MaxCnt);
        }
        return MaxCnt;
    }
};