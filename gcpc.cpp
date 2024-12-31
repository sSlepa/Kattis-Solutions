///https://open.kattis.com/problems/gcpc

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
typedef tree<tuple<long long,long long,long long>, null_type, greater<tuple<long long,long long,long long>>, rb_tree_tag,
             tree_order_statistics_node_update> ost;

///__builtin_popcount(x)

ll n,m,t,p;
pair<ll,ll> a[100005];
ost copac;

int main(){

    fastio
    cin >> n >> m;
    for(int i = 1 ; i <= n ; ++i){
        a[i] = {0,0};
        copac.insert(make_tuple(0,0,-i));
    }
    for (int i = 1 ; i <= m ; ++i){
        cin >> t >> p;
        copac.erase(make_tuple(a[t].first, -a[t].second, -t));
        a[t] = {a[t].first + 1, a[t].second + p};
        copac.insert(make_tuple(a[t].first, -a[t].second, -t));

        cout << copac.order_of_key(make_tuple(a[1].first, -a[1].second, -1)) + 1 << endl;

    }
    

    return 0;
}
