#include <vector>
#include <algorithm> // Include algorithm for max function

// Solution class encapsulates the method to determine the last moment.
class Solution {
public:
    // getLastMoment calculates the last moment before all ants fall off a plank.
    // Parameters:
    // - n: the length of the plank.
    // - left: a vector of integers representing positions of ants moving to the left.
    // - right: a vector of integers representing positions of ants moving to the right.
    // Returns the maximum number of seconds before the last ant falls off.
    int getLastMoment(int n, std::vector<int>& left, std::vector<int>& right) {
        int lastMoment = 0; // Initialize the last moment to zero.

        // Iterate over the positions of ants moving to the left.
        for (int position : left) {
            // Update last moment based on the ants moving to the left.
            lastMoment = std::max(lastMoment, position);
        }

        // Iterate over the positions of ants moving to the right.
        for (int position : right) {
            // Update last moment based on the distance of ants moving to the right from the end.
            lastMoment = std::max(lastMoment, n - position);
        }

        return lastMoment; // Return the calculated last moment.
    }
};
