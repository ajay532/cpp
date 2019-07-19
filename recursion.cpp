#include<bits/stdc++.h>
#include<string>
using namespace std;
int totlen = 4;
int totalprod;

void subsets(string &s, vector< string> &res_mat, string &res_str, int idx)
{
  cout<<"index="<<idx<<"\n";
  if(idx == s.length())
  {
    res_mat.push_back(res_str);
    return;
  }
  //for(int i = idx; i<s.length(); i++)
  //{
  res_str.push_back(s[idx]);
  subsets(s, res_mat, res_str, idx+1);
  res_str.erase(res_str.begin() + res_str.length() -1);
  subsets(s, res_mat, res_str, idx+1);
  //}
}


////////////////////
void triplet_product(vector<int> &nums, vector< vector<int> > &res_mat, vector<int> &res_arr, int idx, int prod)
{
  cout<<"index= "<<idx<<" size= "<<res_arr.size()<<" product= "<<prod<<"\n";
  if(idx == nums.size() + 1 || res_arr.size() == 3 || prod == totalprod)
  {
    if(res_arr.size() == 3 && prod == totalprod)
    res_mat.push_back(res_arr);
    return;
  }
  for(int i = idx; i<nums.size();i++)
  {
    res_arr.push_back(nums[i]);
    prod = prod*nums[i];
    triplet_product(nums, res_mat, res_arr, i+1, prod);
    res_arr.erase(res_arr.begin() + res_arr.size() -1);
    prod = prod/nums[i];
  }
}

/////////////////////
void subset_of_totlen(string &s, vector< string> &res, string &str, int idx)
{
  cout<<"index="<<idx<<"\n";
  if(idx == s.length() + 1 || str.length() == totlen)
  {
    if(str.length() == totlen)
    res.push_back(str);
    return;
  }
  for(int i = idx; i<s.length();i++)
  {
  str.push_back(s[i]);
  subset_of_totlen(s, res, str, i+1);
  str.erase(str.begin() + str.length() -1);
  }
}

/////////////////////////////////////
void permutation(string &s, vector< string> &res, string &str, vector<bool> &check)
{
  //cout<<"index="<<idx<<"\n";
  if(str.length() == s.length())
  {
    cout<<"\n"<<str<<"\n";
    res.push_back(str);
    return;
  }
  for(int i = 0; i<s.length();i++)
  {
    cout<<i<<" ";
    if(check[i])
    {
      check[i] = false;
      str.push_back(s[i]);
      permutation(s, res, str, check);
      str.erase(str.begin() + str.length() -1);
      check[i] =true;
    }
  }
}
int main()
{
  //// case of all subsets
  string s;
  cout<<"enter the string\n";
  cin>>s;
  vector< string> res_mat;
  string res_str;
  subsets(s, res_mat, res_str, 0);
  cout<<"\nResult: subset of given string are\n";
  for(int i =0;i<res_mat.size();i++)
  {
    cout<<res_mat[i]<<"\n";
  }

  //subset_of_totlen(s, res, str, 0);
  //vector<bool> check(s.length(), true);
  //permutation(s, res, str, check);

//// case of subset product
  // vector<int> nums; vector< vector<int> > res_mat; vector<int> res_arr;
  // int x,y;
  // cout<<"enter size of list\n";
  // cin>>x;
  // cout<<"enter integers in list\n";
  // for(int i = 0;i<x;i++)
  // {
  //   cin>>y;
  //   nums.push_back(y);
  // }
  // cout<<"enter given total product\n";
  // cin>>totalprod;
  // triplet_product(nums, res_mat, res_arr, 0, 1);
  // cout<<"\nresult:\n";
  // for(int i=0; i< res_mat.size();i++)
  // {
  //   for(int j=0;j<res_mat[i].size();j++)
  //   {
  //     cout<<res_mat[i][j]<<" ";
  //   }
  //   cout<<"\n";
  // }
  return 0;
}
