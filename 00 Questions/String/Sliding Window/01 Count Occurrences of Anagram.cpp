#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
#include <unordered_set>
using namespace std;


// fixed Size window is used here
int main()
{

    unordered_map<char, int> m;
    unordered_map<char, int> m1;

    string text = "gotxxotgxdogt";
    string word = "got";

    int count = 0;

    for (char x : word)
    {
        m1[x]++;
    }
    for (int i = 0; i < word.length(); i++)
    {
        m[text[i]]++;
    }
    if (m == m1)
        count++;

    int start = 0;
    for (int end = word.length(); end < text.length(); end++)
    {

        // add new character
        m[text[end]]++;

        // remove old character
        m[text[start]]--;
        if (m[text[start]] == 0)
        {
            m.erase(text[start]);
        }

        start++;

        if (m == m1)
            count++;
    }
    cout << count;

    return 0;
}