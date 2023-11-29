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
#include <functional>
#include <numeric>
#include <string>
#include <unordered_set>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
#define Inf 0x3f3f3f3f
#define MAX 2000000000000000000LL
#define MOD 1000000007
#define MODC 984162946217979097
#define lsb(i) (i & -i)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tup tuple<int,int,int>
#define ll long long
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ost;

///__builtin_popcount(x)

constexpr int p = 666013;
constexpr int mod = 1674329;

int n,m,k;
vector<pii>G[1005];
int x,y,w;
bitset<1005> info[1005];

ll ezpow(ll a, ll b){

    ll ans = 1;
    for(; b ; b >>= 1){
        if(b & 1)
            ans = (ll) ans * a % MOD;
        a = (ll) a * a % MOD;
    }

   return ans;
}
/// Stare curenta : Nod si multime de noduri vizitate
struct stare{

    int a; bitset<1005> ma;
    stare(int aa,bitset<1005> &b) : a(aa) {ma = b;}
    bool operator == (const stare& other) const{
        return (a == other.a && ma == other.ma);
    }
};

vector<pair<long long,stare>> h[mod];

/// Hashuim valorile de tip : nod si bitset de noduri vizitate
int has(stare &s){

    int biti = s.ma.count();
    
    int u = ezpow(biti,s.a);

    u += (1LL * s.a * p % mod); 

    u %= mod;

    return u;
}

vector<pair<long long,stare> >::iterator getcost(stare &s,int unde){ 
    for(auto it = h[unde].begin(); it != h[unde].end() ; it++)
        if(it->second == s) 
            return it;

    return h[unde].end();
}

class cmp{
    public :
    bool operator()(const pair<ll,stare> &a,const pair<ll,stare> &b){
        return a.first > b.first;
    }
};


ll dijkstra(){

    stare start = stare(1,info[1]); 

    int u = has(start); 

    h[u].push_back({0,start});

    priority_queue<pair<ll,stare>,vector<pair<ll,stare>>,cmp> heap;

    heap.push({0,start}); 

    while(!heap.empty()){

        auto v = heap.top(); 
        heap.pop();

        if(v.second.ma.count() >= 7)  /// Minim 7 e gata
            return v.first;

        for(auto &it : G[v.second.a]){

            ll nc = v.first + it.second;

            stare noua = v.second; 
            
            noua.a = it.first;

            noua.ma |= info[it.first];

            int unde = has(noua); /// Hashuim noua stare

            auto caut = getcost(noua,unde);
            
            if(caut == h[unde].end()){ 
                h[unde].push_back({nc,noua});
                heap.push({nc,noua});
            }
            ///Stare noua

            else if(caut->first > nc){
                caut->first = nc;
                heap.push({nc,noua});
            }
            /// Actualizam stare existenta
        }
    }

    return -1;
}

int main(){

    fastio
    cin >> n >> m >> k;
    for(int i = 1 ; i <= m ; ++i){
        cin >> x >> y >> w;
        G[x].push_back({y,w});
        G[y].push_back({x,w});
    }
    for(int i = 1 ; i <= k ; ++i){
        cin >> x >> y;
        info[x][y] = 1;
    }

    cout << dijkstra();

    

    return 0;
}
