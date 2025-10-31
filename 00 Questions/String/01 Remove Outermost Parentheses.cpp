// ✅ Approach 1: Counter-Based Approach (Efficient)

// We can solve this in O(n) time and O(1) extra space (besides the result string).

// 🔍 Idea:

// Keep a counter to track how many parentheses are currently open.

// When we see '(', we increase the counter.

// When we see ')', we decrease the counter.

// We only add characters to the result when the counter is not zero — that means we’re inside a primitive substring (not at its outermost boundary).

class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        string ans = "";
        int counter = 0; // Tracks the current level of nesting

        for (char x : s)
        {
            // Step 1: If current character is a closing parenthesis
            // we decrement counter first (to reflect going out of a level)
            if (x == ')')
            {
                counter--;
            }

            // Step 2: If we are not at the outermost level, add character
            // counter != 0 means we are inside a primitive
            if (counter != 0)
            {
                ans += x;
            }

            // Step 3: If current character is an opening parenthesis
            // we increment counter after checking (to reflect entering a level)
            if (x == '(')
            {
                counter++;
            }
        }

        return ans;
    }
};

// 🪜 Approach 2: Stack-Based Approach (Alternative)
// We can also use a stack to simulate the same logic.
// Idea:
// Push '(' onto a stack when seen.
// Pop when ')' is seen.
// Only add characters to result when the stack is not empty (same concept as counter-based, but less efficient).

string removeOuterParentheses(string s)
{
    string ans = "";
    stack<char> st;

    for (char c : s)
    {
        if (c == ')')
        {
            st.pop(); // we’re closing a bracket
        }

        if (!st.empty())
        {
            ans += c; // add only if inside a primitive
        }

        if (c == '(')
        {
            st.push(c); // open a new bracket
        }
    }

    return ans;
}
