//brute force approach

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        // Temporary array to store valid elements
        vector<int> temp;

        // Traverse the original array
        for (int number : nums) {

            // Copy only those elements
            // which are NOT equal to val
            if (number != val)
                temp.push_back(number);
        }

        // Copy valid elements back to original array
        for (int i = 0; i < temp.size(); i++)
            nums[i] = temp[i];

        // Number of remaining elements
        return temp.size();
    }
};

//Time Complexity: O(n) - We traverse the entire array once.
//Space Complexity: O(n) - We use a temporary array to store valid elements.

//Optimal Solution: Two Pointers approach

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        // 'write' points to the next position
        // where a valid element should be placed.
        int write = 0;

        // 'read' scans every element in the array.
        for (int read = 0; read < nums.size(); read++) {

            // Keep only elements that are NOT equal to val.
            if (nums[read] != val) {

                // Copy the valid element to its correct position.
                nums[write] = nums[read];

                // Move write pointer to the next free position.
                write++;
            }
        }

        // 'write' is exactly the number of valid elements.
        return write;
    }
};

//Time Complexity: O(n) - We traverse the entire array once.
//Space Complexity: O(1) - We do not use any extra space we modify

