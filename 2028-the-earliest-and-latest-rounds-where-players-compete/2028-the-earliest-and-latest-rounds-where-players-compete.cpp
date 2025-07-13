#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string, pair<int, int>> memo;

    pair<int, int> dfs(int n, int f, int s) {
        if (f + s == n + 1) return {1, 1};  // meet in this round
        if (f + s > n + 1) return dfs(n, n + 1 - s, n + 1 - f);  // flip to normalize

        string key = to_string(n) + "," + to_string(f) + "," + to_string(s);
        if (memo.count(key)) return memo[key];

        int left = (n + 1) / 2;
        int minR = INT_MAX, maxR = INT_MIN;

        for (int mask = 0; mask < (1 << left); ++mask) {
            vector<int> win;
            int i = 1, j = n, pos = 0;
            bool playersMet = false;

            while (i < j) {
                int a = i, b = j;
                if ((a == f && b == s) || (a == s && b == f)) {
                    playersMet = true;
                    break;
                }

                if (a == f || b == f) win.push_back(f);
                else if (a == s || b == s) win.push_back(s);
                else win.push_back((mask >> pos++) & 1 ? a : b);
                i++; j--;
            }
            if (playersMet) continue;

            if (i == j) win.push_back(i);

            int nf = -1, ns = -1;
            sort(win.begin(), win.end());
            for (int k = 0; k < win.size(); ++k) {
                if (win[k] == f) nf = k + 1;
                if (win[k] == s) ns = k + 1;
            }
            if (nf != -1 && ns != -1) {
                auto [a, b] = dfs(win.size(), nf, ns);
                minR = min(minR, a + 1);
                maxR = max(maxR, b + 1);
            }
        }

        return memo[key] = {minR, maxR};
    }

    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        return {dfs(n, firstPlayer, secondPlayer).first,
                dfs(n, firstPlayer, secondPlayer).second};
    }
};


