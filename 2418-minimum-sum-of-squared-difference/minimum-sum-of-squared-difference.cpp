
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;

        vector<long long> diff(n);
        long long total = 0;
        long long high = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            total += diff[i];
            high = max(high, diff[i]);
        }

        if (total <= k)
            return 0;

        long long low = 0;

        while (low < high) {
            long long mid = low + (high - low) / 2;
            long long need = 0;

            for (int i = 0; i < n; i++) {
                if (diff[i] > mid)
                    need += diff[i] - mid;
            }

            if (need <= k)
                high = mid;
            else
                low = mid + 1;
        }

        long long level = low;
        long long need = 0;
        long long ans = 0;
        long long count = 0;

        for (int i = 0; i < n; i++) {
            if (diff[i] > level)
                need += diff[i] - level;

            if (diff[i] >= level)
                count++;

            long long d = min(diff[i], level);
            ans += d * d;
        }

        long long remaining = k - need;
        ans -= remaining * (2 * level - 1);

        return ans;
    }
};
