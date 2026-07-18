//Approach 1: Brute force approach

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {

        // Get total number of elements in input vector
        int n = nums.size();

        // Initialize output vector to store smaller element counts
        vector<int> answer(n);

        // Loop through each element as the target for comparison
        for (int i = 0; i < n; i++) {

            // Initialize counter for elements smaller than nums[i]
            int count = 0;

            // Loop through all elements to perform comparison
            for (int j = 0; j < n; j++) {

                // Increment count if a smaller element is found
                if (nums[j] < nums[i])
                    count++;
            }

            // Assign total count of smaller numbers to current index
            answer[i] = count;
        }

        // Return final array containing all calculated counts
        return answer;
    }
};


//Time Complexity: O(n^2) - Two nested loops, each iterating through the array of size n.
//Space Complexity: O(1) - Only using a constant amount of extra space for the counter and loop variables.


//Approach 2: Counting Sort Approach

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {

        // Create a copy of original vector to preserve indices
        vector<int> sorted = nums;

        // Sort copy in ascending order to group smaller elements first
        sort(sorted.begin(), sorted.end());

        // Map to store the very first occurrence index of each number
        unordered_map<int, int> firstIndex;

        // Loop through sorted array to map numbers to smaller element counts
        for (int i = 0; i < sorted.size(); i++) {

            // Only map the first occurrence so duplicates don't overwrite it
            if (!firstIndex.count(sorted[i]))
                firstIndex[sorted[i]] = i; // Index 'i' equals count of smaller numbers
        }

        // Vector to store final output matching original array order
        vector<int> answer;

        // Map original elements to their pre-calculated counts
        for (int x : nums)
            answer.push_back(firstIndex[x]);

        // Return the populated results
        return answer;
    }
};


//Time Complexity: O(n log n) - Sorting the array takes O(n log n) time, and mapping takes O(n) time.
//Space Complexity: O(n) - Storing the sorted array and the mapping requires additional space proportional to the input size.


//Approach 3: Frequency Array Approach

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {

        // Fixed-size frequency array for constraints 0 <= nums[i] <= 100
        vector<int> frequency(101, 0);

        // Count occurrences of each number in the input array
        for (int number : nums)
            frequency[number]++;

        // Compute running prefix sum to know how many elements exist up to index i
        for (int i = 1; i <= 100; i++)
            frequency[i] += frequency[i - 1];

        // Result vector to store counts for the original array order
        vector<int> answer;

        // Map each original number to its count of smaller elements
        for (int number : nums) {

            // Zero has no elements smaller than itself
            if (number == 0)
                answer.push_back(0);
            else
                // Prefix sum at (number - 1) gives count of all smaller elements
                answer.push_back(frequency[number - 1]);
        }

        // Return the final linear-time calculated result
        return answer;
    }
};

//Time Complexity: O(n) - Counting frequencies and calculating prefix sums both take linear time.
//Space Complexity: O(1) - The frequency array has a fixed size of 101




