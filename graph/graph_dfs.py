#V is no of nodes
#adj - adjacency list


#ITTERATIVE
    def dfsOfGraph( V, adj):
        # code here
        visited = [False for i in range(0,V)]
        stack = []
        stack.append((0,0))
        a = []
        # visited[0] = True;
        while len(stack) > 0:
            #print()
            i, j = stack.pop()
            if not visited[i]:
                visited[i] = True
                a.append(i)
            for k in range(j,len(adj[i])):
                z = adj[i][k]
                #print(i,z)
                if not visited[z]:
                    stack.append((i,k+1))
                    stack.append((z,0))
                    break
            
        return a
        
    
    
    
#RECURSIVE
    def dfs(self,V,adj,visited,a,p):
        visited[p] = True
        a.append(p)
        for i in range(0,len(adj[p])):
            if not visited[adj[p][i]]:
                self.dfs(V,adj,visited,a,adj[p][i])
        return
    
    
    def dfsOfGraph(self, V, adj):
        # code here
        visited = [False for i in range(0,V)]
        a = []
        self.dfs(V,adj,visited,a,0)
        return a
