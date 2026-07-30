//brute force approach - check every version

class Solution {
public:
    int firstBadVersion(int n) {

        // Check every version one by one
        for (int version = 1; version <= n; version++) {

            // First bad version found
            if (isBadVersion(version))
                return version;
        }

        return -1;
    }
};

//time Complexity: O(n) - We check every version from 1 to n.
//space Complexity: O(1) - We do not use any extra space.



//optimal approach - binary search


// The API is already defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n; // Range: 1 to n (1-indexed)
        
        while (left < right) {
            // Midpoint calculation designed to prevent integer overflow
            int mid = left + (right - left) / 2;
            
            // If mid is bad, answer is mid or further left. Else, it is strictly to the right.
            if (isBadVersion(mid)) right = mid;
            else left = mid + 1;
        }
        return left; // Convergence point (left == right) is the first bad version
    }
};

//time Complexity: O(log n) - We halve the search space with each iteration.
//space Complexity: O(1) - We do not use any extra space.
