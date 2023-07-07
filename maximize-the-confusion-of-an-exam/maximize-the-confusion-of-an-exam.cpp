// To solve the problem, we use a sliding window approach. We maintain a window with two pointers, i and j, representing the left and right boundaries of the window, respectively. The window contains the substring we are currently considering.

// We also keep track of the maximum frequency (max_freq) of any character encountered within the window. This helps us determine the most frequent character and the number of characters that need to be changed.

// We iterate through the answerKey string using the right pointer j. At each step, we update the frequency of the current character and update max_freq if necessary. If the length of the current window (j - i + 1) exceeds the sum of max_freq and k, it means we have more characters to change than allowed.

// In such a case, we move the left pointer i to the right, effectively shrinking the window from the left side. We also update the frequency count of the character at the i-th index to reflect the removal of that character from the window.

// By keeping track of the maximum length of the window during the iterations, we can find the maximum length of the contiguous substring where at most k characters can be changed.

// The final result is obtained by subtracting the index i from the length of the answerKey string, which gives us the length of the longest valid substring.


class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int maxFreq = 0;
        int i = 0;
        unordered_map<char, int> charCount;

        for (int j = 0; j < answerKey.length(); j++) {
            char currentChar = answerKey[j];
            charCount[currentChar]++;
            maxFreq = max(maxFreq, charCount[currentChar]);

            if (j - i + 1 > maxFreq + k) {
                charCount[answerKey[i]]--;
                i++;
            }
        }

        return answerKey.length() - i;
        
    }
};