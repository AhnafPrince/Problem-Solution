#include<bits/stdc++.h>
using namespace std;

set<long long> visitedc;
vector<long long> temp;
set<long long>::iterator it;
vector<long long> graph[100001];
bool visited[100001];

void dfs(long long node)
{
    if(visited[node]==true)
        return;

    visited[node]=true;
    visitedc.erase(node);
    temp.push_back(node);
    for(long long i=0;i<graph[node].size();i++)
            dfs(graph[node][i]);
}

int main()
{
    long long q,n,m,cr,cl,a,b;
    cin>>q;

    while(q--)
    {
        cin>>n>>m>>cl>>cr;

        memset(graph,0,sizeof(graph));
        memset(visited,0,sizeof(visited));
        long long component = 0,rcost=0,lcost=0,ncost=0;

        for(long long i=0;i<m;i++)
        {
            cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
            visitedc.insert(a);
            visitedc.insert(b);
        }

        for(long long i=1;i<=n;i++)
        {
            if(visitedc.count(i))
                continue;
            else
                visitedc.insert(i);
        }

        while(visitedc.empty()!=true)
        {
            temp.clear();
            it=visitedc.begin();
            dfs(*it);
            rcost=rcost+((temp.size()-1)*cr);
            component++;
        }
        lcost=component*cl;
        ncost=n*cl;
        //cout<<component<<endl;
        if(ncost<(rcost+lcost) || m==0)
            cout<<ncost<<endl;
        else
            cout<<rcost+lcost<<endl;
    }

    return 0;
}
