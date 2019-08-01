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

void make_set(vi &arr)
{
  loop(i,0,arr.size())
  {
    arr[i] = i;
  }
}
int find_set(vi &arr, int a)
{
  while(arr[a]!=a)
  {
    arr[a] = arr[arr[a]];
    a = arr[a];
  }
  return a;
}
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

void kruskal(auto &edge_list, int n)
{
  sort(edge_list.begin(),edge_list.end(),mysort);
  vi arr(n,0);
  make_set(arr);
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
      // count++;
      // if(count==n/2)
    }
  }
  cout<<"kruskal cost is:"<<min_cost;
}

void prims(auto &adj_list, int n)
{
  vector<bool> inmst(n,false);
  vi parent(n,0);
  loop(i,0,n)
  parent[i] = i;
  vi value(n,INT_MAX);
  value[0]=0;
  //priority_queue <pi, vii, mysort2> minkey(keys.begin(),keys.end());
  int min_cost = 0;
  loop(i,0,n)
  {
    //finding minimum keys
    int minkey = INT_MAX;
    int minkeyindex = -1;
    loop(j,0,n)
    {
      if(!inmst[j] && value[j]<minkey)
      {
        minkey = value[j];
        minkeyindex = j;
      }
    }
    inmst[minkeyindex] = true;
    if(i!=0)
    min_cost = adj_list[minkeyindex].;
    for(auto j: adj_list[minkeyindex])
    {
      if(!inmst[j.F] && value[minkeyindex] + j.S < value[j.F])
      {
      value[j.F] = value[minkeyindex] + j.S;
      parent[j.F] = minkeyindex;
      }
    }
    cout<<"minkey = "<<minkeyindex<<"\n";
    loop(j,0,n)
    cout<<value[j]<<" ";
    cout<<"\n";
  }
  //printing nodes
  cout<<"prims, edges traversed are in this order\n";
  loop(i,1,n)
  cout<<"("<<i<<", "<<parent[i]<<") ";
  cout<<"prims min cost is\n";
  cout<<min_cost;

}

int main()
{
  int n, m,a,b,w;
  n = 5,m=7;
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
  vector< vector< pair<int,int> > > adj_list = { {mp(1,1),mp(2,7)}, {mp(0,1),mp(2,5),mp(3,4),mp(4,3)}, {mp(0,7),mp(1,5),mp(4,6)}, {mp(1,4),mp(4,2)}, {mp(1,3),mp(2,6),mp(3,2)}};
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
  vector< pair<int,pair<int,int> > >  edge_list;
  for(int i =0;i<adj_list.size();i++)
  {
    for(auto j: adj_list[i])
    {
      edge_list.pb( mp( j.S, mp(i,j.F)) );
    }
  }
  // cout<<"Given edge list:\n";
  // for(auto i: edge_list)
  // {
  //     cout<<"["<<i.F<<" ("<<(i.S).F<<", "<<(i.S).S<<")] ";
  // }
  // // sort all edges by weight
  // sort(edge_list.begin(),edge_list.end(),mysort);
  // cout<<"Given edge list after sorting:\n";
  // for(auto i: edge_list)
  // {
  //     cout<<"["<<i.F<<" ("<<(i.S).F<<", "<<(i.S).S<<")] ";
  // }
  //Kruskal algorithm
  kruskal(edge_list, n);
  cout<<"\n";
  prims(adj_list,n);
  cout<<"\n";
  return 0;
}
