class Solution {
    // Function to return max value that can be put in knapsack of capacity.
    static int knapSack(int capacity, int val[], int wt[]) {
        // code here
        int len = val.length;
        int[][] d = new int[len+1][capacity+1];
        
        for(int i = 0 ; i <= len ; i++) {
            for (int j = 0 ; j <= capacity ; j++) {
                d[i][j] = 0;
            }
        }
        
        for(int i = 1 ; i <= len ; i++) {
            for (int j = 1 ; j <= capacity ; j++) {
                if(j >= wt[i-1])
                    d[i][j] = Math.max((d[i-1][j - wt[i-1]] + val[i-1]), d[i-1][j]);
                else
                    d[i][j] = d[i-1][j];
            }
        }
        

        // tracking weights in knapsack        
        int i = len;
        int j = capacity;
        while(i > 0 && j > 0) {
            if(d[i][j] == d[i-1][j]) {
                i--;
            } else {
                if(d[i][j] == d[i-1][j-wt[i-1]] + val[i-1]) {
                    System.out.println("wt:" + wt[i-1] + "    val:" + val[i-1]);
                    j = j - wt[i-1];
                    i--;
                } else {
                    j--;
                }
            }
        }
        
        return d[len][capacity];
    }
}
