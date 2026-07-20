//brute force approach

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        vector<int> temp;

        // Store all non-zero elements
        for (int num : nums) {
            if (num != 0)
                temp.push_back(num);
        }

        // Add zeroes
        while (temp.size() < nums.size())
            temp.push_back(0);

        // Copy back
        nums = temp;
    }
};

//TC: o(n)
//SC: O(N) - extra space for temp vector


//Optimal Solution: Two Pointers approach

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        // Position where the next non-zero element should be placed
        int write = 0;

        // Scan the entire array
        for (int read = 0; read < nums.size(); read++) {

            // Found a non-zero element
            if (nums[read] != 0) {

                // Move it to its correct position
                swap(nums[write], nums[read]);

                // Next position for a non-zero
                write++;
            }
        }
    }
};

//TC: O(n)
//SC: O(1) - no extra space used

