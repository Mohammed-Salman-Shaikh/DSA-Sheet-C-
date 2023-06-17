#include <bits/stdc++.h>

// Function to find the majority element in an array
int findMajorityElement(int arr[], int n) {
	
	int vote = 0; // Counter for the number of votes
	int candidate = -1; // Current candidate for majority element

	// Finding a potential candidate for the majority element
	for (int i = 0; i < n; i++) {
		if (vote == 0) {
			candidate = arr[i]; // If vote count is 0, set the candidate to the current element
			vote++; // Increment vote count
		}
		else if (candidate == arr[i]) {
			vote++; // If the current element matches the candidate, increment vote count
		}
		else {
			vote--; // If the current element is different, decrement vote count
		}
	}

	int cnt = 0; // Counter to count occurrences of the candidate element in the array

	// Counting the occurrences of the candidate element in the array
	for (int i = 0; i < n; i++) {
		if (arr[i] == candidate) {
			cnt++; // Increment the counter if the element matches the candidate
		}
	}

	// Checking if the candidate element is a majority element
	if (cnt > n / 2) {
		return candidate; // If the count is greater than half of the array size, return the candidate as the majority element
	}
	else {
		return -1; // Otherwise, return -1 indicating that there is no majority element
	}
}

