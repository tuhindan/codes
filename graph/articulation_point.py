import sys

def arpoint(time,ll,visited,disc,low,isRoot,ar,node):
    visited[node] = True;
    low[node] = time
    disc[node] = time
    #print(node,time)
    l = len(ll[node])
    if isRoot:
        childCount = 0
        for i in range(l):
            if not visited[ll[node][i]]:
                childCount += 1
                arpoint(time+1,ll,visited,disc,low,False,ar,int(ll[node][i]))
        if childCount > 1:
            ar.append(node)
        return 0
    else:
        flag = False
        lowest_disc = low[node]
        
        for i in range(l):
            if not visited[ll[node][i]]:
                ansector = arpoint(time+1,ll,visited,disc,low,False,ar,int(ll[node][i]))
                if ansector >= disc[node]:
                    if not flag:
                        ar.append(node)
                        flag =True
            else:
                ansector = disc[ll[node][i]]
            if ansector < lowest_disc:
                lowest_disc = ansector
            #print("node",ll[node][i],ansector,lowest_disc)
            #print(disc)
        if lowest_disc < low[node]:
            low[node] =lowest_disc
        return lowest_disc




ll = [[] for i in range(n+1)]
ar = []
visited = [False for i in range(n+1)]
low = [None for i in range(n+1)]
disc = [None for i in range(n+1)]

for a0 in range(m):
    u, v = input().strip().split(' ')
    u, v = [int(u), int(v)]
    ll[u].append(v)
    ll[v].append(u)
    
arpoint(0,ll,visited,disc,low,True,ar,1)
print(ar)
print(low)
