#Given n dice each with m faces, numbered from 1 to m, find the number of ways to get sum X.
#X is the summation of values on each face when all the dice are thrown.
#sol is of N*X


class Solution {
  public:
    long long noOfWays(int m , int N , int X) {
        // code here
        long long *curr = (long long *)malloc(sizeof(long long)*(X+1));
        long long *prev = (long long *)malloc(sizeof(long long)*(X+1));

        for(int i = 0; i <= X ;i++)
        {
            prev[i] = 0;
            curr[i] = 0;
        }
        prev[0] = 1;
        
        for(int i = 1; i <= N ;i++)
        {
            int x,y,z;
            for(int j = 0; j <= X; j++)
            {
                if(j <= m)
                {
                    if(j == 0)
                        curr[j] = 0;
                    else
                    {
                        curr[j] = curr[j-1]+prev[j-1];
                    }
                }
                else
                {
                    curr[j] = curr[j-1]+prev[j-1]-prev[j-m-1];
                }
            }
            // for(int j = 0; j <= X; j++)
            //     cout<<curr[j]<<" ";
            //cout<<endl;
            long long *temp = curr;
            curr = prev;
            prev = temp;
        }
        
        return prev[X];
    }
};
