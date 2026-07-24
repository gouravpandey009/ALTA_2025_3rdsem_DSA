//brute force approach - simple traversal

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        vector<int> answer;

        // Check every number from 1 to n
        for (int number = 1; number <= nums.size(); number++) {

            bool found = false;

            // Search the current number in the array
            for (int value : nums) {

                if (value == number) {

                    found = true;
                    break;
                }
            }

            // Number was not found
            if (!found)
                answer.push_back(number);
        }

        return answer;
    }
};


//Time Complexity: O(n^2) - We traverse the entire array for every number from 1 to n.
//Space Complexity: O(1) - We do not use any extra space, except for


//better approach - using hashset

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        // Store every number in a HashSet
        unordered_set<int> seen(nums.begin(), nums.end());

        vector<int> answer;

        // Check which numbers are missing
        for (int number = 1; number <= nums.size(); number++) {

            if (!seen.count(number))
                answer.push_back(number);
        }

        return answer;
    }
};

//Time Complexity: O(n) - We traverse the entire array once to store the numbers and then again to find the missing numbers.
//Space Complexity: O(n) - We use a hashset to store the numbers, which takes O(n) space.


//optimal approach - using index marking

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        // Traverse every element
        for (int i = 0; i < nums.size(); i++) {

            // Use abs() because the element may already
            // have been marked negative.
            int index = abs(nums[i]) - 1;

            // Mark this index as visited by making it negative.
            // Check first to avoid flipping it back to positive.
            if (nums[index] > 0)
                nums[index] = -nums[index];
        }

        vector<int> answer;

        // Positive indices correspond to missing numbers.
        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] > 0)
                answer.push_back(i + 1);
        }

        return answer;
    }
};


//time Complexity: O(n) - We traverse the entire array twice, which takes O(n) time.
//Space Complexity: O(1) - We do not use any extra space, except for the output vector, which does not count towards space complexity.