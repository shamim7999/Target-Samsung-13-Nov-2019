#include<bits/stdc++.h>
using namespace std;
#define dd double
#define int long long
#define ull unsigned long long
#define ld long double
#define mx 15
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int n, k, m, a[mx][mx], hi;
int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

bool vis[mx][mx], paisi;


bool ok(int x, int y)
{
   return (x>=1 && x<=n && y>=1 && y<=m && !vis[x][y] && a[x][y]!=0);
}

void dfs(int x, int y)
{
   if(!ok(x, y))
      return;
   if(a[x][y] == 3){
      paisi = 1;
      return;
   }
   vis[x][y] = 1;
   dfs(x, y+1);
   dfs(x, y-1);

   for(int i=0; i<=hi; i++){
      dfs(x-i, y);
      dfs(x+i, y);
   }
}

void solve(int kk)
{
   cin >> n >> m;
   for(int i=1; i<=n; i++){
      for(int j=1; j<=m; j++)
         cin >> a[i][j];
   }
   for(hi=0; hi<=11; hi++){
      memset(vis, 0, sizeof vis);
      dfs(n, 1);
      if(paisi){
         cout << hi << "\n";
         return;
      }
   }
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