//brute force - try every possible pair of buying and selling days

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        // Stores the maximum profit found so far.
        int maxProfit = 0;

        int n = prices.size();

        // Try every possible buying day.
        for (int buy = 0; buy < n; buy++) {

            // Try every selling day after buying.
            for (int sell = buy + 1; sell < n; sell++) {

                // Calculate current profit.
                int profit = prices[sell] - prices[buy];

                // Update maximum profit if better.
                maxProfit = max(maxProfit, profit);
            }
        }

        // If every transaction gives loss,
        // maxProfit remains 0.
        return maxProfit;
    }
};


//time complexity: O(n^2) - two nested loops
//space complexity: O(1) - only using a few variables


//optimal solution - carry forward technique - single pass through the array

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        // Store the minimum stock price
        // seen so far.
        int minimumPrice = prices[0];

        // Store the best profit found.
        int maximumProfit = 0;

        // Traverse every day's price.
        for (int price : prices) {

            // Update the minimum buying price.
            minimumPrice = min(minimumPrice, price);

            // Profit if we sell today.
            int currentProfit = price - minimumPrice;

            // Update the best profit.
            maximumProfit = max(maximumProfit, currentProfit);
        }

        return maximumProfit;
    }
};


//time complexity: O(n) - single pass through the array
//space complexity: O(1) - only using a few variables

