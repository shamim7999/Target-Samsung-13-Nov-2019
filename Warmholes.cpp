#include<bits/stdc++.h>
using namespace std;
#define dd double
#define int long long
#define ull unsigned long long
#define ld long double
#define mx 1000005
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int n, k, m, a[mx], X1, Y1, X2, Y2;
vector <pair<int, int>> v[mx];
map <pair<int, int>, int> mp;
vector <int> dis;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

void dijkstra(int start)
{
     priority_queue <pair<int, int>> pq;
     pq.push({0, start});
     dis[start] = 0;
     while(!pq.empty()){
          auto [w, Node] = pq.top();
          w = abs(w);
          pq.pop();
          for(auto f : v[Node]){
               auto [adjNode, Weight] = f;
               if(dis[Node] + Weight < dis[adjNode]){
                    dis[adjNode] = dis[Node] + Weight;
                    pq.push({-dis[adjNode], adjNode});
               }
          }
     }
}

void giveValue(int x, int y)
{
     if(mp.find({x, y}) == mp.end())
          mp[{x, y}] = k, k++;
}

void solve(int kk)
{
   k = 0;   
   cin >> n >> X1 >> Y1 >> X2 >> Y2;
   giveValue(X1, Y1); giveValue(X2, Y2);
   for(int i=0, x, y, xx, yy, w; i<n; i++){
          cin >> x >> y >> xx >> yy >> w;
          giveValue(x, y);
          giveValue(xx, yy);
          int a1 = mp[{x, y}];
          int a2 = mp[{xx, yy}];
          v[a1].push_back({a2, w});
          v[a2].push_back({a1, w});
   }

   for(int i=0; i<200; i++){
      for(int j=0; j<200; j++){
         giveValue(i, j);
         int a1 = mp[{i, j}];
         for(int L=0; L<4; L++){
            int x = i+dx[L];
            int y = j+dy[L];
            if(x>=0 && x<200 && y>=0 && y<200){
               giveValue(x, y);
               int a2 = mp[{x, y}];
               int w = abs(i - x) + abs(j - y);
               v[a1].push_back({a2, w});
               v[a2].push_back({a1, w});
            }
         }
      }
   }
   //cout << mp.size() << "\n";
   dis.resize((int)mp.size() + 5);
   for(auto [x, y] : mp)
         dis[y] = 1000000000;
   dijkstra(mp[{X1, Y1}]);
   cout << dis[mp[{X2, Y2}]] << "\n";
   for(auto [x, y] : mp)
      v[y].clear();
   mp.clear();
   //cout << max_x << " " << max_y << "\n";
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