#include<bits/stdc++.h>
using namespace std;

#define loop(a,b,c) for(int a = (int)b; a<(int)c; a++)
#define vi vector<int>
#define vvi vector< vector<int> >
#define pi pair<int,int>
#define vii vector< pi >
#define ll long long int
#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define mp make_pair

  // intialize each vertex as individual set.
void make_set(vi &arr)
{
  loop(i,0,arr.size())
  {
    arr[i] = i;
  }
}
  // Finding if parent is same as vertex , we also applied path compression
  // find_set work like tree child-parent-grandparent to find
  // vertex set
int find_set(vi &arr, int a)
{
  while(arr[a]!=a)
  {
    arr[a] = arr[arr[a]];
    a = arr[a];
  }
  return a;
}
  // unioun to merge two vertex in same set, unioun first compare both sets
  // by find_set we will find exact set, if not same set, merge both set.
  // by making parent of one vertex as others.
  // I didn't apply merge by rank, which works as merge a lighter set to heavy
  // set so to reduce time
void union_set(vi &arr, int a, int b)
{
  int seta = find_set(arr, a);
  int setb = find_set(arr, b);
  if(seta!=setb)
  {
    arr[seta] = setb;
  }
}
void print_set(vi &arr)
{
  loop(i,0,arr.size())
  {
    cout<<arr[i]<<" ";
  }cout<<"\n";
}
bool mysort(pair<int,pair<int,int> > a, pair<int,pair<int,int> > b)
{
  if(a.F<b.F)
  return true;
  return false;
}
bool mysort2(pi a, pi b)
{
  if(a.S<b.S)
  return true;
  return false;
}
    // kruskal algorithm
void kruskal(auto &edge_list, int n)
{
  sort(edge_list.begin(),edge_list.end(),mysort);  // sorting edges by weight
  vi arr(n,0); // declaring parent set
  make_set(arr);  // initialize each set
  int min_cost = 0;
  int m = edge_list.size();
  cout<<"\nkruskal edge order:\n";
  loop(i,0,m)
  {
    int w =edge_list[i].F, a =edge_list[i].S.F, b =edge_list[i].S.S;
    //print_set(arr);
    if(find_set(arr, a)!=find_set(arr, b))
    {
      union_set(arr,a,b);
      min_cost += w;
      cout<<w<<": "<<a<<", "<<b<<"\n";
    }
  }
  cout<<"MST cost with kruskal is:"<<min_cost;
}

  // prims algorithm
  void prims(auto &adj_list)
  {
    int n = adj_list.size();
    vi visited(n,0); // storing values of each vertex, visited or not.
    priority_queue<pi> pq;
    pq.push(mp(-0,-0));  // pushing (weight, vertex).
    int min_cost = 0;
    cout<<"Prims vertex order\n";
    while(!pq.empty())
    {
      pi u = pq.top(); pq.pop();
      if(visited[-u.S])  // important
      continue;
      min_cost +=-u.F;
      cout<<"vertex is "<<-u.S<<", min_cost is:"<<min_cost<<"\n";
      visited[-u.S] = 1;
      for(auto v:adj_list[-u.S])
      {
        if(!visited[v.S])
        {
          pq.push(mp(-v.F,-v.S));
        }
      }
    }
    cout<<"MST cost with prims is:"<<min_cost<<"\n";
  }

int main()
{
  int n,m;
  n = 5,m=7; // n vertex and m edges;
  cout<<"MST graph problems\n";
  // adj_list store u:(w,v);
  vector< vector< pi> > adj_list = { {mp(1,1),mp(7,2)}, {mp(1,0),mp(5,2),mp(4,3),mp(3,4)}, {mp(7,0),mp(5,1),mp(6,4)}, {mp(4,1),mp(2,4)}, {mp(3,1),mp(6,2),mp(2,3)}};
  cout<<"Given adjacency list:\n";
  int cnt =0;
  for(auto i: adj_list)
  {
    cout<<"node "<<cnt++<<":";
    for(auto j: i)
    {
      cout<<" ("<<j.F<<", "<<j.S<<")";
    }
    cout<<"\n";
  }
  // edge list:  w,(u,v)
  vector< pair<int,pair<int,int> > >  edge_list;
  for(int i =0;i<adj_list.size();i++)
  {
    for(auto j: adj_list[i])
    {
      edge_list.pb( mp( j.F, mp(i,j.S)) );
    }
  }

  //Kruskal algorithm
  kruskal(edge_list, n);
  cout<<"\n\n";
  prims(adj_list);
  cout<<"\n";
  return 0;
}
