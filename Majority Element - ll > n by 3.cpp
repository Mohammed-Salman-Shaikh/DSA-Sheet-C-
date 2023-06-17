#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr) {
    // Function to find elements that appear more than n/3 times in the array

    int element1 = -1; // First potential majority element
    int element2 = -1; // Second potential majority element
    int count1 = 0; // Count for the first potential majority element
    int count2 = 0; // Count for the second potential majority element

    // Finding potential majority elements
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == element1) {
            count1++; // Increment count for the first potential majority element
        }
        else if (arr[i] == element2) {
            count2++; // Increment count for the second potential majority element
        }
        else if (count1 == 0) {
            element1 = arr[i]; // Set the first potential majority element
            count1 = 1; // Reset the count for the first potential majority element
        }
        else if (count2 == 0) {
            element2 = arr[i]; // Set the second potential majority element
            count2 = 1; // Reset the count for the second potential majority element
        }
        else {
            count1--; // Decrement count for the first potential majority element
            count2--; // Decrement count for the second potential majority element
        }
    }

    vector<int> ls; // Vector to store the majority elements
    count1 = 0; // Resetting the count for the first potential majority element
    count2 = 0; // Resetting the count for the second potential majority element

    // Counting occurrences of the potential majority elements
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == element1) {
            count1++; // Increment count for the first potential majority element
        }
        else if (arr[i] == element2) {
            count2++; // Increment count for the second potential majority element
        }
    }

    // Checking if the counts exceed n/3
    if (count1 > arr.size() / 3) {
        ls.push_back(element1); // Adding the first potential majority element to the result vector
    }

    if (count2 > arr.size() / 3) {
        ls.push_back(element2); // Adding the second potential majority element to the result vector
    }

    return ls; // Return the vector containing the majority elements
}
