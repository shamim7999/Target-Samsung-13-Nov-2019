#include<bits/stdc++.h>
using namespace std;
#define dd double
#define int long long
#define ull unsigned long long
#define ld long double
#define mx 1000005
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int n, k, m, a[13][13];
int dp[(1LL<<12) + 10][13];

int func(int mask , int pos)
{
   if(mask == (1LL<<n)-1)
      return a[pos][0];
   if(mask!=0 && pos == 0)
        return 1e15;
   int &ret = dp[mask][pos];
   if(ret!=-1)
      return ret;
   int a1 = 1e15;
   int st = 0;
   for(int i=0; i<n; i++){
      int ok = (mask & (1LL<<i));
      if(!ok){
         a1 = min(a1, a[pos][i]+func(mask | (1LL<<i), i));
      }
   }
   return ret = a1;
}

void solve(int kk)
{
   cin >> n;
   for(int i=0; i<n; i++){
      for(int j=0; j<n; j++)
         cin >> a[i][j];
      for(int j=0; j<(1LL<<n); j++)
         dp[j][i] = -1;
   }
   cout << func(0, 0) << "\n";
}

int32_t main()
{
   fast;
   int t = 1;
   cin >> t;
   for(int i=1; i<=t; i++)
        solve(i);
   return 0;
}
