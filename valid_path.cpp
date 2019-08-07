#include<bits/stdc++.h>
using namespace std;
void print_matrix(vector< vector<int> > &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    cout<<"\n";
    cout<<"\t";
    for(int j = 0;j<m;j++)
    { cout<<j<<"\t";
  }cout<<"\n";
    for(int i =0;i<n;i++)
    {   cout<<i<<"\t";
        for(int j = 0;j<m;j++)
        {
            cout<<matrix[i][j]<<"\t";
        }cout<<"\n";
    }cout<<"\n";
}

int ispossible(int x, int y, int tot_circle, int rad, vector<int> &c, vector<int> &r, vector< vector<int> > &grid)
{
    for(int i = 0;i<tot_circle;i++)
     {
         //cout<<sqrt((r[i]-x)*(r[i]-x) + (c[i]-y)*(c[i]-y))<<" "<<rad<<"\n";
        if(sqrt((r[i]-x)*(r[i]-x) + (c[i]-y)*(c[i]-y)) <= rad)
        {
            grid[x][y] = 0;
            break;
        }
     }
     return grid[x][y];
}
void path(int x, int y, int tot_circle, int rad, vector<int> &c, vector<int> &r, vector< vector<int> > &grid, vector< vector<int> > &visited)
{
    if(x<0||x>=grid.size()||y<0||y>=grid[0].size())
        return;
    if(visited[x][y])
      return;
    visited[x][y]=1;
    //cout<<x<<" "<<y<<"\n";
    int possible = ispossible(x,y,tot_circle, rad, c, r, grid);
    if(possible && x==grid.size()-1 && y == grid[0].size()-1)
        {
        grid[x][y] = 2;
        return; }
    if(possible){
    int dr[] = {0,1,1};
    int dc[] = {1,0,1};
    for(int i =0;i<3;i++)
        path(x + dr[i], y + dc[i], tot_circle, rad, c, r, grid, visited);
  }
}

string solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    int col = A+1, row = B+1, tot_circle = C, rad = D;
    vector<int> c(E);
    vector<int> r(F);
    vector<int> v(col,1);
    vector< vector<int> > grid(row,v);
    vector<int> v1(col,0);
    vector< vector<int> > visited(row,v1);
    // //adjusting circle index
    // for(int i =0;i<r.size();i++)
    // r[i] = col-r[i];
    cout<<"grid before start\n";
    print_matrix(grid);
    cout<<"visited before start\n";
    print_matrix(visited);
    path(0, 0, tot_circle, rad, c, r, grid, visited);
    cout<<"grid after end\n";
    print_matrix(grid);
    cout<<"visited after end\n";
    print_matrix(visited);
    //cout<<row<<" "<<col<<grid[3][2]<<"\n";
    if(grid[row-1][col-1] ==2)
    return "YES";
    else
    return "NO";
    //cout<<"\n";
}

int main()
{
  vector<int> r = {8, 5, 2, 4, 6, 4, 3, 8, 1};
  vector<int> c = {47, 32, 35, 8, 64, 97, 43, 49};
  cout<<solve(10, 99, 8, 2,r,c);
}
