#include<iostream>
#include <cmath>
#include<queue>
//#include <pair>
#include <map>
#include <algorithm>
using namespace std;
#define dd double
#define int long long
#define ull unsigned long long
#define ld long double
#define mx 52
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int n, k, m, a[mx][mx], dis[mx][mx];

map <int, bool> Up, Down, Right, Left;

bool ok(int x, int y)
{
   return (x>=1 && x<=n && y>=1 && y<=m);
}

bool __up(int x, int y)
{
   if((ok(x-1, y) && Up[a[x-1][y]] && dis[x-1][y] > 1+dis[x][y])){
      dis[x-1][y] = 1+dis[x][y];
      return 1;
   }
   return 0;
}

bool __down(int x, int y)
{
   if((ok(x+1, y) && Down[a[x+1][y]] && dis[x+1][y] > 1+dis[x][y])){
      dis[x+1][y] = 1+dis[x][y];
      return 1;
   }
   return 0;
}

bool __left(int x, int y)
{
   if((ok(x, y-1) && Left[a[x][y-1]] && dis[x][y-1] > 1+dis[x][y])){
      dis[x][y-1] = 1+dis[x][y];
      return 1;
   }
   return 0;
}
bool __right(int x, int y)
{
   if((ok(x, y+1) && Right[a[x][y+1]] && dis[x][y+1] > 1+dis[x][y])){
      dis[x][y+1] = 1+dis[x][y];
      return 1;
   }
   return 0;
}
void bfs(int xx, int yy)
{
   queue <pair<int, int>> q;
   q.push({xx, yy});
   //dis[{xx, yy}] = 1;
   dis[xx][yy] = 1;
   while(!q.empty()){
      auto [x, y] = q.front();
      q.pop();
      int a1 = a[x][y];
      if(a1 == 1){
         if(__up(x, y)) q.push({x-1, y});
         if(__down(x, y)) q.push({x+1, y});
         if(__left(x, y)) q.push({x, y-1});
         if(__right(x, y)) q.push({x, y+1});
      }
      if(a1 == 2){
         if(__up(x, y)) q.push({x-1, y});
         if(__down(x, y)) q.push({x+1, y});
      }
      if(a1 == 3){
         if(__left(x, y)) q.push({x, y-1});
         if(__right(x, y)) q.push({x, y+1});
      }
      if(a1 == 4){
         if(__right(x, y)) q.push({x, y+1});
         if(__up(x, y)) q.push({x-1, y});
      }
      if(a1 == 5){
         if(__down(x, y)) q.push({x+1, y});
         if(__right(x, y))q.push({x, y+1});
      }
      if(a1 == 6){
         if(__down(x, y)) q.push({x+1, y});
         if(__left(x, y)) q.push({x, y-1});
      }
      if(a1 == 7){
         if(__up(x, y)) q.push({x-1, y});
         if(__left(x, y)) q.push({x, y-1});  
      }
   }
}

void solve(int kk)
{
   int x, y;
   cin >> n >> m >> x >> y >> k;
   x++, y++;
   for(int i=1; i<=n; i++){
      for(int j=1; j<=m; j++){
         cin >> a[i][j];
         dis[i][j] = 1000000000;
      }
   }
   bfs(x, y);
   int sum = 0;
   for(int i=1; i<=n; i++){
      for(int j=1; j<=m; j++)
         sum+=(dis[i][j]<=k);
   }
   cout << sum << "\n";
}

int32_t main()
{
   fast;
   int t = 1;
   Up[1] = 1;Up[2] = 1;Up[5] = 1;Up[6] = 1;Down[1] = 1;Down[2] = 1;Down[4] = 1;Down[7] = 1;
   Right[1] = 1;Right[3] = 1;Right[6] = 1;Right[7] = 1;Left[1] = 1;Left[3] = 1;Left[5] = 1;
   Left[4] = 1;
   
   cin >> t;
   for(int i=1; i<=t; i++)
        solve(i);
   return 0;
}  
