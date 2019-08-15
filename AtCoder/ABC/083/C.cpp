#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD = 1e9 + 7;
ll INF = 1e18;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(){
    ll x, y; cin>>x>>y;

    int cnt=0;
    while(x <= y){
        x *= 2;
        cnt++;
    }

    cout << cnt << endl;
}