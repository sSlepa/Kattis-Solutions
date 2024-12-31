///https://open.kattis.com/problems/eveningout2
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
#pragma warning(disable:4996)

using namespace std;
#define Inf 0x3f3f3f3f
#define MAX 2000000000000000000LL
#define MOD 1000000009
#define MODC 984162944621615797
#define lsb(i) (i & -i)
#define pii pair<int,int>
#define tup tuple<int,int,int>
#define ll long long
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
///__builtin_popcount(x)

/*
int n,m;
int x,y;
vector<int> G[200005];
int v[200005];

cin >> n >> m;
    for(int i = 1 ; i <= n ; ++i){
        cin >> x >> y;
        G[x].push_back(y);
    }
*/
vector<unsigned ll> m;
int main(){

    fastio
    unsigned ll a,b;
    cin >> a >> b;

    for(int i = 1 ; i < sqrt(a) + 1 ; ++i)
        if(a % i == 0){
            m.push_back(i);
            m.push_back(a / i);
        }
    unsigned ll mini = -1;
    for(int i = 0 ; i < m.size() ; ++i){
        unsigned ll val1 = m[i];
        unsigned ll val2 = b;
        if(val1 < val2)
            swap(val1,val2);
        if(val1 - val2 < mini)
            mini = val1 - val2;
    }

    cout << mini;
    


    return 0;
}
