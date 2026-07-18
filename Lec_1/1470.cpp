//Bruteforce Approach

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {

        // This vector will store the final shuffled array
        vector<int> answer;

        // Reserve space beforehand to avoid multiple reallocations.
        // Final answer will always contain exactly 2*n elements.
        answer.reserve(2 * n);

        // Traverse only the first half of the array.
        for (int i = 0; i < n; i++) {

            // Add the current element from the first half.
            answer.push_back(nums[i]);

            // Add its corresponding element from the second half.
            answer.push_back(nums[i + n]);
        }

        // Return the shuffled array.
        return answer;
    }
};


//Optimized Approach

//In-place Encoding 


// If the constraints guarantee:

// nums[i] <= 1000

// we can encode two numbers into one integer.

// Example:

// encoded = first + second * 1024

// Later recover them using:

// first = encoded % 1024
// second = encoded / 1024

// This allows an O(1) extra space solution.

//However, this relies on the value limit and is not a general technique.