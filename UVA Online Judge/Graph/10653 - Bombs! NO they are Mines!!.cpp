#include<bits/stdc++.h>
using namespace std;

#define FI freopen("input.txt","r",stdin)
#define FO freopen("output.txt","w",stdout)

vector<int> graph[1001];
bool visited[1001][1001];
int dist[1001][1001];
int R,C;
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

//checking the next entering ceil is valid or not
int valid(int r,int c)
{
    return r>=0 && r<R && c>=0 && c<C && visited[r][c]!=true;
}


int bfs(int s1, int s2,int d1, int d2)
{

    pair<int, int> p;
    p.first = s1;
    p.second = s2;

    queue<pair<int,int>> Q;
    Q.push(p);
    visited[s1][s2]=true;
    dist[s1][s2] = 0;

    while(!Q.empty())
    {
        p = Q.front();
        int r=p.first;
        int c=p.second;
        Q.pop();

        for(int i=0; i<=3; i++)
        {
            if(valid(r+dr[i],c+dc[i]))
            {
                int j=r+dr[i];
                int k=c+dc[i];
                visited[j][k]=true;
                dist[j][k]=dist[r][c]+1;
                p.first=j;
                p.second=k;
                Q.push(p);
            }
        }
    }
    return dist[d1][d2];
}

int main()
{
    int r,n,a,b,c1,s1,s2,d1,d2,v1,v2,c;
    //FI;
    while (scanf ("%d%d", &r, &c) == 2 && r!=0 && c!=0)
    {
        memset(dist,0,sizeof(dist));
        memset(visited,0,sizeof(visited));
        memset(graph,0,sizeof(graph));


        R=r;
        C=c;

        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                graph[i].push_back(j);
                graph[j].push_back(i);
                visited[i][j]=false;
            }
        }

        cin>>n;

        for(int i=0; i<n; i++)
        {
            cin>>a;
            cin>>b;
            for(int j=0; j<b; j++)
            {
                cin>>c1;
                visited[a][c1]=true;
            }
        }


        cin>>s1>>s2>>d1>>d2;

        int distance = bfs(s1,s2,d1,d2);


        cout<<distance<<endl;

    }

    return 0;

}
