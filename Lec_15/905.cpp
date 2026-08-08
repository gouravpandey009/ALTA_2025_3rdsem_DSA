//brute force approach - two passes

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {

        // Temporary array to store the partitioned result.
        vector<int> answer;

        // First, place all even numbers.
        for (int number : nums) {

            // A number is even when remainder after
            // division by 2 is zero.
            if (number % 2 == 0) {

                answer.push_back(number);
            }
        }

        // Then, place all odd numbers.
        for (int number : nums) {

            // A number is odd when remainder is not zero.
            if (number % 2 != 0) {

                answer.push_back(number);
            }
        }

        // Return the array with evens followed by odds.
        return answer;
    }
};

//time complexity: O(n) - two passes through the array
//space complexity: O(n) - using a temporary array to store the result

//optimal solution - two pointers - single pass through the array

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {

        // Pointer starting from the left side.
        // The left side should contain even numbers.
        int left = 0;

        // Pointer starting from the right side.
        // The right side should contain odd numbers.
        int right = nums.size() - 1;

        // Continue while there is an unprocessed region.
        while (left < right) {

            // Move left forward while the current element
            // is already in its correct group (even).
            while (left < right && nums[left] % 2 == 0) {
                left++;
            }

            // Move right backward while the current element
            // is already in its correct group (odd).
            while (left < right && nums[right] % 2 != 0) {
                right--;
            }

            // At this point:
            // nums[left] is odd  -> should go right.
            // nums[right] is even -> should go left.
            //
            // Therefore, swap them.
            if (left < right) {
                swap(nums[left], nums[right]);

                // Move both pointers because the swapped
                // elements are now in their correct groups.
                left++;
                right--;
            }
        }

        // The array is now partitioned as:
        // EVEN numbers | ODD numbers
        return nums;
    }
};

//time complexity: O(n) - single pass through the array
//space complexity: O(1) - only using a few variables
