#include <bits/stdc++.h>

// Function to calculate the number of unique paths in a grid
int uniquePaths(int m, int n) {
    int N = n + m - 2;  // Total number of steps required to reach the destination
    int r = m - 1;      // Number of steps that need to be taken vertically or horizontally
    double res = 1;     // Variable to store the result

    // Calculate the binomial coefficient using multiplicative formula
    for (int i = 1; i <= r; i++) {
        res = res * (N - r + i) / i;
    }

    return (int)res;  // Return the number of unique paths as an integer
}
