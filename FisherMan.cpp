#include<bits/stdc++.h>
using namespace std;
#define dd double
#define int long long
#define ull unsigned long long
#define ld long double
#define mx 15
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int n, m, ace, b[5];
vector <int> a;

int dp[(1LL<<11)+3][4][16];

int func(int mask, int pos, int now)
{
    if(pos == m)
        return 0;
    int &ret = dp[mask][pos][now];
    if(ret!=-1)
        return ret;
    int a1 = 1000000000;
    for(int i=0; i<n; i++){
         int ok = (mask & (1LL<<i));
         if(!ok){
            if(now-1>0){
               a1 = min(a1, abs(a[pos]-i)+1+func( (mask | (1LL<<i)) , pos , now-1));
            }
            else if(now-1 == 0){
               a1 = min(a1, abs(a[pos]-i)+1+func( (mask | (1LL<<i)) , pos+1 , b[pos+1]));
            }
         }
    }
    return ret = a1;
}
void solve(int kk)
{
   cin >> n;
   a.resize(3);
   m = 3;
   for(int i=0; i<m; i++){
        cin >> a[i];
        a[i]--;
   }
   for(int i=0; i<m; i++)
        cin >> b[i], ace+=b[i];
   int a1 = 1000000000;
   memset(dp, -1, sizeof dp);
   a1 = func(0 , 0, b[0]);
   cout << a1 << "\n";
}

int32_t main()
{
   fast;
   int t = 1;
   //cin >> t;
   for(int i=1; i<=t; i++)
        solve(i);
   return 0;
}