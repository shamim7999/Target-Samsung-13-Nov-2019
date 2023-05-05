#include<bits/stdc++.h>
using namespace std;
#define dd double
#define int long long
#define ull unsigned long long
#define ld long double
#define mx 1000005
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int n, k, m;
int a1, b1, a2, b2;
pair<int, int> a[12];
int dp[(1LL<<12)+12][12];

int func(int mask, int pos)
{
   if(mask == (1LL<<n)-1)
      return abs(a2-a[pos].first) + abs(b2 - a[pos].second);
   int &ret = dp[mask][pos];
   if(ret!=-1)
      return ret;
   int a11 = 1000000000;
   for(int i=0; i<n; i++){
      int x = 0;
      int ok = (mask & (1LL<<i));
      if(!ok){
         if(mask == 0){
            x = abs(a1 - a[i].first) + abs(b1 - a[i].second);
            a11 = min(a11, x+func( (mask | (1LL<<i)) , i  ));
         }
         else{
            x = abs(a[pos].first - a[i].first) + abs(a[pos].second - a[i].second);
            a11 = min(a11, x+func( (mask | (1LL<<i)) , i  ));
         }
      }
   }
   return ret = a11;
}

void solve(int kk)
{
   cin >> n;
   memset(dp, -1, sizeof dp);
   cin >> a1 >> b1 >> a2 >> b2;
   for(int i=0; i<n; i++)
      cin >> a[i].first >> a[i].second;
   cout << "# " << kk << " " << func(0, 0) << "\n";

}

int32_t main()
{
   fast;
   int t = 10;
   //cin >> t;
   for(int i=1; i<=t; i++)
        solve(i);
   return 0;
}
