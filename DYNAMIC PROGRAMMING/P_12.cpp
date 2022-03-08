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
