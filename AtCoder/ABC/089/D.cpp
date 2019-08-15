#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD = 1e9 + 7;
ll INF = 1e18;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(){
    int h, w, d; cin>>h>>w>>d;
    int a[310][310];
    map<int, P> mp;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin>>a[i][j];
            mp[a[i][j]] = make_pair(i, j);
        }
    }

    int sum[100010];
    memset(sum, 0, sizeof(sum));
    for(int i=1; i<=d; i++){
        for(int j=0; i+j<=h*w; j+=d){
            if(j == 0){
                sum[i] = 0;
            }
            else{
                sum[i+j] = sum[i+j-d] + abs(mp[i+j].first - mp[i+j-d].first) + abs(mp[i+j].second - mp[i+j-d].second);
            }
        }
    }

    int q; cin>>q;
    for(int i=0; i<q; i++){
        int l, r; cin>>l>>r;
        cout << sum[r] - sum[l] << endl;
    }
}