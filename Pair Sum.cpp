#include <bits/stdc++.h>

// Function to find pairs in the array that sum up to a given target value
vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Create a map to store the frequency of each element in the array
   map<int, int> mp;
   // Create a vector of vectors to store the pairs that sum up to the target value
   vector<vector<int>> ans;

   // Iterate over each element in the array
   for(int i = 0; i < arr.size(); i++){
      // Calculate the value needed to form the target sum with the current element
      int x = s - arr[i];
      
      // Check if the value needed exists in the map
      if(mp.find(x) != mp.end()){
         // If it exists, get the frequency of the value
         int val = mp[x];

         // Add all the pairs (current element, value needed) to the answer vector
         while(val--){
            // Create a pair with the minimum and maximum of the two values
            int minn = min(x, arr[i]);
            int maxx = max(x, arr[i]);
            ans.push_back({minn, maxx});
         }
      }
      
      // Increase the frequency of the current element in the map
      mp[arr[i]]++;
   }

   // Sort the answer vector lexicographically
   sort(ans.begin(), ans.end());

   // Return the vector containing all pairs that sum up to the target value
   return ans;
}
