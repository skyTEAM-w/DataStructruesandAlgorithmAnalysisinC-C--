#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int intersectionSizeTwo(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b)
             {
            if (a[1] == b[1])
            {
                return a[0] > b[0];
            }
            else
            {
                return a[1] < b[1];
            } });
        vector<int> ans;
        for (const auto &interval : intervals)
        {
            int a = interval[0];
            int b = interval[1];
            if (ans.empty())
            {
                ans = {b - 1, b};
            }
            else
            {
                size_t size = ans.size();
                if(ans[size - 1] < a)
                {
                    ans.push_back(b - 1);
                }
                if(ans[size - 2] < a)
                {
                    ans.push_back(b);
                }
            }
        }
        return ans.size();
    }
};