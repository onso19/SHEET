// same as P_43

// function to find the smallest sum contiguous subarray
int smallestSumSubarr(int arr[], int n)
{
    // First invert the sign of the elements
    for (int i = 0; i < n; i++)
        arr[i] = -arr[i];
 
    // Apply the normal Kadane algorithm But on the elements
    // Of the array having inverted sign
    int sum_here = arr[0], max_sum = arr[0];
 
    for (int i = 1; i < n; i++) {
 
        sum_here = max(sum_here + arr[i], arr[i]);
        max_sum = max(max_sum, sum_here);
    }
 
    // Invert  the answer to get minimum val
    return (-1) * max_sum;
}
