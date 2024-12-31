///https://open.kattis.com/problems/landlocked
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

int dx[] = {0,0,1,-1,1,1,-1,-1};
int dy[] = {1,-1,0,0,1,-1,1,-1};

struct trei{

    int x,y,cost;
    char ch;

};

int n,m;
trei a[1005][1005];
int b[1005][1005];
char ch;
map<char,int> ma;


bool operator <(const trei& a, const trei& b){

    return a.cost > b.cost;

}

priority_queue<trei> q;

bool inmat(int i,int j){

    return i >= 1 && i <= n && j >= 1 && j <= m;

}

void dijkstra(){

    while(!q.empty()){

        trei r = q.top();
        q.pop();
        a[r.x][r.y].ch = 'd';

        //cout << r.x << ' ' << r.y << '\n';

        if(r.ch != 'W')
            ma[r.ch] = min(ma[r.ch],r.cost);
        
        for(int d = 0 ; d < 8 ; ++d){
            int ii = dx[d] + r.x;
            int jj = dy[d] + r.y;
            trei &ne = a[ii][jj];
            if(!inmat(ii,jj) || ne.ch == 'd')
                continue;
            else if(ne.ch == r.ch){
                ne.cost = r.cost;
                q.push(ne);
            }
            else if(ne.cost > r.cost + 1){
                ne.cost = r.cost + 1;
                q.push(ne);
            }
        }
    }
}

int main(){

    fastio
    cin >> n >> m;
    for(int i = 1 ; i <= n ; ++i)
        for(int j = 1 ; j <= m ; ++j){
            char chr;
            cin >> chr;
            a[i][j].ch = chr;
            a[i][j].x = i;
            a[i][j].y = j;
            a[i][j].cost = Inf;

            ma[a[i][j].ch] = Inf;

            if(a[i][j].ch == 'W')
                q.push({i,j,0,a[i][j].ch});
            
        }

    dijkstra();
    //exit(0);
    ma.erase('W');

    for(auto i : ma)
        cout << i.first << ' ' << i.second - 1 << '\n';
    


    return 0;
}
