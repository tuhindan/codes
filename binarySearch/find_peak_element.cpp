int find(int a[], int l, int h,int n)
{
    int m = (l+h)/2;
    if(h == 0 || l == n-1)
        return m;
    
    if(m != 0 && a[m-1] > a[m])
        return find(a,l,m-1,n);
    else if(m != n-1 && a[m+1] > a[m])
        return find(a,l+1,h,n);
    return m;
    
}

int peakElement(int arr[], int n)
{
   // Your code here
    // cout<<find(arr,0,n-1,n)<<endl;
    // cout<<arr[find(arr,0,n-1,n)]<<endl;
    return find(arr,0,n-1,n);
}
