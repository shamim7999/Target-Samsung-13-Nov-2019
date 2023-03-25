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
string s1;
vector <int> v[mx];
map <int, int> dis;

void bfs(int start)
{
     dis[start] = 0;
     queue <int> q;
     q.push(start);
     while(!q.empty()){
          int x = q.front();
          q.pop();
          for(int xx : v[x]){
               if(dis[x] + 1 < dis[xx]){
                    dis[xx] = dis[x]+1;
                    q.push(xx);
               }
          }
     }
}

void solve(int kk)
{
   cin >> k >> s1;
   n = s1.size();
   stack <char> s;
   vector <int> tem;
   bool ok = 0;
   int start = 0;
   for(int i=0; i<n; i++){
     if(s1[i] == '(' ||  s1[i] == ')'){
          if(s1[i] == '(')
               s.push(s1[i]);
          else{
               if(s1[i-1] == '('){
                    s.pop();
               }
               else{
                    int xx = tem.back();
                    tem.pop_back();
                    int rt = tem.back();
                    v[rt].push_back(xx);
                    s.pop();
               }
          }
     }
     else{
          int num = 0;
          int pos = i;
          for(int j=i; s1[j]!='(' && s1[j]!=')' ;j++){
               num = 10*num + (s1[j]-'0');
               pos = j;
          }
          i = pos;
          tem.push_back(num);
          dis[num] = 1000000000;
          //vv.push_back(num);
          if(!ok){
               start = num;
               ok = 1;
          }
     }
   }
   bfs(start);
   int sum = 0;
   for(auto [x, y] : dis){
      if(y == k)
          sum+=x;
   }
   cout << sum << "\n";   
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