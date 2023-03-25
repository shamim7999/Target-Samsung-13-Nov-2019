#include<bits/stdc++.h>
using namespace std;
#define dd double
#define int long long
#define ull unsigned long long
#define ld long double
#define mx 60
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int n, k, m, a[mx];
vector <int> v[mx];
vector <pair<int, vector<int>>> ans;
bitset <mx> vis;

void dfs(int node, int &sum, vector <int> &tem)
{
    if(vis[node]){
        if(ans.empty()){
            ans.push_back({sum, tem});
        }
        else{
            auto [val, vec] = ans.back();
            if(sum < val){
                ans.clear();
                ans.push_back({sum, tem});
            }
        }
        //cout << "paisi\n";
        return;
    }
    //cout << node << " ";
    vis[node] = 1;
    tem.push_back(node);
    sum+=node;
    for(int child : v[node]){
        dfs(child, sum, tem);
    }
    sum-=node;
    vis[node] = 0;
    tem.pop_back();
}

void solve(int kk)
{
   cin >> n >> m;
   for(int i=0,x,y; i<m; i++){
        cin >> x >> y;
        v[x].push_back(y);
   }
   //int sum =0 ;
   //vector <int> tem;
   for(int i=1; i<=n; i++){
        vector <int> tem;
        int sum = 0;
        dfs(i, sum, tem);
   }
   //dfs(1, sum, tem);
   for(auto [x, y] : ans){
        sort(y.begin(), y.end());
        for(int xx : y)
            cout << xx << " ";
   }
   cout << "\n";
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
