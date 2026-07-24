//methtod - 1 - bruteforce apparoach - simple traversal

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n = nums.size();

        for (int i = 0; i < n; i++) {

            int count = 0;

            for (int j = 0; j < n; j++) {

                if (nums[i] == nums[j])
                    count++;
            }

            if (count > n / 2)
                return nums[i];
        }

        return -1;
    }
};

//Time Complexity: O(n^2) - We traverse the entire array for every element in the array.
//Space Complexity: O(1) - We do not use any extra space.

//method - 2 - sorting approach

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        return nums[nums.size() / 2];
    }
};

//Time Complexity: O(nlogn) - We sort the array first, which takes O(nlogn) time, and then access the middle element.
//Space Complexity: O(1) - We do not use any extra space.


//method - 3 - hash map approach

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        unordered_map<int, int> frequency;

        for (int number : nums) {

            frequency[number]++;

            if (frequency[number] > nums.size() / 2)
                return number;
        }

        return -1;
    }
};

//Time Complexity: O(n) - We traverse the entire array once.
//Space Complexity: O(n) - We use a hash map to store the frequency of each


//method - 4 - Boyer-Moore Voting Algorithm

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int candidate = 0;
        int count = 0;

        for (int number : nums) {

            // Choose a new candidate
            if (count == 0)
                candidate = number;

            // Same candidate gains a vote
            if (number == candidate)
                count++;
            else
                count--;
        }

        return candidate;
    }
};

//Time Complexity: O(n) - We traverse the entire array once.
//Space Complexity: O(1) - We do not use any extra space.