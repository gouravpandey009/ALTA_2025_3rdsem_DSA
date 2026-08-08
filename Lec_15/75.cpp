//brute force approach - sort the array and count the number of 0s, 1s and 2s
class Solution {
public:
    void sortColors(vector<int>& nums) {

        // Count the number of 0s, 1s and 2s.
        int count0 = 0;
        int count1 = 0;
        int count2 = 0;

        // Traverse the array once.
        for (int num : nums) {

            if (num == 0)
                count0++;

            else if (num == 1)
                count1++;

            else
                count2++;
        }

        // Rewrite the array.
        int index = 0;

        // Place all 0s.
        while (count0--)
            nums[index++] = 0;

        // Place all 1s.
        while (count1--)
            nums[index++] = 1;

        // Place all 2s.
        while (count2--)
            nums[index++] = 2;
    }
};

//time complexity: O(n) - single pass through the array
//space complexity: O(1) - only using a few variables


//optimal solution - Dutch National Flag Algorithm - single pass through the array

class Solution {
public:
    void sortColors(vector<int>& nums) {

        // 'low' points to the position where the next 0 should be placed.
        int low = 0;

        // 'mid' is used to traverse the array.
        int mid = 0;

        // 'high' points to the position where the next 2 should be placed.
        int high = nums.size() - 1;

        // Continue until the unknown region becomes empty.
        while (mid <= high) {

            // ---------------- Case 1 ----------------
            // Current element is 0.
            if (nums[mid] == 0) {

                // Place the 0 into the left region.
                swap(nums[low], nums[mid]);

                // Left region grows.
                low++;

                // Move to the next unknown element.
                mid++;
            }

            // ---------------- Case 2 ----------------
            // Current element is already 1.
            else if (nums[mid] == 1) {

                // It already belongs to the middle region.
                mid++;
            }

            // ---------------- Case 3 ----------------
            // Current element is 2.
            else {

                // Move the 2 to the right region.
                swap(nums[mid], nums[high]);

                // Right region grows.
                high--;

                // IMPORTANT:
                // Do NOT increment mid here.
                // The new element at 'mid' has not been processed yet.
            }
        }
    }
};

//time complexity: O(n) - single pass through the array
//space complexity: O(1) - only using a few variables

