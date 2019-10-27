#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Node{

  ll node,cost;

  Node(int _node,ll _cost)
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

    ll v,w;
};

vector<Edge> graph[200000];
ll cost[200000];
ll total_cost=0;
ll t=0;
bool visited[200000];
ll lm=LONG_MAX;

void prims()
{
    cost[0]=0;
    PQ.push(Node(0,0));

    while(!PQ.empty())
    {
        Node u = PQ.top();
        PQ.pop();

        if(visited[u.node])
            continue;

        visited[u.node]=true;
        total_cost+=u.cost;

        for(Edge e : graph[u.node])
        {
            if(visited[e.v]==false && cost[e.v]>e.w)
            {
                cost[e.v]=e.w;
                PQ.push(Node(e.v,cost[e.v]));
            }
        }
    }
}


int main()
{
    int m,n;

    cin>>m>>n;

    while(m!=0 && n!=0)
    {
        int a,b,w;
        memset(graph,0,sizeof(graph));
        memset(visited,0,sizeof(visited));
        memset(cost,0,sizeof(cost));
        t=0;
        for(int i=0;i<n;i++)
        {
            //cin>>a>>b>>w;
            scanf("%d %d %ld",&a,&b,&w);
            t+=w;
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
        prims();
        cout<<t-total_cost<<endl;

        scanf("%d %d",&m,&n);
    }


    return 0;
}
