//brute force approach

class Solution {
public:
    int search(vector<int>& nums, int target) {

        // Check every element one by one.
        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] == target) {
                return i;
            }
        }

        // Target does not exist.
        return -1;
    }
};

//Time Complexity: O(n) - We traverse the entire array once.
//Space Complexity: O(1) - We do not use any extra space.

//optimal approach - binary search


class Solution {
public:
    int search(vector<int>& nums, int target) {

        int left = 0;
        int right = (nums.size()) - 1;

        while (left <= right) {

            // Overflow-safe middle index.
            int mid = left + (right - left) / 2;

            // Target found.
            if (nums[mid] == target) {
                return mid;
            }

            // Target can only exist in the right half.
            if (nums[mid] < target) {
                left = mid + 1;
            }

            // Target can only exist in the left half.
            else {
                right = mid - 1;
            }
        }

        // Search space became empty.
        return -1;
    }
};

//Time Complexity: O(logn) - We divide the search space in half each time.
//Space Complexity: O(1) - We do not use any extra space.