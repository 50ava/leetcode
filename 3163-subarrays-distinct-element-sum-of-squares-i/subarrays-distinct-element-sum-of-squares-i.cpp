class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        // Step 1: pick every starting index i
        for (int i = 0; i < n; i++) {
            set<int> seen;  // distinct values in the current subarray

            // Step 2: extend the subarray to every ending index j
            for (int j = i; j < n; j++) {
                seen.insert(nums[j]);

                // Step 3: add (distinct count)^2
                ans += seen.size() * seen.size();
            }
        }

        // Step 4: return the total
        return ans;
    }
};