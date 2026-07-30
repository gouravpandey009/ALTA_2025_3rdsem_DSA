//optimized solution

class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {

        // visited[i] = true means friend (i + 1) has received the ball.
        vector<bool> visited(n, false);

        // Friend 1 corresponds to index 0.
        int current = 0;

        // First friend starts with the ball.
        visited[current] = true;

        // Round number.
        int turn = 1;

        while (true) {

            // Calculate the next friend.
            current = (current + turn * k) % n;

            // If this friend already received the ball,
            // the game ends.
            if (visited[current])
                break;

            // Mark the friend as visited.
            visited[current] = true;

            // Move to the next round.
            turn++;
        }

        vector<int> answer;

        // Friends who never received the ball are the losers.
        for (int i = 0; i < n; i++) {

            if (!visited[i])
                answer.push_back(i + 1);
        }

        return answer;
    }
};

//Time Complexity: O(n) - In the worst case, we may visit all friends before the game ends.
//Space Complexity: O(n) - We use a boolean array to keep track of which friends have received the ball.

