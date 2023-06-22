#include <bits/stdc++.h> 

vector<int> nextPermutation(vector<int> &permutation, int n) {
    // If the size of the permutation is 1, return it as is
    if (n == 1) {
        return permutation;
    }
    int i = n - 2;  // Initialize the first pointer to the second-to-last element
    int j = n - 1;  // Initialize the second pointer to the last element
    // Find the first decreasing element from the right side of the permutation
    while (i >= 0 && permutation[i] >= permutation[i + 1]) {
        i--;
    }
    if (i >= 0) {
        // Find the smallest element greater than permutation[i] from the right side
        while (j >= 0 && permutation[j] <= permutation[i]) {
            j--;
        }
        if (j >= 0) {
            // Swap permutation[i] with the smallest element greater than it
            swap(permutation[i], permutation[j]);
        }
    }
    // Reverse the subarray from i+1 to the end to obtain the next permutation
    reverse(permutation.begin() + i + 1, permutation.end());
    return permutation;
}

//Using c++ STL
// vector<int> nextPermutation(vector<int> &permutation, int n)
// {
//     next_permutation(permutation.begin(), permutation.end());
//     return permutation;
// }
