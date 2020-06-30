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
const int mod = 1e9+7, N = 4e5 + 10;
int n;
int seg[4*N],lazy[4*N];
int a[N];
int getsumutil(int l,int r,int st,int en,int in)
{
	if(lazy[in]!=0)
	{
		seg[in]+=lazy[in];
		if(st!=en)
		{
			lazy[2*in+1]+=lazy[in];
			lazy[2*in+2]+=lazy[in];
		}
		lazy[in]=0;
	}
	if(st>r||en<l)
	{
		return 0;
	}
	if(st>=l&&en<=r)
	{
		return seg[in];
	}
	int mid=(st+en)/2;
	return getsumutil(l,r,st,mid,2*in+1)+getsumutil(l,r,mid+1,en,2*in+2);
}
int getsum(int l,int r)
{
	return getsumutil(l,r,0,n-1,0);
}
void updateutil(int l,int r,int val,int st,int en,int in)
{
	if(lazy[in]!=0)
	{
		seg[in]+=lazy[in];
		if(st!=en)
		{
			lazy[2*in+1]+=lazy[in];
			lazy[2*in+2]+=lazy[in];
		}
		lazy[in]=0;
	}
	if(st>r||en<l)
	{
		return;
	}
	if(st>=l&&en<=r)
	{
		seg[in]+=val;
		if(st!=en)
		{
			lazy[2*in+1]+=val;
			lazy[2*in+2]+=val;
		}
		return;
	}
	int mid=(st+en)/2;
	updateutil(l,r,val,st,mid,2*in+1);
	updateutil(l,r,val,mid+1,en,2*in+2);
	seg[in]=seg[2*in+1]+seg[2*in+2];
}
void update(int l,int r,int val)
{
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
   {
   	cin>>a[i];

   }
   construct();
   int l,r,val;
   cin>>l>>r>>val;
   update(l,r,val);
   int l1,r1;
   cin>>l1>>r1;
   cout<<getsum(l,r);
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