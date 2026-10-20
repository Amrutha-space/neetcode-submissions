class Solution {
public:
    string minWindow(string s, string t) {
        if (t.length() > s.length()) {
            return "";
        }

        vector<int> freq(128, 0);

        for (char c : t) {
            freq[c]++;
        }

        int left = 0;
        int count = t.length();
        int minLength = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.length(); right++) {
            if (freq[s[right]] > 0) {
                count--;
            }

            freq[s[right]]--;

            while (count == 0) {
                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    start = left;
                }

                freq[s[left]]++;

                if (freq[s[left]] > 0) {
                    count++;
                }

                left++;
            }
        }

        if (minLength == INT_MAX) {
            return "";
        }

        return s.substr(start, minLength);
    }
};