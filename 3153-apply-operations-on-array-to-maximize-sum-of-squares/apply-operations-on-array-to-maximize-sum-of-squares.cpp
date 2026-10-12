
class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> count(32, 0);
        int MOD = 1000000007;

        for (int num : nums) {
            for (int b = 0; b < 32; b++) {
                if (num & (1 << b)) {
                    count[b]++;
                }
            }
        }

        long long result = 0;

        while (k > 0) {
            long long curr = 0;

            for (int b = 0; b < 31; b++) {
                if (count[b] > 0) {
                    count[b]--;
                    curr = curr | (1LL << b);
                }
            }

            result = (result + curr * curr) % MOD;
            k--;
        }

        return result;
    }
};
