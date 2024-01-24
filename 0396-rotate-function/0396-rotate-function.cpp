class Solution {
public:
    int maxRotateFunction(std::vector<int>& nums) {
        int currentFunctionValue = 0; // Initialize sum of i*nums[i]
        int sumOfElements = 0; // Initialize sum of nums[i] for all i
        int numberOfElements = nums.size(); // Number of elements in the array

        // Calculate initial configuration values for currentFunctionValue and sumOfElements
        for (int i = 0; i < numberOfElements; ++i) {
            currentFunctionValue += i * nums[i];
            sumOfElements += nums[i];
        }
      
        int maxFunctionValue = currentFunctionValue; // Initialize the maximal value of F with current configuration
      
        // Iterate over the array to find the maximal rotation function value
        for (int i = 1; i < numberOfElements; ++i) {
            // Compute the next value of F by adding the sumOfElements and subtracting
            // the last element multiplied by the number of elements
            currentFunctionValue = currentFunctionValue + sumOfElements - numberOfElements * nums[numberOfElements - i];
          
            // Update the maxFunctionValue with the maximum of current and the newly computed value
            maxFunctionValue = std::max(maxFunctionValue, currentFunctionValue);
        }

        // Return the maximum value found for the rotation function
        return maxFunctionValue;
    }
};
