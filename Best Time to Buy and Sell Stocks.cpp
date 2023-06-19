#include <bits/stdc++.h> 

// Function to calculate the maximum profit from buying and selling stocks
int maximumProfit(vector<int> &prices){
    // Initialize the minimum price to the first element in the prices vector
    int mini = prices[0];
    // Initialize the maximum profit to 0
    int maxProfit = 0;
    // Initialize the cost variable to 0
    int cost = 0;

    // Iterate over each price in the prices vector
    for(int i = 0; i < prices.size(); i++){
        // Calculate the cost of buying the stock at the current price
        cost = prices[i] - mini;
        // Update the maximum profit if the current cost is greater than the existing maximum profit
        maxProfit = max(maxProfit, cost);
    }

    // Return the maximum profit
    return maxProfit;
}
