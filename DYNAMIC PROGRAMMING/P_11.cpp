
#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum sum
int findMinRec(int arr[], int i, int sumCalculated,
			int sumTotal,vector<int,vector<int>>dp)
{
	// If we have reached last element. Sum of one
	// subset is sumCalculated, sum of other subset is
	// sumTotal-sumCalculated. Return absolute difference
	// of two sums.
	if (i == 0)
		return dp[i][sumCalculated]= abs((sumTotal - sumCalculated)
				- sumCalculated);

  if(dp[i][sumCalculated]!=-1)return dp[i][sumCalculated];
  
	// For every item arr[i], we have two choices
	// (1) We do not include it first set
	// (2) We include it in first set
	// We return minimum of two choices
	return dp[i][sumCalculated]=min(
		findMinRec(arr, i - 1, sumCalculated + arr[i - 1],
				sumTotal),
		findMinRec(arr, i - 1, sumCalculated, sumTotal));
return dp[n][sumTotal];
}

// Returns minimum possible difference between sums
// of two subsets
int findMin(int arr[], int n)
{
	// Compute total sum of elements
	int sumTotal = 0;
	for (int i = 0; i < n; i++)
		sumTotal += arr[i];
vector<int,vector<int>>dp(n+1,sumTotal);
  memset(dp,-1,sizeof(dp));
	// Compute result using recursive function
	return findMinRec(arr, n, 0, sumTotal);
}

// Driver program to test above function
int main()
{
	int arr[] = { 3, 1, 4, 2, 2, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "The minimum difference between two sets is "
		<< findMin(arr, n);
	return 0;
}
