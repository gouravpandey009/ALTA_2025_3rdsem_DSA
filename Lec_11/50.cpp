//Bruteforce approach

class Solution {
public:
    double myPow(double x, int n) {

        double ans = 1;

        for(int i=0;i<n;i++)
            ans*=x;

        return ans;
    }
};


//Time Complexity: O(n) - We traverse the entire array once to calculate the power.
//Space Complexity: O(1) - We do not use any extra space.



//method - 2 - recursive approach

class Solution {
public:

    // Recursive function to calculate x^n
    double power(double x, long long n) {

        // Base Case:
        // Any number raised to the power 0 is always 1.
        if (n == 0)
            return 1.0;

        // Solve the smaller subproblem only ONCE.
        // This avoids repeated recursive calls.
        double half = power(x, n / 2);

        // If exponent is even:
        // x^n = (x^(n/2)) * (x^(n/2))
        if (n % 2 == 0)
            return half * half;

        // If exponent is odd:
        // x^n = x * (x^(n/2)) * (x^(n/2))
        return x * half * half;
    }

    double myPow(double x, int n) {

        // Convert exponent to long long.
        // This prevents overflow when n = INT_MIN (-2147483648).
        long long exponent = n;

        // Handle negative exponent.
        // Example:
        // 2^-3 = 1 / (2^3)
        if (exponent < 0) {
            x = 1.0 / x;
            exponent = -exponent;
        }

        // Solve using Divide & Conquer.
        return power(x, exponent);
    }
};

//Time Complexity: O(logn) - We divide the exponent by 2 in each recursive call, leading to a logarithmic time complexity.
//Space Complexity: O(logn) - The recursion stack can go as deep as log(n) in the worst case, leading to a logarithmic space complexity.
