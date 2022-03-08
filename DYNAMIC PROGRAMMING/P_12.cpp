// RECURSIVE APPROACH
int knapSack(int C, int weight[], int value[], int n)
    {

 

        /*

           Weight of nth item can’t be more than C

           item cannot be included.

        */
        if (n == 0 || C == 0)
            return 0;

        if (weight[n - 1] > C)
            return knapSack(C, weight, value, n - 1);


        // return maximum of the following cases:
        // 1. nth item will be included
        // 2. nth item not included
        else
            return max(value[n - 1]+ knapSack(C - weight[n - 1], weight,

            value, n), knapSack(C, weight, value, n - 1));
    }


//////// MEMO
int dp[9][9];
 
// A recursive program, using ,
// memoization, to implement the
// rod cutting problem(Top-Down).
int un_kp(int price[], int length[],
                    int Max_len, int n)
{
 
    // The maximum price will be zero,
    // when either the length of the rod
    // is zero or price is zero.
    if (n == 0 || Max_len == 0)
    {
        return 0;
    }
 
    // If the length of the rod is less
    // than the maximum length, Max_lene will
    // consider it.Now depending
    // upon the profit,
    // either Max_lene  we will take
    // it or discard it.
    if (length[n - 1] <= Max_len)
    {
        dp[n][Max_len]
            = max(price[n - 1]
                      + un_kp(price, length,
                           Max_len - length[n - 1], n),
                  un_kp(price, length, Max_len, n - 1));
    }
 
    // If the length of the rod is
    // greater than the permitted size,
    // Max_len we will  not consider it.
    else
    {
        dp[n][Max_len]
            = un_kp(price, length,
                              Max_len, n - 1);
    }
 
    // Max_lene Max_lenill return the maximum
    // value obtained, Max_lenhich is present
    // at the nth roMax_len and Max_lenth column.
    return dp[n][Max_len];
}
