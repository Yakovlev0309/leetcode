#include "../leetcode.h"

int myAtoi(std::string s)
{
    int sign = 1;
    int i = 0;
    long ans = 0;

    while (i < s.length() && s[i] == ' ')
    {
        i++;
    }

    if (s[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (s[i] == '+')
    {
        i++;
    }

    while (i < s.length())
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            ans = ans * 10 + (s[i] - '0');

            if (ans > INT_MAX && sign == -1)
            {
                return INT_MIN;
            }
            else if (ans > INT_MAX && sign == 1)
            {
                return INT_MAX;
            }
            i++;
        }
        else
        {
            return ans * sign;
        }
    }

    return ans * sign;
}

// int myAtoi(string s)
// {
//     if (s.length() == 0)
//     {
//         return 0;
//     }

//     string res = "";

//     int size = s.length();
//     int first_digit_index = -1;
//     int i;
//     for (i = 0; i < size; ++i)
//     {
//         if (isdigit(s[i]))
//         {
//             first_digit_index = i;
//             break;
//         }
//         else if (s[i] != ' ' && s[i] != '-')
//         {
//             break;
//         }
//     }

//     if (first_digit_index == -1)
//     {
//         return 0;
//     }

//     // bool minus = false;
//     if (first_digit_index != 0)
//     {
//         if (s[first_digit_index - 1] == '-')
//         {
//             // minus = true;
//             res += '-';
//         }
//     }
//     res += s[first_digit_index];

//     for (i = first_digit_index + 1; i < size; ++i)
//     {
//         if (isdigit(s[i]))
//         {
//             res += s[i];
//         }
//         else
//         {
//             break;
//         }
//     }

//     return stoll(res);
// }
