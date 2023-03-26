#include<bits/stdc++.h>
using namespace std;
#define dd double
#define int long long
#define ull unsigned long long
#define ld long double
#define mx 1000005
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int n, k, m, a[16][16];

int func2(int mask)
{
    int sum = 0;
    for(int i=0; i<n; i++){
        bool okk = 1;
        for(int j=0; j<m; j++){
            int ok = (mask & (1LL<<j));
            if(ok){
                if(a[i][j] == 1){
                    okk = 0;
                    break;
                }
            }
            else{
                if(a[i][j] == 0){
                    okk = 0;
                    break;
                }
            }
        }
        sum+=okk;
    }
    return sum;
}

int func(int mask, int ace)
{
    if(ace == 0){
        return func2(mask);
    }
    int a1 = 0;
    for(int i=0; i<m; i++){
        a1 = max(a1, func( (mask ^ (1LL<<i))  , ace-1));
    }
    return a1;
}

void solve(int kk)
{
   cin >> n >> m >> k;
   for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            cin >> a[i][j];
   }
   cout << func(0, k) << "\n";
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
