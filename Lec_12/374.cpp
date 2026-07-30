//brute force approach - gueess every number from 0 to n

/** Forward declaration of guess API.
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {

        // Try every number one by one.
        for (int i = 1; i <= n; i++) {

            // If API says correct,
            // return the answer.
            if (guess(i) == 0)
                return i;
        }

        return -1;
    }
};

//time Complexity: O(n) - We check every number from 1 to n.
//space Complexity: O(1) - We do not use any extra space.


//optimal approach - binary search

/** Forward declaration of guess API.
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {

        // Binary Search boundaries
        int left = 1;
        int right = n;

        // Continue until answer is found
        while (left <= right) {

            // Safe midpoint calculation
            // Avoids integer overflow.
            int mid = left + (right - left) / 2;

            // Call the provided API
            int result = guess(mid);

            // Correct guess
            if (result == 0)
                return mid;

            // Guess is too high
            else if (result == -1)
                right = mid - 1;

            // Guess is too low
            else
                left = mid + 1;
        }

        // Control should never reach here
        return -1;
    }
};

//time Complexity: O(log n) - We halve the search space with each iteration.
//space Complexity: O(1) - We do not use any extra space.

