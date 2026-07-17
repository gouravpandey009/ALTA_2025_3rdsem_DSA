//Brute force approach

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {

        int n = nums.size();

        // Result array
        vector<int> ans(n);

        // Follow the definition directly
        for (int i = 0; i < n; i++) {
            ans[i] = nums[nums[i]];
        }

        return ans;
    }
};


//Optimized approach

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {

        int n = nums.size();

        // Encode both old and new values
        for (int i = 0; i < n; i++) {
            nums[i] += n * (nums[nums[i]] % n);
        }

        // Extract only the new values
        for (int i = 0; i < n; i++) {
            nums[i] /= n;
        }

        return nums;
    }
};