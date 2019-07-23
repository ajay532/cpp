#include<bits/stdc++.h>
using namespace std;

#define loop(a,b,c) for(int a = (int)b; a<(int)c; a++)
#define vi vector<int>
#define vvi vector< vector<int> >
#define vii vector< pair<int, int> >
#define ll long long int
#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define mp make_pair
void BFS(int s, vector< vector< pair<int,int> > > &adj_list)
{
    queue<int> q;
    vector<bool> visited(adj_list.size(), false);
    q.push(s);
    visited[s] =true;
    int top;
    while(!q.empty())
    {
      top = q.front();
      cout<<top<<" ";
      q.pop();
      for(auto i: adj_list[top])
      {
        if(!visited[(&i)->F])
        {
          q.push((&i)->F);
          visited[(&i)->F] =true;
        }
      }
    }
}

void DFS(int s, vector< vector< pair<int,int> > > &adj_list)
{
    stack<int> q;
    vector<bool> visited(adj_list.size(), false);
    q.push(s);
    visited[s] =true;
    int top;
    while(!q.empty())
    {
      top = q.top();
      cout<<top<<" ";
      q.pop();
      for(auto i: adj_list[top])
      {
        if(!visited[(&i)->F])
        {
          q.push((&i)->F);
          visited[(&i)->F] =true;
        }
      }
    }
}

void Level(int s, vector< vector< pair<int,int> > > &adj_list)
{
    queue<int> q;
    vector<bool> visited(adj_list.size(), false);
    vector<int> level(adj_list.size(), 0);
    q.push(s);
    visited[s] =true;
    level[s] = 0;
    cout<<" ("<<s<<", "<<level[s]<<")";
    int top;
    while(!q.empty())
    {
      top = q.front();
      q.pop();
      for(auto i: adj_list[top])
      {
        if(!visited[(&i)->F])
        {
          q.push((&i)->F);
          visited[(&i)->F] =true;
          level[(&i)->F]= level[top]+1;
          cout<<" ("<<(&i)->F<<", "<<level[(&i)->F]<<")";
        }
      }
    }
}

int main()
{
  int n, m,a,b,w;
  n = 6,m=7;
  cout<<"Graph problems\n";
  // cout<<"enter nodes and edges count\n";
  // cin>>n>>m;
  // vii v;
  // vector< vector< pair<int,int> > > adj_list(n,v);
  // cout<<"enter m edges";
  // loop(i,0,m)
  // {
  //   cin>>a>>b;
  //   adj_list[a].pb(mp(b,0));
  //   adj_list[b].pb(mp(a,0));
  // }
  vector< vector< pair<int,int> > > adj_list = { {mp(1,0),mp(2,0)}, {mp(0,0),mp(3,0),mp(4,0)}, {mp(0,0),mp(5,0),mp(6,0)}, {mp(1,0)}, {mp(1,0)}, {mp(2,0)}, {mp(2,0)} };
  cout<<"Given adjacency list:\n";
  int cnt =0;
  for(auto i: adj_list)
  {
    cout<<"node "<<cnt++<<":";
    for(auto j: i)
    {
      cout<<" ("<<(&j)->F<<", "<<(&j)->S<<")";
    }
    cout<<"\n";
  }

  // BFS
  cout<<"\nBFS\n";
  BFS(0, adj_list);

  //DFS
  cout<<"\nDFS\n";
  DFS(0, adj_list);

  //level check
  cout<<"\nLevel check: (node, level)\n";
  Level(0, adj_list);
  cout<<"\n";
  return 0;
}
