bool searchMatrix(vector<vector<int>>& mat, int target) {
    int m = mat.size(); // Number of rows in the matrix
    int n = mat[0].size(); // Number of columns in the matrix

    int low = 0; // Lower bound for binary search
    int high = n * m - 1; // Upper bound for binary search
    int mid = (low + high) / 2; // Middle index of the search range

    // Perform binary search
    while (low <= high) {
        mid = (low + high) / 2; // Calculate the middle index
        int row = mid / n; // Calculate the row index of the middle element
        int col = mid % n; // Calculate the column index of the middle element

        if (mat[row][col] < target) {
            low = mid + 1; // If the middle element is smaller than the target, move the lower bound to mid + 1
        } else if (mat[row][col] == target) {
            return true; // If the middle element is equal to the target, return true (target found)
        } else {
            high = mid - 1; // If the middle element is larger than the target, move the upper bound to mid - 1
        }
    }

    return false; // If the target is not found, return false
}
