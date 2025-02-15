class Solution {
    // Function to find minimum number of attempts needed in
    // order to find the critical floor.
    static int eggDrop(int n, int k) {
        // Your code here
        int[][] d = new int[n+1][k+1];
        
        for(int i = 0 ; i <= k ; i++) {
            d[0][i] = 0;
            d[1][i] = i; 
        }
        
        for(int i = 0 ; i <= n ; i++) {
            d[i][0] = 0;
            d[i][1] = 1;
        }
        
        for(int i = 2 ; i <= n ; i++) {
            for (int j = 2; j <= k ; j++) {
                int min = k;
                for (int l = 1 ; l < j ; l++) {
                     int z = Math.max(d[i-1][l-1],d[i][j-l]) + 1;
                    if (z < min)
                        min = z;
                }
                d[i][j] = min;
            }
        }
        
        return d[n][k];
    }
}
