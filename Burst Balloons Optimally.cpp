#include<bits/stdc++.h>
using namespace std;
#define dd double
#define int long long
#define ull unsigned long long
#define ld long double
#define mx 1000005
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int n, k, m, a[mx];
int dp[(1LL<<11)+3][11];

int func(int mask, int pos)
{
    if(mask == (1LL<<n)-1)
        return a[pos]-1;
    int &ret = dp[mask][pos];
    if(ret!=-1)
        return ret;
    int a1 = 0;
    for(int i=0; i<n; i++){
        int ok = (mask & (1LL<<i));
        
        if(!ok){
            int Left = 1, Right = 1;
            for(int j=i-1; j>=0; j--){
                int okk = (mask & (1LL<<j));
                if(!okk){
                    Left = a[j];
                    break;
                }
            }
            for(int j=i+1; j<n; j++){
                int okk = (mask & (1LL<<j));
                if(!okk){
                    Right = a[j];
                    break;
                }
            }
            a1 = max(a1, (Left*Right)+func( (mask | (1LL<<i)) , i ));
        }
    }
    return ret = a1;
}

void solve(int kk)
{
   cin >> n;
   memset(dp, -1, sizeof dp);
   for(int i=0; i<n; i++)
        cin >> a[i];
   cout << func(0, 0) << "\n"; 
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
