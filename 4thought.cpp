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

using namespace std;
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

char v[] = {'+','-','/','*'};

int pune = 1;
char x[5];
vector<char> a[65];
string s;
int p;


void functie(){

    
    for(int i = 1 ; i <= 3 ; ++i)
        a[pune].push_back(x[i]);
    
    pune++;


}

void back(int k){

    for(int i = 0 ; i < 4 ; ++i){
        x[k] = v[i];
        if(k < 3)
            back(k + 1);
        else
            functie();
    }

}

int eval();
int prod();
int termen();

int eval(){

    int ans = prod();  
    while(s[p] == '+' || s[p] == '-'){
        if(s[p] == '+'){
            p++;
            ans += prod();
        }
        else if(s[p] == '-'){
            p++;
            ans -= prod();
        }
    }
    return ans;
}
int prod(){

    int ans = termen();
    while(s[p] == '*' || s[p] == '/'){
        if(s[p] == '*'){
            p++;
            ans *= termen();
        }
        else if(s[p] == '/'){
            p++;
            ans /= termen();
        }
    }
    return ans;
    
}
int termen(){
    
    int ans = (s[p] - '0');
    p++;
    return ans;

}


bool solve(int n,int i){
    
    p = 0;
    s = "";
    s += "4";
    s += a[i][0];
    s += "4";
    s += a[i][1];
    s += "4";
    s += a[i][2];
    s += "4";
    int ans = eval();

    if(ans == n)
        return true;

    return false;

}

void afis(int n,int k){

    cout << "4 " << a[k][0] << " 4 " << a[k][1] << " 4 " << a[k][2] << " 4 " << "= " << n;
    cout << '\n';

}

int main(){

    fastio
    
    back(1);

    int t,n;
    cin >> t;
    while(t--){

        cin >> n;
        bool ok = false;
        for(int i = 1 ; i <= 64 ; ++i){
            if(solve(n,i)){
                ok = true;
                afis(n,i);
                break;
            }
        }
        if(!ok)
            cout << "no solution\n";
    }

    

    
    return 0;
}
