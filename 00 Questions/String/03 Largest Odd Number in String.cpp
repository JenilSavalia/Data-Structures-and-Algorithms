class Solution
{
public:
    string largestOddNumber(string num)
    {
        if ((num.back() - '0') % 2 != 0)
            return num;

        int n = num.length();
        for (int i = n - 1; i >= 0; i--)
        {
            if ((num[i] - '0') % 2 != 0)
            {
                return num.substr(0, i + 1);
            }
        }

        return "";
    }
};

// how can we get largest odd number from a string (substrings included) ?

// if we iterate from last char of the string and check (after converision from char to int) id that char is odd, then that would be the biggest
// substring that is odd

// How to convert char "1" to integer 1 ?

// characters like '0', '1', '2', etc. are stored as ASCII codes — numeric values under the hood.

// Character	ASCII code (decimal)
// '0'	48
// '1'	49
// '2'	50
// '3'	51
// '4'	52
// '5'	53
// '6'	54
// '7'	55
// '8'	56
// '9'	57

// example -> '4' in ASCII is 52 and '0' in ASCII is 48. so  52 - 48   →   4

// diff b/w % (mudlo) and / () operators ?

// % -> gives reminder  ex -> 5 % 2 = 1 (remainder) , 8 % 2 = 0 (remainder)

//   / => gives divisor (result) ex -> 5 / 2 = 2.5 ~ 2 , 10/5 = 2
