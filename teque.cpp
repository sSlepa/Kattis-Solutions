///https://open.kattis.com/problems/teque

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

int n;
deque<int> st,dr;
string op;
int x;

int main(){

    fastio
    cin >> n;
    for(int i = 1 ; i <= n ; ++i){

        cin >> op >> x;
        if(op == "push_front")
            st.push_front(x);
        else if(op == "push_back")
            dr.push_back(x);
        else if(op == "push_middle")
            st.push_back(x);
        else if(op == "get"){
            if(x < st.size())
                cout << st[x] << '\n';
            else{
                x -= st.size();
                cout << dr[x] << '\n';
            }
        }
        while(st.size() > dr.size() + 1){
            dr.push_front(st[st.size() - 1]);
            st.pop_back();
        }
        while(dr.size() > st.size()){
            st.push_back(dr[0]);
            dr.pop_front();
        }

    }
    return 0;
}
