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

int n,q;
ll x,y;
unordered_map<ll,ll> m;
ll inflatie;
ll suma;
string s;

int main(){

    fastio
    cin >> n;
    for(int i = 1 ; i <= n ; ++i){

        cin >> x;
        suma += x;
        m[x]++;

    }
    cin >> q;
    for(int i = 1 ; i <= q ; ++i){
        cin >> s;
        if(s == "INFLATION"){
            cin >> x;
            inflatie += x;
        }
        else{
            cin >> x >> y;
            x -= inflatie;
            y -= inflatie;
            if(x != y){
                suma = suma + m[x] * (y - x);
                m[y] += m[x];
                m[x] = 0;
            }
        }
        cout << suma + inflatie * n << '\n';

    }

    

    return 0;
}
