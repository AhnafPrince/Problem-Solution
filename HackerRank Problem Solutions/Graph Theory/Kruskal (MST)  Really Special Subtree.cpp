#include<bits/stdc++.h>
using namespace std;

#define FI freopen("input.txt","r",stdin)

struct Node{
    int node,cost;
    Node(int _node,int _cost)
    {
        node=_node;
        cost=_cost;
    }
};

bool operator<(Node A,Node B)
{
    return A.cost>B.cost;
}

priority_queue<Node> PQ;

struct Edge{

    int v,w;
};

vector<Edge> graph[3000];
long long cost[3000];
bool visited[3000];
long lm=LONG_MAX;
//int parant[3000];
long long total_cost;

void prims(int s)
{
    cost[s]=0;
    PQ.push(Node(s,cost[s]));

    while(!PQ.empty())
    {
        Node u=PQ.top();
        PQ.pop();

        if(visited[u.node]==true)
            continue;

        visited[u.node]=true;
        total_cost+=u.cost;

        for(Edge e : graph[u.node])
        {
            if(visited[e.v]==false && cost[e.v]>e.w)
            {
                cost[e.v]=e.w;
                PQ.push(Node(e.v,cost[e.v]));
                //parant[e.v]=u.node;
            }
        }
    }

}

int main()
{
    //FI;

    long long n,m;
    cin>>n>>m;
    int a,b,w;

    memset(graph,0,sizeof(graph));
    memset(visited,0,sizeof(visited));
    memset(cost,0,sizeof(cost));
    //memset(parant,0,sizeof(parant));

    for(int i=0;i<m;i++)
    {
        //cin>>a>>b>>w;
        scanf("%d %d %d",&a,&b,&w);

        Edge ed;
        ed.v=b;
        ed.w=w;
        graph[a].push_back(ed);
        ed.v=a;
        graph[b].push_back(ed);
        cost[a]=lm;
        cost[b]=lm;
    }

    total_cost=0;
    prims(n);

    cout<<total_cost<<endl;

    return 0;
}

