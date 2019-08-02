#include<bits/stdc++.h>
using namespace std;
#define loop(a,b,c) for(int a = int(b); a<c; a++)
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define vii vector<int,int>
#define pi pair<int,int>
#define ll long long
#define F first
#define S second

void dijkstras(int start, auto &adj_list)
{
  int n = adj_list.size();
  vi value(n,INT_MAX); // storing values of each vertex, shortest path possible from 0 vertex.
  value[start] = 0;
  priority_queue<pi> pq;
  pq.push(mp(-value[start],-start));  // pushing (shortest path value, vertex).
  while(!pq.empty())
  {
    pi u = pq.top(); pq.pop();
    cout<<"vertex is "<<-u.S<<"\n";
    for(auto v:adj_list[-u.S])
    {
      if(-u.F+v.F <value[v.S])
      {
        value[v.S] = -u.F+v.F;
        pq.push(mp(-value[v.S],-v.S));
      }
    }
  }
  cout<<"shortest path value for each node are:\n";
  loop(i,0,n)
  {
    cout<<value[i]<<" ";
  }cout<<"\n";
}

int main()
{
  int n, m,a,b,w;
  n = 5,m=7;
  cout<<"SSSP graph problems\n";
  vector< vector< pi> > adj_list = { {mp(1,1),mp(7,2)}, {mp(1,0),mp(5,2),mp(4,3),mp(3,4)}, {mp(7,0),mp(5,1),mp(6,4)}, {mp(4,1),mp(2,4)}, {mp(3,1),mp(6,2),mp(2,3)}};
  // adj_list store u:(w,v);
  cout<<"Given adjacency list:\n";
  int cnt =0;
  for(auto i: adj_list)
  {
    cout<<"node "<<cnt++<<":";
    for(auto j: i)
    {
      cout<<" ("<<j.S<<", "<<j.F<<")";
    }
    cout<<"\n";
  }

  //calling dijkstras algorithm
  dijkstras(4,adj_list);

  return 0;
}
