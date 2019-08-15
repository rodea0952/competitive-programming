#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD = 1e9 + 7;
ll INF = 1e18;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

ll n, a, b;

bool calc(ll mid, vector<ll> h){
    for(int i=0; i<n; i++){
        h[i] -= mid*b;
    }

    ll cnt=0;
    for(int i=0; i<n; i++){
        if(h[i] > 0) cnt += (h[i] + (a - b) - 1) / (a - b);
    }

    if(cnt <= mid) return true;
    else return false;
}

int main(){
    cin>>n>>a>>b;
    vector<ll> h(n);
    for(int i=0; i<n; i++) cin>>h[i];

    ll left=0, right=1e9, mid;
    while(left + 1 < right){
        mid=(left+right)/2;

        if(calc(mid, h)) right=mid;
        else left=mid;
    }
    cout << right << endl;
}