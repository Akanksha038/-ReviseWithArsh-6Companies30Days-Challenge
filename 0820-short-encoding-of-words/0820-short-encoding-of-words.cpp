struct TrieNode {
    TrieNode* children[26] = {nullptr}; // A node in a Trie for lowercase English letters.
};

class Solution {
public:
    // Calculates the minimum length of a string that encodes input words such that 
    // no word is a suffix of another. Each word is followed by a '#' character in the encoding.
    int minimumLengthEncoding(vector<string>& words) {
        TrieNode* root = new TrieNode(); // The root of the Trie.
        // Insert all words into the Trie in reverse order (since we want to check suffixes).
        for (const auto& word : words) {
            TrieNode* current = root;
            for (int i = word.size() - 1; i >= 0; --i) {
                int index = word[i] - 'a'; // Convert char to index (0-25).
                if (current->children[index] == nullptr) {
                    current->children[index] = new TrieNode(); // Create a new node if necessary.
                }
                current = current->children[index]; // Move to the child node.
            }
        }
        // Start Depth-First Search from the root. The initial length argument is 1 for the '#' character.
        return depthFirstSearch(root, 1);
    }

private:
    // Depth-First Search to find the total length of the encoding.
    int depthFirstSearch(TrieNode* currentNode, int depth) {
        bool isLeaf = true; // A flag to check if the current node is a leaf.
        int totalLength = 0; // Accumulation of the lengths of the encoded words.

        // Visit all children nodes.
        for (int i = 0; i < 26; ++i) {
            if (currentNode->children[i] != nullptr) {
                isLeaf = false; // Current node has a child, so it's not a leaf.
                totalLength += depthFirstSearch(currentNode->children[i], depth + 1); // Recurse with incremented depth.
            }
        }
      
        // If the node is a leaf, add the depth (word length + '#') to the total length of the encoding.
        if (isLeaf) {
            totalLength += depth;
        }
        return totalLength; // Return the calculated total length.
    }
};