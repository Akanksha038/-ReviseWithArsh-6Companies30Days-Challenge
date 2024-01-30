class Solution {
public:
    int findContentChildren(std::vector<int>& children, std::vector<int>& cookies) {
        // Sort the greed factors of the children
        std::sort(children.begin(), children.end());
        // Sort the sizes of the cookies
        std::sort(cookies.begin(), cookies.end());
      
        int numChildren = children.size(); // Number of children
        int numCookies = cookies.size();   // Number of cookies
        int contentChildren = 0;           // Counter for content children
      
        // Iterate through each child
        for (int childIndex = 0, cookieIndex = 0; childIndex < numChildren; ++childIndex) {
            // Find the first cookie that can satisfy the current child's greed factor
            while (cookieIndex < numCookies && cookies[cookieIndex] < children[childIndex]) {
                ++cookieIndex;
            }
          
            // If we found a cookie that can satisfy the child
            if (cookieIndex < numCookies) {
                // Give the cookie to the child
                ++contentChildren;
                // Move to the next cookie
                ++cookieIndex;
            } else {
                // If no more cookies are available that can satisfy any child, break out of the loop
                break;
            }
        }
      
        // The number of children who can be content with the cookies we have
        return contentChildren;
    }
};
