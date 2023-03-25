#include<bits/stdc++.h>
using namespace std;
#define dd double
#define int long long
#define ull unsigned long long
#define ld long double
#define mx 20
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int n, k, m, a[mx][6];

void dfs(int x, int y, int paisi, bool Bomb, int Freed)
{
   k = max(k, paisi);
   if(x == 0)
      return;
   for(int i=-1; i<=1; i++){
      if( y+i>=1 && y+i<=5 ){

            if(a[x][y+i] == 2){
               if(Bomb){
                  if(Freed > 0)
                     dfs(x-1, y+i, paisi+(a[x][y+i] == 1), Bomb, Freed-1);
               }
               else{
                  dfs(x-1, y+i, paisi+(a[x][y+i] == 1), 1, 5);
               }
            }
            else{
               if(Bomb){
                  if(Freed > 0)
                     dfs(x-1, y+i, paisi+(a[x][y+i] == 1), Bomb, Freed-1);
               }
               else{
                  dfs(x-1, y+i, paisi+(a[x][y+i] == 1), Bomb, Freed);
               }
            }
      }
   }
}

void solve(int kk)
{
   cin >> n;
   for(int i=1; i<=n; i++){
      for(int j=1; j<=5; j++)
         cin >> a[i][j];
   }
   
   k = 0;
   dfs(n, 3, 0, 0, 0);

   cout << "#" << kk << " " << k << "\n";
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