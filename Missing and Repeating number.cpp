#include <bits/stdc++.h>

// Function to find the missing and repeating elements in an array
pair<int, int> missingAndRepeating(vector<int> &arr, int n) {
    vector<int> count(n + 1, 0);  // Initialize a count array to keep track of occurrences
    sort(arr.begin(), arr.end());  // Sort the array in ascending order
    int R = 0;  // Variable to store the repeating element
    int M = 0;  // Variable to store the missing element

    // Iterate over the array to count occurrences and find the repeating element
    for (int i = 0; i < arr.size() - 1; i++) {
        count[arr[i]] += 1;  // Increment the count for the current element

        // Check if the current element is equal to the next element, indicating a repetition
        if (arr[i] == arr[i + 1]) {
            R = arr[i];  // Store the repeating element
        }
    }

    count[arr.size() - 1] += 1;  // Increment the count for the last element

    // Iterate over the count array to find the missing element
    for (int i = 1; i <= n; i++) {
        if (count[i] == 0) {
            M = i;  // Store the missing element
            break;
        }
    }

    return {M, R};  // Return the pair of missing and repeating elements
}
