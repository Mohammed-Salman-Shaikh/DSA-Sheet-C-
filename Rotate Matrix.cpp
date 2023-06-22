#include <bits/stdc++.h>

// Function to rotate a matrix clockwise
void rotateMatrix(vector<vector<int>> &mat, int n, int m) {
    int topleft = 0, topright = m-1, bottomright = n-1, bottomleft = 0;

    // Iterate over the layers of the matrix
    while (topleft < topright && bottomleft < bottomright) {
        int temp = mat[topleft][bottomleft];  // Store the top-left element of the current layer

        // Shift elements in the top row of the current layer
        for (int i = topleft + 1 ; i <= bottomright ; i++) {
            mat[i-1][bottomleft] = mat[i][bottomleft];
        }

        // Shift elements in the rightmost column of the current layer
        for (int i = bottomleft + 1 ; i <= topright ; i++) {
            mat[bottomright][i-1] = mat[bottomright][i];
        }

        // Shift elements in the bottom row of the current layer
        for (int i = bottomright-1 ; i >= topleft ; i--) {
            mat[i+1][topright] = mat[i][topright];
        }

        // Shift elements in the leftmost column of the current layer
        for (int i = topright-1 ; i >= bottomleft ; i--) {
            mat[topleft][i+1] = mat[topleft][i];
        }

        mat[topleft][bottomleft+1] = temp;  // Place the stored top-left element in its new position

        // Update the boundaries of the current layer
        topleft++;
        bottomleft++;
        topright--;
        bottomright--;
    }
}
