#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD = 1e9 + 7;
ll INF = 1e18;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(){
    int n, k; cin>>n>>k;

    int cnt1=0, cnt2=0;
    for(int i=1; i<=n; i++){
        if(i % k == 0) cnt1++;
        else if(k % 2 == 0){
            if((i % k) % (k / 2) == 0) cnt2++;
        }
    }
    ll ans1=1, ans2=1;
    for(int i=1; i<=3; i++) ans1 *= cnt1;
    for(int i=1; i<=3; i++) ans2 *= cnt2;

    cout << ans1 + ans2 << endl;
}