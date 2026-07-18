//Brute Force Approach
//This gives TLE for large n, but is simple to understand and implement.

class Solution {
public:

    int tribonacci(int n) {

        // Base case: First Tribonacci number
        if (n == 0)
            return 0;

        // Base case: Second and third Tribonacci numbers
        if (n == 1 || n == 2)
            return 1;

        // Recursive definition:
        // Current Tribonacci number depends on previous 3 numbers
        return tribonacci(n - 1)
             + tribonacci(n - 2)
             + tribonacci(n - 3);
    }
};


//Each call creates

// 3 more calls.

// Recursion tree grows exponentially

// Approximate complexity

// O(3^n)

// Space

// Maximum recursion depth

// n

// Therefore

// Time : Exponential

// Space : O(n)


//Optimized Approach

//Why we need DP?

// Look here

// T5

// needs

// T4

// T3

// T2

// Then

// T4

// again needs

// T3

// We already solved

// T3

// Why solve it again?

// Can we store it?

// YES

// This is exactly how Dynamic Programming works we will store the results of subproblems and reuse them.

// We will study DP Later in thiscourse.

//This is known as Memoization (TOP- DOWN), we will store the results of subproblems in an array and reuse them when needed.


class Solution {
public:

    // DP array to store already computed Tribonacci values
    vector<int> dp;

    int solve(int n) {

        // Base cases
        if (n == 0)
            return 0;

        if (n == 1 || n == 2)
            return 1;

        // If already computed, return directly
        if (dp[n] != -1)
            return dp[n];

        // Compute once and store the answer
        dp[n] = solve(n - 1)
              + solve(n - 2)
              + solve(n - 3);

        return dp[n];
    }

    int tribonacci(int n) {

        // Initialize DP array with -1 (meaning not computed yet)
        dp.assign(n + 1, -1);

        return solve(n);
    }
};

// Later on we can also do space optimization and reduce the space complexity to O(1) by storing only the last 3 computed values instead of the entire DP array.


