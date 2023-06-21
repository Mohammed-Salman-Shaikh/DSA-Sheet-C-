#include <bits/stdc++.h>
// Approach 2, best approach
// Function to merge two sorted arrays into a single sorted array
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
    int left, right, len;
    // Initialize the pointers and length variables
    left = m - 1;   // Pointer for the last element of arr1
    right = n - 1;  // Pointer for the last element of arr2
    len = m + n - 1;  // Length of the merged array

    // Merge the two arrays starting from the end
    while (left >= 0 && right >= 0) {
        // Compare the elements at the corresponding positions in arr1 and arr2
        if (arr1[left] < arr2[right]) {
            // If the element in arr2 is larger, place it in the merged array
            arr1[len] = arr2[right];
            right--;  // Move the right pointer to the previous position
        }
        else {
            // If the element in arr1 is larger or equal, place it in the merged array
            arr1[len] = arr1[left];
            left--;  // Move the left pointer to the previous position
        }
        len--;  // Move the merged array pointer to the previous position
    }

    // If there are remaining elements in arr2, add them to the merged array
    while (right >= 0) {
        arr1[len] = arr2[right];
        right--;  // Move the right pointer to the previous position
        len--;  // Move the merged array pointer to the previous position
    }

    // Return the merged and sorted array
    return arr1;
}


//   //Approach 1, this maynot be accepted in the interview
// // Function to combine and sort two arrays
// vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
  
// 	// Remove the last n elements from arr1
// 	for(int i = 0; i < n; i++){
// 		arr1.pop_back();
// 	}

// 	// Append the elements from arr2 to arr1
// 	for(int i = 0; i < n; i++){
// 		arr1.push_back(arr2[i]);
// 	}

// 	// Sort the combined array arr1
// 	sort(arr1.begin(), arr1.end());

// 	// Return the sorted array arr1
// 	return arr1;
// }
