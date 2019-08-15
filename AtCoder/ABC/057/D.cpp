#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD = 1e9 + 7;
ll INF = 1e18;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

ll C[60][60]; //C[n][k] -> nCk
void comb(int n){
    for(int i=0; i<=n; i++){
        for(int j=0; j<=i; j++){
            if(j == 0 || j == i){
                C[i][j]=1LL;
            }
            else{
                C[i][j]=(C[i-1][j-1]+C[i-1][j]);
            }
        }
    }
}

int main(){
    int n, a, b; cin>>n>>a>>b;
    vector<ll> v(n);
    for(int i=0; i<n; i++) cin>>v[i];

    sort(v.begin(), v.end(), greater<ll>());

    double ans=0;
    for(int i=0; i<a; i++){
        ans += v[i];
    }
    ans /= a;
    
    comb(n);

    cout << fixed << setprecision(10) << ans << endl;

    if(v[0] == v[a-1]){
        int cnt=0;
        for(int i=0; i<n; i++){
            if(v[0] == v[i]) cnt++;
        }

        ll ans2=0;
        for(int i=a; i<=b; i++){
            ans2 += C[cnt][i];
        }
        cout << ans2 << endl;
    }
    else{
        int cnt=0, cnt2=0;
        for(int i=0; i<n; i++){
            if(v[a-1] == v[i]) {
                cnt++;
                if(i < a) cnt2++;
            }
        }

        cout << C[cnt][cnt2] << endl;
    }
}