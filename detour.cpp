///https://open.kattis.com/problems/detour

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <bitset>
#include <stack>
#include <unordered_map>
#include <map>
#include <cmath>
#include <chrono>
#include <set>
#include <iomanip>
#include <list>
#include <sstream>

using namespace std;
using namespace chrono;
#define Inf 0x3f3f3f3f
#define MAX 2000000000000000000LL
#define MOD 1000000007
#define MODC 984162946217979097
#define lsb(i) (i & -i)
#define pii pair<int,int>
#define tup tuple<int,int,int>
#define ll long long
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

///__builtin_popcount(x)

int n,m;
int x,y,w;
vector<pair<int,int> > G[100005];
vector<int> d(100005,Inf);
priority_queue<pii,vector<pii>,greater<pii> > q;
vector<int> p(100005,0);
vector<int> v(100005,0);
vector<int> path;
bool gata;

void dijkstra(){

    d[1] = 0;
    q.push({0,1});
    while(!q.empty()){
        int x = q.top().second;
        q.pop();
        for(auto i : G[x]){
            if(d[i.first] > d[x] + i.second){
                d[i.first] = d[x] + i.second;
                p[i.first] = x;
                q.push({d[i.first],i.first});
            }
        }
    }
}

void dfs(int nod){

    v[nod] = 1;
    if(nod == 1){
        gata = true;
        path.push_back(nod);
        return;
    }
    for(auto i : G[nod]){
        if(!v[i.first] && p[nod] != i.first){
            dfs(i.first);
            if(gata){
                path.push_back(nod);
                return;
            }
        }
    }
}

int main(){

    fastio
    cin >> n >> m;
    for(int i = 1 ; i <= m ; ++i){
        cin >> x >> y >> w;
        G[x].push_back({y,w});
        G[y].push_back({x,w});
    }
    dijkstra();
    
    dfs(0);
    
    if(gata){
        cout << path.size() << ' ';
        reverse(path.begin(),path.end());
        for(auto i : path)
            cout << i << ' ';
    }
    else{
        cout << "impossible";
    }

    

    
    return 0;
}
