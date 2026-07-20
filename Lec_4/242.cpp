//brute force apporach

class Solution {
public:
    bool isAnagram(string s, string t) {

        // If lengths are different,
        // they can never be anagrams.
        if (s.length() != t.length())
            return false;

        // Sort both strings alphabetically.
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        // If sorted strings become identical,
        // then frequencies are identical.
        return s == t;
    }
};

//Time Complexity: O(n log n) - Sorting both strings takes O(n log n) time.
//Space Complexity: O(1) - No extra space used, sorting is done in place.

//optimal approach - Frequency counting approach - we need only 26 characters for lower case letters

class Solution {
public:
    bool isAnagram(string s, string t) {

        // If lengths are different,
        // they cannot be anagrams.
        if (s.length() != t.length())
            return false;

        // Frequency array for 26 lowercase English letters.
        vector<int> frequency(26, 0);

        // Count frequency of every character in first string.
        for (char ch : s) {

            // Convert character into index:
            // 'a' -> 0
            // 'b' -> 1
            // ...
            frequency[ch - 'a']++;
        }

        // Remove frequencies using second string.
        for (char ch : t) {

            frequency[ch - 'a']--;
        }

        // Every frequency must become zero.
        for (int count : frequency) {

            // If any character count differs,
            // strings are not anagrams.
            if (count != 0)
                return false;
        }

        // All frequencies matched.
        return true;
    }
};

//Time Complexity: O(n) - Counting frequencies takes O(n) time.
//Space Complexity: O(1) - Frequency array has a fixed size of 26