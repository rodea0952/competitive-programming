#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD = 1e9 + 7;
ll INF = 1e18;

int main() {
    int n; cin>>n;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++) cin>>a[i];

    int t_ans=0, a_ans=0, kari=-MOD, ans=0, MAX=-MOD;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){

            if(i == j) continue;

            for(int k=min(i, j); k<=max(i, j); k++){
                if((k - min(i, j) + 1) % 2 == 1) t_ans += a[k];
                else a_ans += a[k];
            }

            if(a_ans > kari){
                kari = a_ans;
                ans = t_ans;
            }
            t_ans = 0, a_ans = 0;
        }
        MAX = max(MAX, ans);
        kari = -MOD;
    }
    cout << MAX << endl;
}