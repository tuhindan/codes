def search(i,a,n):
    
    l = 0
    h = n-1
    m = (l+h)//2
    while l < h:
        if a[m] <= i:
            l = m+1
            m = (h+l)//2
        else:
            h = m-1
            m = (h+l)//2
            
    
    if a[l] > i:
        return l
    return l+1

def countEleLessThanOrEqual(arr1,n1,arr2,n2):
    #returns the required output
    k = []
    arr2.sort();
    for i in arr1:
        v = search(i,arr2,n2)
        # print(i,v)
        k.append(v)
    return k
