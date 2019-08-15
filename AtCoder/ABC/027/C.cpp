#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD = 1e9 + 7;
ll INF = 1e18;

int main() {
    ll n; cin>>n;

    int depth=-1;
    for(ll i=n; i>0; i/=2) depth++;
    //cout << depth << endl;
    ll x=1;
    if(depth % 2 == 1){
        while(1){
            x *= 2;
            if(x > n){
                cout << "Aoki" << endl;
                return 0;
            }
        
            x = 2*x + 1;
            if(x > n){
                cout << "Takahashi" << endl;
                return 0;
            }
        }
    }
    else{
        while(1){
            x = 2*x + 1;
            if(x > n){
                cout << "Aoki" << endl;
                return 0;
            }
        
            x *= 2;
            if(x > n){
                cout << "Takahashi" << endl;
                return 0;
            }
        }
    }
}