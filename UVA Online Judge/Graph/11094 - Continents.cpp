#include<bits/stdc++.h>
using namespace std;

set<pair<int,int>> visitedc;
bool visited[20][20];
int dr[]= {0,0,-1,1};
int dc[]= {-1,1,0,0};
int node;
int M,N;

int valid(int r,int c)
{
    return r<M && c<N && r>=0 && c>=0 && visited[r][c]!=true;
}

void bfs(int s1,int s2)
{
    visited[s1][s2]=true;
    node=1;
    pair<int,int> p;
    p.first=s1;
    p.second=s2;
    visitedc.erase(p);
    queue<pair<int,int>> Q;
    Q.push(p);

    while(!Q.empty())
    {
        p=Q.front();
        Q.pop();
        int r=p.first,c=p.second;

        for(int i=0; i<=3; i++)
        {
            int j=r+dr[i];
            int k=c+dc[i];

            if(k==-1)
                k+=N;
            else if(k==N)
                k=0;

            if(valid(j,k))
            {
                visited[j][k]=true;
                p.first=j;
                p.second=k;
                visitedc.erase(p);
                Q.push(p);
                node++;
            }
        }
    }
}

int main()
{

    pair<int,int> p;
    while(scanf("%d %d",&M,&N)==2)
    {
        char a[M][N];
        memset(visited,0,sizeof(visited));
        visitedc.clear();
        for(int i=0; i<M; i++)
            for(int j=0; j<N; j++)
                cin>>a[i][j];

        int s1,s2;
        cin>>s1>>s2;
        char t=a[s1][s2];
        for(int i=0; i<M; i++)
        {
            for(int j=0; j<N; j++)
            {
                if(a[i][j]==t)
                {
                    p.first=i;
                    p.second=j;
                    visitedc.insert(p);
                }
                else
                    visited[i][j]=true;
            }
        }
        bfs(s1,s2);
        int ans=0;

        while(!visitedc.empty())
        {
            auto it = visitedc.begin();
            bfs(it->first,it->second);
            if(node>ans)
                ans=node;
        }
        cout<<ans<<endl;

    }
    return 0;
}
