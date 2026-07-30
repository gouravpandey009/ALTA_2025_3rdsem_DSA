//brute force approach - simulation / track one by one

class Solution {
public:
    int findTheWinner(int n, int k) {

        // Queue stores all players
        queue<int> players;

        // Initially every player is alive
        for (int player = 1; player <= n; player++) {
            players.push(player);
        }

        // Continue until only one player survives
        while (players.size() > 1) {

            // Rotate the first (k-1) players
            // by moving them from front to back.
            for (int count = 1; count < k; count++) {

                players.push(players.front());
                players.pop();
            }

            // The kth player is eliminated.
            players.pop();
        }

        // Last remaining player is the winner.
        return players.front();
    }
};

//Time Complexity: O(n*k) - In the worst case, we may have to eliminate n-1 players, and for each elimination, we rotate k-1 players.
//Space Complexity: O(n) - We use a queue to store all players, which takes O(n) space.


//optimal approach - Josephus problem - Recursive formula

class Solution {
public:

    // Returns winner using 0-based indexing
    int josephus(int n, int k) {

        // Base case:
        // Only one player remains.
        if (n == 1)
            return 0;

        // Solve smaller problem and
        // convert answer to current circle.
        return (josephus(n - 1, k) + k) % n;
    }

    int findTheWinner(int n, int k) {

        // Convert 0-based answer
        // into 1-based player number.
        return josephus(n, k) + 1;
    }
};

//Time Complexity: O(n) - We solve the problem recursively for n players.
//Space Complexity: O(n) - The recursion stack can go as deep as n in the worst case.
