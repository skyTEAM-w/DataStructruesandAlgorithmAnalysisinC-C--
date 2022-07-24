#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool sequenceReconstruction(vector<int> &nums, vector<vector<int>> &sequences)
    {
        int n = nums.size();

        vector<int> indegree(n + 1);
        vector<unordered_set<int>> grah(n + 1);

        for (auto &sequence : sequences)
        {
            for (int i = 1; i < squence.size(); i++)
            {
                int pre = squence[i - 1];
                int next = squence[i];
                if (!grah[pre].count(next))
                {
                    grah[pre].emplace(next);
                    indegree[next]++;
                }
            }
        }

        queue<int> qu;
        for (int i = 1; i <= n; i++)
        {
            if (indegree[i] == 0)
            {
                qu.emplace(i);
            }
        }

        while (!qu.empty())
        {
            if (qu.size() > 1)
            {
                return false;
            }
            int num = qu.front();
            qu.pop();
            for (auto next : grah[num])
            {
                indegree[next]--;
                if (indegree[next] == 0)
                {
                    qu.emplace(next);
                }
            }
        }
        return true;
    }
};

int main()
{
}