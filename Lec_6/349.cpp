//brute force approach

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        // Stores unique common elements
        vector<int> answer;

        // Compare every element of nums1 with every element of nums2
        for (int num1 : nums1) {

            for (int num2 : nums2) {

                if (num1 == num2) {

                    // Avoid inserting duplicates
                    if (find(answer.begin(), answer.end(), num1) == answer.end()) {

                        answer.push_back(num1);
                    }
                }
            }
        }

        return answer;
    }
};

//better approach - Sorting and Two Pointers (without hashset)

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        // Sort both arrays
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> answer;

        int i = 0;
        int j = 0;

        while (i < nums1.size() && j < nums2.size()) {

            if (nums1[i] < nums2[j]) {

                // Move the smaller element forward
                i++;
            }
            else if (nums1[i] > nums2[j]) {

                j++;
            }
            else {

                // Common element found
                if (answer.empty() || answer.back() != nums1[i]) {

                    // Store only if it is not already added
                    answer.push_back(nums1[i]);
                }

                i++;
                j++;
            }
        }

        return answer;
    }
};

//time complexity: O(nlogn + mlogm) - We sort both arrays first and then traverse them once.
//space complexity: O(1) - We do not use any extra space except for the answer vector.


//optimal approach - with Hashset

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        // Store unique elements of first array
        unordered_set<int> set1(nums1.begin(), nums1.end());

        // Store unique intersection elements
        unordered_set<int> intersectionSet;

        // Traverse second array
        for (int number : nums2) {

            // Check if current number exists in first array
            if (set1.count(number)) {

                // Insert into result set.
                // Set automatically avoids duplicates.
                intersectionSet.insert(number);
            }
        }

        // Convert set into vector because LeetCode expects vector<int>
        return vector<int>(intersectionSet.begin(), intersectionSet.end());
    }
};

//time complexity: O(n + m) - We traverse the entire nums1 and nums2 arrays.
//space complexity: O(n) - We use a hash set to store unique elements of nums



