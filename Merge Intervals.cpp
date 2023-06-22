#include<bits/stdc++.h>

// Function to merge overlapping intervals
vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals) {
    int n = intervals.size();

    // Sort the intervals based on the start times
    sort(intervals.begin(), intervals.end());

    // Create a vector to store the merged intervals
    vector<vector<int>> ans;

    // Add the first interval to the answer vector
    ans.push_back(intervals[0]);

    // Iterate over the remaining intervals
    for(int i = 1; i < n; i++) {
        // Check if the current interval overlaps with the last interval in the answer vector
        if(intervals[i][0] <= ans.back()[1]) {
            // If there is an overlap, update the end time of the last interval in the answer vector
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
        else {
            // If there is no overlap, add the current interval to the answer vector
            ans.push_back(intervals[i]);
        }
    }

    // Return the merged intervals
    return ans;
}
