//brute force approach - sort

class Solution {
public:
    int thirdMax(vector<int>& nums) {

        // Sort in descending order
        sort(nums.begin(), nums.end(), greater<int>());

        vector<int> distinct;

        // Collect only distinct values
        for (int number : nums) {

            if (distinct.empty() || distinct.back() != number)
                distinct.push_back(number);
        }

        // If third distinct maximum exists
        if (distinct.size() >= 3)
            return distinct[2];

        // Otherwise return maximum
        return distinct[0];
    }
};


//Time Complexity: O(nlogn) - We sort the array first, which takes O(nlogn) time, and then traverse it once to collect distinct values.
//Space Complexity: O(n) - We use a separate vector to store distinct values, which


//better solution - using set

class Solution {
public:
    int thirdMax(vector<int>& nums) {

        // Stores unique values in sorted order
        set<int> uniqueNumbers;

        for (int number : nums) {

            uniqueNumbers.insert(number);

            // Keep only the largest 3 elements
            if (uniqueNumbers.size() > 3)
                uniqueNumbers.erase(uniqueNumbers.begin());
        }

        // If fewer than 3 distinct numbers exist,
        // return the maximum.
        if (uniqueNumbers.size() < 3)
            return *uniqueNumbers.rbegin();

        // Otherwise return the smallest among the top 3,
        // which is the third maximum.
        return *uniqueNumbers.begin();
    }
};

//time Complexity: O(nlog3) = O(n) - We traverse the entire array once, and each insertion into the set takes O(log3) time since we maintain at most 3 elements in the set.
//Space Complexity: O(1) - We use a set to store at most 3 distinct values, which takes constant space.


//optimal solution - using 3 variables (one pass)

class Solution {
public:
    int thirdMax(vector<int>& nums) {

        // Use long long to safely handle INT_MIN.
        // Initialize with a value smaller than any int.
        long long first = LLONG_MIN;
        long long second = LLONG_MIN;
        long long third = LLONG_MIN;

        // Traverse every number exactly once
        for (int number : nums) {

            // Ignore duplicate values already stored
            if (number == first || number == second || number == third)
                continue;

            // Found a new largest number
            if (number > first) {

                // Shift existing rankings
                third = second;
                second = first;
                first = number;
            }

            // Found a new second largest
            else if (number > second) {

                third = second;
                second = number;
            }

            // Found a new third largest
            else if (number > third) {

                third = number;
            }
        }

        // If third maximum doesn't exist,
        // return the maximum.
        if (third == LLONG_MIN)
            return first;

        return third;
    }
};

//Time Complexity: O(n) - We traverse the entire array once.
//Space Complexity: O(1) - We use only a fixed number of variables, regardless

