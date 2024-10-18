#include "../leetcode.h"

int maximumSwap(int num)
{
    std::string str = std::to_string(num);
    std::vector<int> values;
    // values.reserve(str.length() ^ 2);

    for (int i = 0; i < str.length(); ++i)
    {
        for (int j = i; j < str.length(); ++j)
        {
            if (str[j] > str[i])
            {
                std::swap(str[i], str[j]);
                values.push_back(std::stoi(str));
                std::swap(str[i], str[j]);
            }
        }
    }

    return values.size() > 0 ? *std::max_element(values.begin(), values.end()) : num;
}
