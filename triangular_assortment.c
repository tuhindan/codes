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

/**************DFS traversal to compute distance**************/
void dfs(int **arr,int x,int y,int n,int m,int val)
{
    if(x < 0 || x >= n)
        return;
    if(y < 0 || y >= m)
        return;
    if(arr[x][y] == -1 || arr[x][y] > val)
    {
        arr[x][y] = val;
        dfs(arr,x,y-1,n,m,val+1);
        dfs(arr,x,y+1,n,m,val+1);
        if(y%2 == 0)
            dfs(arr,x-1,y+1,n,m,val+1);
        else
            dfs(arr,x+1,y-1,n,m,val+1);
    }
}
/*************************************************************/

/*************Print the distance in the sequence**************/
void printTriangularTraversal(int **arr,int n,int m)
{
    int i,j,k;
    
    for(k = 0 ; k < n ; k++)
    {
        i = k;
        j = 0;
        while(i >=  0 && j < m)
        {
            printf("%2d ",arr[i][j]);
            if(j%2 == 0)
            {
                i--;
            }
            j++;
        }
    }
    
    for(k = 1 ; k < n ;k = k+2)
    {
        j = k;
        i = n-1;
        while(i >=  0 && j < m)
        {
            printf("%2d ",arr[i][j]);
            if(j%2 == 0)
            {
                i--;
            }
            j++;
        }
    }
}
/*************************************************************/

/************************Print Matrix*************************/
void printMatrix(int** arr,int n,int m)
{
    int i,j;
    for(i = 0 ; i < n ; i++)
    {
       for(j = 0 ; j < m ; j++)
       {
           printf("%2d ",arr[i][j]);
       }
       printf("\n");
    }
}
/*************************************************************/

/********************Triangular Assortment********************/
void triangularAssortment(int n,int s)
{
    int **traversalMatrix = memAlloc(n/2,n,true,0);
    int **distanceMatrix = memAlloc(n/2,n,true,-1);
    
    int x,y;
    int i,j,k;
    int count = 1;
    
    /**  Initializing the traversalMatrix  **/
    /** And finding the starting point 's' **/
    for(k = 0 ; k < n/2 ; k++)
    {
        i = k;
        j = 0;
        while(i >=  0 && j < n)
        {
            traversalMatrix[i][j] = count++;
            if(traversalMatrix[i][j] == s)
            {
                x = i;
                y = j;
            }
            if(j%2 == 0)
            {
                i--;
            }
            j++;
       }
    }
    
    for(k = 1 ; k < n ;k = k+2)
    {
    	j = k;
       	i = n/2-1;
        while(i >=  0 && j < n)
        {
            traversalMatrix[i][j] = count++;
            if(traversalMatrix[i][j] == s)
            {
                x = i;
                y = j;
            }
            if(j%2 == 0)
            {
                i--;
            }
            j++;
        }
    }
    
    /*Finding the shortest Distance to all points from s**/
    dfs(distanceMatrix,x,y,n/2,n,0);
    
    printf("traversal matrix :\n");
    printMatrix(traversalMatrix,n/2,n);
    
    printf("\n\ndistance matrix :\n");
    printMatrix(distanceMatrix,n/2,n);
    
    printf("\n\ndistance array:\n");
    printTriangularTraversal(distanceMatrix,n/2,n);
    
    dealloc(traversalMatrix,n/2);
    dealloc(distanceMatrix,n/2);
}
/*************************************************************/

int main() {

    int n = 8;
    int s = 8;
    
    triangularAssortment(n,s);
    
    return 0;
}
