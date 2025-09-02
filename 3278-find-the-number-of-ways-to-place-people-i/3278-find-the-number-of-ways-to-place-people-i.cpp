class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
         int n = points.size();
        int count = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];

                // allow equality (same row or same column is valid)
                if (x1 <= x2 && y1 >= y2) {
                    bool ok = true;
                    for (int k = 0; k < n; ++k) {
                        if (k == i || k == j) continue;
                        int x = points[k][0], y = points[k][1];
                        // inclusive check — no other point allowed in rectangle or on its border
                        if (x1 <= x && x <= x2 && y2 <= y && y <= y1) {
                            ok = false;
                            break;
                        }
                    }
                    if (ok) ++count;
                }
            }
        }
        return count;
    }
};