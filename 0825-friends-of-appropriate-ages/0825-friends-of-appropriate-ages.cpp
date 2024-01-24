class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        // Create a counter array to store the number of people at each age.
        vector<int> ageCounter(121, 0); // Initialized with 121 elements all set to 0
     
        // Count the number of instances of each age
        for (int age : ages) {
            ageCounter[age]++;
        }
      
        int totalFriendRequests = 0; // Initialize the total number of friend requests to 0

        // Loop through the ages from 1 to 120 (inclusive)
        for (int ageA = 1; ageA <= 120; ++ageA) {
            int countAgeA = ageCounter[ageA]; // Number of people with age A

            // Loop through all possible ages for potential friends
            for (int ageB = 1; ageB <= 120; ++ageB) {
                int countAgeB = ageCounter[ageB]; // Number of people with age B

                // Check if a friend request can be sent according to the problem's conditions
                if (!(ageB <= 0.5 * ageA + 7 ||   // Age B should not be less than or equal to 0.5 * Age A + 7
                      ageB > ageA ||               // Age B should be less than or equal to Age A
                      (ageB > 100 && ageA < 100)   // If Age B is > 100, then Age A should also be > 100
                     )) {
                    totalFriendRequests += countAgeA * countAgeB;  // Add the count product to total requests
                  
                    // If ages are the same, subtract the self request count
                    if (ageA == ageB) {
                        totalFriendRequests -= countAgeB; // Subtract the diagonal
                    }
                }
            }
        }

        // Return the total number of friend requests
        return totalFriendRequests;
    }
};