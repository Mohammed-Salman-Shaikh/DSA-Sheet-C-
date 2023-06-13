#include <bits/stdc++.h>

// This function prints Pascal's triangle up to the given number of rows.
vector<vector<long long int>> printPascal(int n) {

  // `nums` is a 2D vector that will store the rows of Pascal's triangle.
  vector<vector<long long int>> nums;

  // The first row of Pascal's triangle is always 1.
  nums.push_back({1});

  // For each row i from 1 to n, we do the following:
  for (int i = 1; i < n; i++) {

    // Create a new row vector `r` of size i + 1.
    vector<long long int> r(i + 1);

    // Set the first and last elements of `r` to 1.
    r[0] = 1;
    r[i] = 1;

    // For each element j from 1 to i - 1, we set `r[j]` to the sum of the two elements above it in the previous row.
    for (int j = 1; j < r.size() - 1; j++) {
      r[j] = nums[i - 1][j - 1] + nums[i - 1][j];
    }

    // Add `r` to the `nums` vector.
    nums.push_back(r);
  }

  // Return `nums`.
  return nums;
}
