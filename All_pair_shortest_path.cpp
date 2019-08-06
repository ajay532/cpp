#include<bits/stdc++.h>
#define loop(a,b,c) for(int a = (int)b; a< (int)c; a++)
#define pi pair<int,int>
#define mp make_pair
#define F first
#define S second
using namespace std;

void find_path(auto i, auto j, auto &parent)
{
    if(i!=j)
      {
      find_path(i,parent[i][j],parent);
      cout<<parent[i][j]<<" ";
    }
}

void floyd_warshal(auto &adj_matrix)
{
  int n = adj_matrix.size();
  // declaring parent matrix
  vector<int> v(n,0);
  vector< vector<int> > parent(n, v);
  // intializing parent matrix
  loop(i,0,n)
    loop(j,0,n)
      {
        parent[i][j] = i;
      }

  // calculating shortes value and setting parent
  loop(k,0,n)
    loop(i,0,n)
      loop(j,0,n)
          if(adj_matrix[i][j] > adj_matrix[i][k] + adj_matrix[k][j])
          {
            adj_matrix[i][j] = adj_matrix[i][k] + adj_matrix[k][j];
            parent[i][j] = k;
          }

  // printing final values
  cout<<"shortest path between two vertices i and j\n";
  loop(i,0,n)
  {
    loop(j,0,n)
      {
          cout<<adj_matrix[i][j]<<" ";
      }cout<<"\n";
  }
  // fetching path for two nodes
  loop(i,0,n)
  {
    loop(j,0,n)
    {   cout<<"path for "<<i<<" and "<< j<< " is: ";
        find_path(i,j,parent);
        cout<<"\n";
    }
  }
}
int main()
{
  int n,m;
  n = 5,m=7; // n vertex and m edges;
  cout<<"APSP graph problems\n";
    // adj_list store u:(w,v);
  vector< vector< pi> > adj_list = { {mp(1,1),mp(7,2)}, {mp(1,0),mp(5,2),mp(4,3),mp(3,4)}, {mp(7,0),mp(5,1),mp(6,4)}, {mp(4,1),mp(2,4)}, {mp(3,1),mp(6,2),mp(2,3)}};
  cout<<"Given adjacency list:\n";
  int cnt = 0;
  for(auto i: adj_list)
  {
    cout<<"node "<<cnt++<<":";
    for(auto j: i)
    {
      cout<<" ("<<j.F<<", "<<j.S<<")";
    }
    cout<<"\n";
  }
   // declaring and intializing adj matrix, it is mandatory
   // to have adj matrix to apply floyd warshal APSP algorithm
   // thats why space complexity is o(v^2)
  vector< long long int > v(n,INT_MAX);
  vector< vector<long long int> > adj_matrix(n, v);
  loop(i,0,n)
  {
    for(auto j: adj_list[i])
    {
      adj_matrix[i][j.S] = j.F;
    }
    adj_matrix[i][i] = 0;
  }

    // floyd_warshal_algorithm
  floyd_warshal(adj_matrix);
  return 0;
}
