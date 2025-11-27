class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
         int n = nums.size();
        // prefix sum
        long long ps = 0;
        const long long INF = LLONG_MAX / 4;
        vector<long long> minPref(k, INF);

        // prefix index 0 -> ps[0] = 0, mod = 0
        minPref[0] = 0;

        long long ans = LLONG_MIN;
        for (int r = 1; r <= n; ++r) {
            ps += nums[r-1];           // ps == prefix sum up to index r (exclusive of r)
            int rem = r % k;
            if (minPref[rem] != INF) {
                ans = max(ans, ps - minPref[rem]);
            }
            // update the minimum prefix sum seen for this remainder class using current ps
            // (this allows future r' with same remainder to form subarray length divisible by k)
            minPref[rem] = min(minPref[rem], ps);
        }

        return ans;
    }
};