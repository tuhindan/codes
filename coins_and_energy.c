#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/*********************Allocating 2D Matrix*********************/
int **memAlloc(int n,int m,bool setVal,int val)
{
    int **mem = (int **)malloc(sizeof(int *)*n);
    
    int i,j;
    
    for(i = 0 ; i < n ; i++)
    {
        mem[i] = (int *)malloc(sizeof(int)*m);
    }
    
    if(setVal)
    {
        for(i = 0 ; i < n ; i++)
        {
            for(j = 0 ; j < m ; j++)
            {
                mem[i][j] = val;
            }
        }
    }
    
    return mem;
}
/*************************************************************/

/********************Dellocating 2D Matrix********************/
void dealloc(int **mem,int n)
{
    int i;
    
    for(i = 0 ; i < n ; i++)
        free(mem[i]);
        
    free(mem);    
}
/*************************************************************/

/***************************MAX MIN***************************/
int max(int a,int b)
{
    if(a > b)
        return a;
    return b;    
}
int min(int a,int b)
{
    if(a < b)
        return a;
    return b;    
}
/*************************************************************/

/***********************Coins and Energy**********************/
int coinsAndEnergy(int coins[],int energy[],int initialEnergy,int n)
{
    int i,j,k;
    int ans = 1;
    
    /*If initial energy is atleast n-1 then we can traverse 
    all the houses with out needing any more energy
    
    So the maximum energy that we can aquire (altough can be greater)
    should be equal to n-1*/
    
    int **DP = memAlloc(n,n,true,-1);
    /*So allocating a 2D matrix of size nXn
    x axis for the house number (0 - n-1)
    y axis for the energy (0 - n-1)
    
    and DP[i][j] signifies the number of coins that can be collected till
    ith house with jth amount of Energy left
    
    DP[house_no][energy_left] = coins_collected */
    
    
    /*REMEMBER : jumping to the first house dosent require energy
    subsequent jump will require*/
    
    /*picking energy at the 0th house result in 0 coins with 
    'initialEnergy+energy[0]' energy left, which should be less than n*/
    DP[0][min(initialEnergy+energy[0],n-1)] = 0;
    
    /*picking coin at the 0th house result in coins[0] coins with
    'initialEnergy' energy left, which should be less than n*/
    DP[0][min(initialEnergy,n-1)] = coins[0];
    
    ans = coins[0];
    
    /**/
    for(i = 1 ; i < n ; i++)
    {
        for(j = 1 ; j < n ; j++)
        {
            if(DP[i-1][j] > -1)
            {
                /*picking coin at the ith house*/
                DP[i][j-1] = max(DP[i][j-1],DP[i-1][j]+coins[i]);
                
                /*picking energy at the ith house*/
                k = min(j+energy[i]-1,n-1);
                DP[i][k] = max(DP[i][k],DP[i-1][j]);
                
                ans = max(ans,DP[i][j-1]);
            }
        }
    }
    
    dealloc(DP,n);
    
    return ans;
  
}
/*************************************************************/

int main() {

    int n = 5;
    int coins[] = {3,23,9,2,2};
    int energy[] = {1,5,3,3,1};
    int initialEnergy = 1;
    printf("%d\n",coinsAndEnergy(coins,energy,initialEnergy,n));
    
    return 0;
}
