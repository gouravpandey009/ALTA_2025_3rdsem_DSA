//brute force approach

class Solution {
public:
    bool isPowerOfThree(int n) {

        // Negative numbers and zero
        // can never be powers of 3.
        if (n <= 0)
            return false;

        // Start from 3^0 = 1
        long long power = 1;

        // Keep generating powers of 3
        while (power < n) {

            power *= 3;
        }

        // If generated value equals n,
        // then n is a power of three.
        return power == n;
    }
};

//Time Complexity: O(log3(n)) - We keep multiplying by 3 until we reach or exceed n.
//Space Complexity: O(1) - We do not use any extra space.


//better approach - repeated division

class Solution {
public:
    bool isPowerOfThree(int n) {

        // Powers of three are always positive.
        if (n <= 0)
            return false;

        // Keep dividing by 3
        // while the number is divisible.
        while (n % 3 == 0) {

            n /= 3;
        }

        // If we finally reach 1,
        // then original number was
        // exactly a power of 3.
        return n == 1;
    }
};

//Time Complexity: O(log3(n)) - We keep dividing by 3 until we reach 1.
//Space Complexity: O(1) - We do not use any extra space.

//optimal approach -  recursive approach

class Solution {
public:

    bool isPowerOfThree(int n) {

        // Negative numbers and zero
        // are never powers of three.
        if (n <= 0)
            return false;

        // Base case:
        // 3^0 = 1
        if (n == 1)
            return true;

        // If not divisible by 3,
        // recursion cannot continue.
        if (n % 3 != 0)
            return false;

        // Reduce the problem size.
        return isPowerOfThree(n / 3);
    }
};

//Time Complexity: O(log3(n)) - We keep dividing by 3 until we reach 1.
//Space Complexity: O(log3(n)) - The recursion stack can go as deep as log3(n) in the worst case.

