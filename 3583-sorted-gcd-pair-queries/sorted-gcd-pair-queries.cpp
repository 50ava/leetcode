class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxVal = *max_element(nums.begin(), nums.end());
        
        // freq[v] = count of v in nums
        vector<int> freq(maxVal + 1, 0);
        for (int v : nums) freq[v]++;
        
        // cnt[g] = number of elements divisible by g
        vector<long long> cnt(maxVal + 1, 0);
        for (int g = 1; g <= maxVal; g++) {
            for (int multiple = g; multiple <= maxVal; multiple += g) {
                cnt[g] += freq[multiple];
            }
        }
        
        // exact[g] = number of pairs whose gcd is exactly g
        vector<long long> exact(maxVal + 1, 0);
        for (int g = maxVal; g >= 1; g--) {
            long long c = cnt[g];
            long long totalPairs = c * (c - 1) / 2;
            for (int multiple = 2 * g; multiple <= maxVal; multiple += g) {
                totalPairs -= exact[multiple];
            }
            exact[g] = totalPairs;
        }
        
        // prefix[g] = number of pairs with gcd <= g
        vector<long long> prefix(maxVal + 1, 0);
        long long running = 0;
        for (int g = 1; g <= maxVal; g++) {
            running += exact[g];
            prefix[g] = running;
        }
        
        // answer each query via binary search (smallest g with prefix[g] > q)
        vector<int> answer;
        answer.reserve(queries.size());
        for (long long q : queries) {
            int lo = 1, hi = maxVal, res = maxVal;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (prefix[mid] > q) {
                    res = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            answer.push_back(res);
        }
        
        return answer;
    }
};