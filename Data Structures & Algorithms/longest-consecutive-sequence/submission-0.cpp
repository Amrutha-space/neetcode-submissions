class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;

        for (int n : nums) {
            s.insert(n);
        }

        int longest = 0;

        for (int n : s) {

            // Check if n is the START of a sequence
            if (s.find(n - 1) == s.end()) {

                int length = 1;

                while (s.find(n + length) != s.end()) {
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};