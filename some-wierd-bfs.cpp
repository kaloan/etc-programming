//Originally written 30.11.18 21:37
vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    int queueSize=1;
    vector<int> searchQueue;
    searchQueue.push_back(s);

    vector<int> lengths; //result
    lengths.resize(n,0);

    vector<bool> reached;
    reached.resize(n,0);
    reached[s-1]=1;
	
    while(!searchQueue.empty())
    {
        for(int i=0;i<m;i++)
        {
            if(edges[i][0]==searchQueue[0]&&!reached[edges[i][1]-1])
            {
                searchQueue.push_back(edges[i][1]);
                lengths[edges[i][1]-1]+=lengths[edges[i][0]-1]+6;
                reached[edges[i][1]-1]=1;
            }
        }
        searchQueue.erase(searchQueue.begin());
    }
	
    for(int i=0;i<n;i++)
    {
        if(!reached[i]) lengths[i]=-1;
    }
	
    lengths.erase(lengths.begin()+(s-1));
	
    return lengths;
}