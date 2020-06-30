/*
  Vishal Shrivastava
  i_am_kirito

  look up to the sky,keep up(don't let go)
  I'll look towards the sky, without any doubt...
  
  never let you go,never let you go.
  till the light shines stronger, I go.
*/
#include <bits/stdc++.h>
using namespace std;
#define minpq priority_queue <int, vector<int>, greater<int> >
#define maxpq  priority_queue <int>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define ll long long
#define int ll
#define pll pair<ll,ll>
#define pii pair<int,int>
const int mod = 1e9+7, N = 1e5 + 10;
int n;
int a[N];
int seg[4*N];
int xorrangeutil(int l,int r,int st,int en,int in)
{
  if(l>en||r<st)
  {
    return 0;
  }
  if(st>=l&&en<=r)
  {
    //cout<<st<<" "<<en<<" "<<seg[in]<<"ll\n";

    return seg[in];
  }
  int mid=(st+en)/2;
  return xorrangeutil(l,r,st,mid,2*in+1)^xorrangeutil(l,r,mid+1,en,2*in+2);
}
int xorrange(int l,int r)
{
  return xorrangeutil(l,r,0,n-1,0);
}
void updateutil(int index,int diff,int st,int en,int in)
{
  if(index>en||index<st)
  {
    return;

  }
  seg[in]=seg[in]^diff;
  //cout<<st<<" "<<en<<" "<<seg[in]<<"\n";
  if(st!=en)
  {
    int mid=(st+en)/2;
    updateutil(index,diff,st,mid,2*in+1);
    updateutil(index,diff,mid+1,en,2*in+2);
  }
}
void update(int in,int val)
{
  int diff=a[in]^val;
  a[in]=val;
  //cout<<diff<<"\n";
  updateutil(in,diff,0,n-1,0);
}
int constructutil(int st,int en,int in)
{
  if(st==en)
  {
    seg[in]=a[st];
    return seg[in];
  }
  int mid=(st+en)/2;
  seg[in]=constructutil(st,mid,2*in+1)^constructutil(mid+1,en,2*in+2);
  return seg[in];
}
void construct()
{
  constructutil(0,n-1,0);
}
void solve()
{
   cin>>n;
   for(int i=0;i<n;i++)
    cin>>a[i];
   construct();
   int in,val;
   cin>>in>>val;
   update(in,val);
   for(int i=0;i<n;i++)
   {
    cout<<a[i]<<" ";
   }
   cout<<"\n";
   int l,r;
   cin>>l>>r;
   cout<<xorrange(l,r)<<"\n";
  return;
}
 
int32_t main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int test=1;
  //cin>>test;
  while(test--)
  {
    solve();
  }
}