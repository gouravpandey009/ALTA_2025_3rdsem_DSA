//method - 1 - brute force approach

class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n = nums.size();

        // Check every number from 0 to n
        for (int number = 0; number <= n; number++) {

            bool found = false;

            // Search the entire array
            for (int value : nums) {

                if (value == number) {
                    found = true;
                    break;
                }
            }

            if (!found)
                return number;
        }

        return -1;
    }
};


//Time Complexity: O(n^2) - We traverse the entire array for every number from 0 to n.
//Space Complexity: O(1) - We do not use any extra space.


//method - 2 - sorting approach

class Solution {
public:
    int missingNumber(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] != i)
                return i;
        }

        return nums.size();
    }
};


//Time Complexity: O(nlogn) - We sort the array first, which takes O(nlogn) time, and then traverse it once.
//Space Complexity: O(1) - We do not use any extra space.

//method - 3 - hashset approach

class Solution {
public:
    int missingNumber(vector<int>& nums) {

        unordered_set<int> seen;

        // Store all numbers
        for (int number : nums)
            seen.insert(number);

        // Find the missing number
        for (int number = 0; number <= nums.size(); number++) {

            if (!seen.count(number))
                return number;
        }

        return -1;
    }
};

//Time Complexity: O(n) - We traverse the entire array once to store the numbers and then again to find the missing number.
//Space Complexity: O(n) - We use a hashset to store the numbers, which takes O(n) space.

//method - 4 - optimal approach using sum formula

class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n = nums.size();

        int expectedSum = n * (n + 1) / 2;

        int actualSum = 0;

        for (int number : nums)
            actualSum += number;

        return expectedSum - actualSum;
    }
};

//Time Complexity: O(n) - We traverse the entire array once to calculate the actual sum.
//Space Complexity: O(1) - We do not use any extra space.

//method - 5 - optimal approach using XOR

class Solution {
public: 
    int missingNumber(vector<int>& nums) {

        int n = nums.size();

        int xorAll = 0;

        // XOR all numbers from 0 to n
        for (int number = 0; number <= n; number++)
            xorAll ^= number;

        int xorNums = 0;

        // XOR all numbers in the array
        for (int number : nums)
            xorNums ^= number;

        // The missing number is the XOR of the two results
        return xorAll ^ xorNums;
    }
};


//Time Complexity: O(n) - We traverse the entire array once to calculate the XOR of the numbers.
//Space Complexity: O(1) - We do not use any extra space.