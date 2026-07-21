//brute force approach

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        int n = nums.size();

        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j < n; j++) {

                if (nums[i] == nums[j])
                    return true;
            }
        }

        return false;
    }
};

//Time Complexity: O(n^2) - We traverse the entire array twice.
//Space Complexity: O(1) - We do not use any extra space.

//better approach

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++) {

            if (nums[i] == nums[i - 1])
                return true;
        }

        return false;
    }
};

//Time Complexity: O(nlogn) - We sort the array first and then traverse it once.
//Space Complexity: O(1) - We do not use any extra space.

//optimal approach

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        unordered_set<int> seen;

        for (int number : nums) {

            // Duplicate found
            if (seen.count(number))
                return true;

            // Store current number
            seen.insert(number);
        }

        return false;
    }
};

//Time Complexity: O(n) - We traverse the entire array once.
//Space Complexity: O(n) - We use a hash set to store unique elements.