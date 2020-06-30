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
int sumrangeutil(int l,int r,int st,int en,int in)
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
  return sumrangeutil(l,r,st,mid,2*in+1)+sumrangeutil(l,r,mid+1,en,2*in+2);
}
int sumrange(int l,int r)
{
  return sumrangeutil(l,r,0,n-1,0);
}
void updateutil(int l,int r,int val,int st,int en,int in)
{
  if(st>r||en<l)
  {
    return;
  }
  if(st==en)
  {
    seg[in]+=val;
    a[st]+=val;
  }
  else
  {
    int mid=(st+en)/2;
    updateutil(l,r,val,st,mid,2*in+1);
    updateutil(l,r,val,mid+1,en,2*in+2);
    seg[in]=seg[2*in+1]+seg[2*in+2];
  }
}
void update(int l,int r,int val)
{

  
  //cout<<diff<<"\n";
  updateutil(l,r,val,0,n-1,0);
}
int constructutil(int st,int en,int in)
{
  if(st==en)
  {
    seg[in]=a[st];
    return seg[in];
  }
  int mid=(st+en)/2;
  seg[in]=constructutil(st,mid,2*in+1)+constructutil(mid+1,en,2*in+2);
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
   int l1,r1;
   cin>>l1>>r1>>val;
   update(l1,r1,val);
   for(int i=0;i<n;i++)
   {
    cout<<a[i]<<" ";
   }
   cout<<"\n";
   int l,r;
   cin>>l>>r;
   cout<<sumrange(l,r)<<"\n";
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