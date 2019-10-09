#include<bits/stdc++.h>
using namespace std;

#define FI freopen("input.txt","r",stdin)

//typedef long long ll;
vector<int> graph[21];
bool visited[21];
int dist[21];

void bfs(int s,int d)
{
    dist[s]=0;
    queue<int> Q;
    Q.push(s);
    int flag=0;
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        for(int i=0;i<graph[u].size();i++)
        {
            if(visited[graph[u][i]]!=true)
            {
                int v=graph[u][i];
                visited[v]=true;
                dist[v]=dist[u]+1;
                if(v==d){
                    flag = 1;
                    break;
                }
                Q.push(v);
            }
        }
        if(flag==1)
            break;
    }
}


int main()
{
    int n,e,a,b,t=1,I=1,J;
    //FI;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            cin>>J;
            graph[I].push_back(J);
            graph[J].push_back(I);
        }

        if(I==19)
        {
            cin>>e;
            cout<<"Test Set #"<<t<<endl;
            t++;
            while(e--)
            {
              memset(dist,0,sizeof(dist));
              memset(visited,0,sizeof(visited));
              cin>>a>>b;
              bfs(a,b);
              printf("%2d to %2d: %d\n",a,b,dist[b]);
            }
            cout<<endl;
            memset(graph,0,sizeof(graph));
            I=0;
        }
        I++;
    }

    return 0;
}
