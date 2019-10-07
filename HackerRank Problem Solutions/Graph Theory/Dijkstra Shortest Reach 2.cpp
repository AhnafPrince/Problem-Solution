#include<bits/stdc++.h>
using namespace std;

#define FI freopen("input.txt","r",stdin)

struct Node
{

    long long node, cost;
    Node(long long _node,long long _cost)
    {
        node = _node;
        cost = _cost;
    }
};

bool operator<(Node A,Node B)
{
    return A.cost>B.cost;
}

struct Edge
{
    long long v,w;
};

vector<Edge> graph[3000];
priority_queue<Node> PQ;

long long lm = LONG_MAX;
long long dist[3000];
int n,e;

void dijkstra(int s)
{
    dist[s]=0;
    PQ.push(Node(s,dist[s]));

    while(!PQ.empty())
    {
        Node u = PQ.top();
        PQ.pop();

        if(u.cost!=dist[u.node])
        {
            continue;
        }

        for(Edge e : graph[u.node])
        {
            if(dist[e.v]>u.cost+e.w)
            {
                dist[e.v]=u.cost+e.w;
                PQ.push(Node(e.v,dist[e.v]));
            }
        }
    }
}
int main()
{
    //FI;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>e;
        memset(graph,0,sizeof(graph));
        memset(dist,0,sizeof(dist));
        int a,b,w,s;
        Edge ed;
        for(int i=0; i<e; i++)
        {
            //cin>>a>>b>>w;
            scanf("%d %d %d",&a,&b,&w); //scanf funcion for test case #7 as for faster input of 35MB file =D
            ed.v=b;
            ed.w=w;
            graph[a].push_back(ed);
            ed.v=a;
            graph[b].push_back(ed);
            dist[a]=lm;
            dist[b]=lm;
        }
        cin>>s;

        dijkstra(s);

        for(int i=1; i<=n; i++)
        {
            if(i==s)
                continue;

            if(dist[i]==lm || dist[i]==0)
            {
                cout<<"-1"<<" ";
                continue;
            }
            cout<<dist[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

