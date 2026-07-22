//bruteforce approach

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        // Traverse every element one by one
        for (int i = 0; i < nums.size(); i++) {

            // First element greater than or equal to target
            // is the required position.
            if (nums[i] >= target)
                return i;
        }

        // Target is greater than every element,
        // so insert at the end.
        return nums.size();
    }
};

//Time Complexity: O(n) - We traverse the entire array once.
//Space Complexity: O(1) - We do not use any extra space.


//optimal approach - binary search

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        // Binary Search boundaries
        int left = 0;
        int right = nums.size() - 1;

        // Continue until search space becomes empty
        while (left <= right) {

            // Compute middle safely to avoid integer overflow
            int mid = left + (right - left) / 2;

            // If middle element is smaller,
            // target can only exist on the right side.
            if (nums[mid] < target) {

                left = mid + 1;
            }
            else {

                // nums[mid] >= target
                // Current index may be the answer,
                // but there might be an earlier valid position.
                right = mid - 1;
            }
        }

        // 'left' is the first position where
        // target can be inserted.
        return left;
    }
};
//Time Complexity: O(logn) - We divide the search space in half each time.
//Space Complexity: O(1) - We do not use any extra space.   