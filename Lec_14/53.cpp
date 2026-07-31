//apprach - 1 - brute force - Generate every subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        // Store the maximum subarray sum found so far.
        int maximum = INT_MIN;

        // Choose every possible starting index.
        for (int start = 0; start < nums.size(); start++) {

            int currentSum = 0;

            // Extend the subarray one element at a time.
            for (int end = start; end < nums.size(); end++) {

                currentSum += nums[end];

                // Update the answer if current subarray is better.
                maximum = max(maximum, currentSum);
            }
        }

        return maximum;
    }
};


//time complexity: O(n^2) - two nested loops
//space complexity: O(1) - only using a few variables


//approach - 2 optimal solution - Divide and Conquer (Recursive Approach)

class Solution {
public:

    // Function to calculate the maximum subarray sum
    // that crosses the middle element.

    int crossingSum(vector<int>& nums, int left, int mid, int right) {

        //Left Part

        // Stores the maximum sum ending at mid.
        int leftMax = INT_MIN;

        // Running sum while moving towards left.
        int currentSum = 0;

        // Start from mid and move towards left.
        for (int i = mid; i >= left; i--) {

            currentSum += nums[i];

            // Update the best left sum.
            leftMax = max(leftMax, currentSum);
        }


        // Right Part

        // Stores the maximum sum starting from mid + 1.
        int rightMax = INT_MIN;

        currentSum = 0;

        // Start from mid + 1 and move towards right.
        for (int i = mid + 1; i <= right; i++) {

            currentSum += nums[i];

            // Update the best right sum.
            rightMax = max(rightMax, currentSum);
        }

        // Crossing subarray =
        // Best Left Ending at Mid
        // +
        // Best Right Starting at Mid+1
        return leftMax + rightMax;
    }

    // Divide & Conquer Recursive Function

    int solve(vector<int>& nums, int left, int right) {

        // Base Case:
        // Only one element remains.
        if (left == right)
            return nums[left];

        // Find middle element.
        int mid = left + (right - left) / 2;

        // Maximum subarray completely inside left half.
        int leftAnswer = solve(nums, left, mid);

        // Maximum subarray completely inside right half.
        int rightAnswer = solve(nums, mid + 1, right);

        // Maximum subarray crossing the middle.
        int crossingAnswer = crossingSum(nums, left, mid, right);

        // Return the best among all three possibilities.
        return max({leftAnswer, rightAnswer, crossingAnswer});
    }

    int maxSubArray(vector<int>& nums) {

        // Start Divide & Conquer on the complete array.
        return solve(nums, 0, nums.size() - 1);
    }
};


//time complexity: O(nlogn) - logn levels of recursion and O(n) for crossing sum
//space complexity: O(logn) - recursion stack space



//approach - 3 - optimal solution - Kadane's Algorithm (Iterative Approach)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Initialize variables to store the maximum subarray sum found so far
        int maxSoFar = nums[0];
        // Initialize a variable to store the maximum subarray sum ending at the current index
        int maxEndingHere = nums[0];

        // Iterate through the array starting from the second element
        for (int i = 1; i < nums.size(); i++) {
            // Update the maximum subarray sum ending at the current index
            maxEndingHere = max(nums[i], maxEndingHere + nums[i]);
            // Update the maximum subarray sum found so far
            maxSoFar = max(maxSoFar, maxEndingHere);
        }

        return maxSoFar;
    }
};


//time complexity: O(n) - single pass through the array
//space complexity: O(1) - only using a few variables


//approach - 4 - optimal solution - prefix sum approach

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Initialize variables to store the maximum subarray sum found so far, the current prefix sum, and the minimum prefix sum encountered
        int max_sum = INT_MIN;
        // Initialize the current prefix sum and minimum prefix sum to 0
        int current_prefix = 0;
        // Initialize the minimum prefix sum to 0
        int min_prefix = 0;
        
        // Iterate through the array to calculate the maximum subarray sum using prefix sums
        for (int num : nums) {
            current_prefix += num;
            max_sum = max(max_sum, current_prefix - min_prefix);
            min_prefix = min(min_prefix, current_prefix);
        }
        
        return max_sum;
    }
};


//time complexity: O(n) - single pass through the array
//space complexity: O(1) - only using a few variables

//approach - 5 - optimal solution - sliding window approach

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        // Initialize variables to store the maximum subarray sum found so far and the current window sum
        int max_sum = INT_MIN;
        // Initialize the current window sum to 0
        int window_sum = 0;
        
        // Iterate through the array to calculate the maximum subarray sum using a sliding window approach
        for (int num : nums) {
            window_sum += num;
            max_sum = max(max_sum, window_sum);
            
            if (window_sum < 0) {
                window_sum = 0;
            }
        }
        
        return max_sum;
    }
};

//time complexity: O(n) - single pass through the array
//space complexity: O(1) - only using a few variables



