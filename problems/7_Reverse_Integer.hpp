#include "../leetcode.h"

int reverse(int x)
{
    std::string str = std::to_string(x);
    bool minus = false;
    long ans = 0;
    
    if (str[0] == '-')
    {
        minus = true;
        str = str.substr(1, str.length());
    }

    for (int i = str.length() - 1; i >= 0; --i)
    {
        if (ans * 10 + (str[i] - '0') > INT_MAX)
        {
            return 0;
        }
        ans = ans * 10 + (str[i] - '0');
    }

    return minus ? -ans : ans;
}
