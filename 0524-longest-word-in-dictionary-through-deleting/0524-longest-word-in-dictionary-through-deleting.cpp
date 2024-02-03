class Solution {
public:
    // Function to find the longest string in the dictionary that is a
    // subsequence of s. If there are multiple, the smallest lexicographically
    // will be returned.
    string findLongestWord(string s, vector<string>& dictionary) {
        string longestWord = ""; // Initialize the longest word to an empty string
      
        // Iterate over each word in the dictionary
        for (string& word : dictionary) {
            // Check if the word is a subsequence of s
            // and compare it with the current longest word based on length and lexicographical order
            if (isSubsequence(s, word) && 
                (longestWord.size() < word.size() || 
                (longestWord.size() == word.size() && word < longestWord))) {
                longestWord = word; // Update the longest word
            }
        }
        return longestWord; // Return the longest word
    }

    // Helper function to check if string b is a subsequence of string a
    bool isSubsequence(string& a, string& b) {
        int aLength = a.size(), bLength = b.size(); // Length of the strings
        int i = 0, j = 0; // Pointers for each string
      
        while (i < aLength && j < bLength) {
            // If the characters match, increment j to check the next character of b
            if (a[i] == b[j]) ++j;
            ++i; // Always increment i to move forward in string a
        }
        // String b is a subsequence of a if j has reached the end of b
        return j == bLength;
    }
};
