#include<bits/stdc++.h>
using namespace std;

vector<long long> graph[100001];
bool visited[100001];
set<long long> visitedc;
set<long long>::iterator it;
vector<long long> temp;

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
    long long n,m,a,b;
    cin>>n>>m;
    memset(graph,0,sizeof(graph));
    memset(visited,0,sizeof(visited));

    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        visitedc.insert(a);
        visitedc.insert(b);
    }

    for(long long i=0;i<n;i++)
    {
        visitedc.insert(i);
    }
    long long component = 0,arr[n],ans=0,sum=0;

    while(!visitedc.empty())
    {
        temp.clear();
        it = visitedc.begin();
        dfs(*it);
        arr[component]=temp.size();
        component++;
    }

    for(long long i=0;i<component;i++)
    {
       ans+=sum*arr[i];
       sum+=arr[i];
    }

    cout<<ans<<endl;

    return 0;
}
