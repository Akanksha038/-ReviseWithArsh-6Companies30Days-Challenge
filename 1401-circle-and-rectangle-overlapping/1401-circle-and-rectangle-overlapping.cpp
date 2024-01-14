class Solution {
public:
    // Function to check if the circle with a given radius and center overlaps with a given rectangle.
    // The rectangle is defined by its bottom-left (x1, y1) and top-right (x2, y2) coordinates.
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
      
        // Helper function to calculate the smallest distance from the center of the circle
        // to the edge of the rectangle along one axis (either x or y).
        // It takes the minimum and maximum edge coordinate values along one axis
        // and the center's coordinate along the same axis.
        auto getMinimumDistance = [](int minEdge, int maxEdge, int centerCoord) -> int {
            if (centerCoord >= minEdge && centerCoord <= maxEdge) {
                // The center is inside the rectangle along this axis, so distance is 0.
                return 0;
            }
            // The center is outside the rectangle; calculate the distance to the closer edge.
            return centerCoord < minEdge ? minEdge - centerCoord : centerCoord - maxEdge;
        };
      
        // Calculate the smallest distances from the circle's center to the rectangle's edges
        // along the x and y axes.
        int deltaX = getMinimumDistance(x1, x2, xCenter);
        int deltaY = getMinimumDistance(y1, y2, yCenter);
      
        // Check if the sum of squares of smallest distances is less than or equal to the square of the radius.
        // If it is, the circle and rectangle overlap.
        return deltaX * deltaX + deltaY * deltaY <= radius * radius;
    }
};