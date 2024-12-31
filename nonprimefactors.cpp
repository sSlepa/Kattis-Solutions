///https://open.kattis.com/problems/nonprimefactors

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
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ost;

///__builtin_popcount(x)

using namespace std;
int n,x;
bitset<20005> prim;
vector<int> p;
int t[2000005];

void calc(){

    for(int i = 0 ; i <= 2000000 ; ++i)
        t[i] = -1;


    prim.set();
    for(int i = 2 ; i <= 2000 ; ++i){
        if(prim[i]){
            for(int j = i * i ; j <= 2000 ; j += i)
                prim[j] = 0;

            p.push_back(i);
        }
    }
}

int solve(int x){

    int nonprime = 1;
    int prime = 0;
    for(auto i : p){
        if(i * i > x)
            break;

        int power = 0;
        if(x % i == 0) 
            prime++;

        while(x % i == 0){ 
            x /= i;
            power++;
        }
        nonprime *= power + 1;
    }

    if(x != 1) 
        nonprime *= 2;
        
    if(x != 1) 
        prime++;

    return nonprime - prime;
}


int main(){
    
    fastio;

    calc();
    cin >> n;
    for(int i = 1 ; i <= n ; ++i){
        cin >> x;
        if(t[x] == -1)
            t[x] = solve(x);

        cout << t[x] << '\n';
    }
    
    
    
    return 0;
}
