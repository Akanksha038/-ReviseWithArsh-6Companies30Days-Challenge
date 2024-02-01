class Solution {
public:
    // The function calculates the probability that the nth person gets the nth seat.
    // According to the problem, if there is one seat, the probability is 100% (or 1).
    // For more than one seat, the probability is always 50% (or 0.5).
    double nthPersonGetsNthSeat(int n) {
        // Check if there's only one person.
        if (n == 1) {
            // If so, the probability that the first person gets the first seat is 100%.
            return 1.0;
        } else {
            // For any number of people greater than one, the probability
            // the nth person gets the nth seat is always 50%.
            return 0.5;
        }
    }
};