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

int main()
{
  int n, m,a,b,w;
  n = 7,m=6;
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

  cout<<"playing find union\n";
  vi arr(n,0);
  make_set(arr);
  print_set(arr);
  union_set(arr,2,5);
  print_set(arr);
  union_set(arr,1,4);
  print_set(arr);
  union_set(arr,0,2);
  print_set(arr);
  union_set(arr,1,3);
  print_set(arr);
  union_set(arr,2,6);
  print_set(arr);
  cout<<"set for 0: "<<find_set(arr,0)<<"\n";
  print_set(arr);
  cout<<"set for 1: "<<find_set(arr,1)<<"\n";
  print_set(arr);
  union_set(arr,0,1);
  print_set(arr);
  cout<<"set for 0 and 1: "<<find_set(arr,0)<<", "<<find_set(arr,1)<<"\n";
  //cout<<"\n";
  return 0;
}
