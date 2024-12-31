///https://open.kattis.com/problems/heatingup
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
#include <random>
#include <string>
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
#define ull unsigned long long
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ost;

///__builtin_popcount(x)

using namespace std;

vector<ull> a(1000005);

int ok(ull mij){
    vector<pair<ull, ull>> todo;
    ull cur = mij;
    for(ull x : a){
        if(x <= cur){
            cur += x;
            while(!todo.empty() && todo.back().first <= cur){
                cur += todo.back().second;
                todo.pop_back();
            }
        } 
        else{
            todo.push_back({x, cur - mij + x});
            cur = mij;
        }
    }
    return todo.empty();
}

int main(){
    
    fastio;

    int n;
    cin >> n;
    

    for(int i = 0 ; i < n ; ++i){
        cin >> a[i];
        a[i + n] = a[i];
    }
    ll st = -1;
    ll dr = 10000000000007;

    while(st + 1 < dr){
        ll mij = (st + dr) / 2;
        if(ok(mij))
            dr = mij;
        else
            st = mij;
        
    }
    cout << dr;
    
    
    
    return 0;
}
