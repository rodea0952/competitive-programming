#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD = 1e9 + 7;
ll INF = 1e18;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(){
    int n, h; cin>>n>>h;
    vector<int> a(n), b(n);
    int MAX=0;
    for(int i=0; i<n; i++){
        cin>>a[i]>>b[i];
        MAX = max(MAX, a[i]);
    }

    sort(b.begin(), b.end(), greater<int>());

    int cnt=0;
    for(int i=0; b[i]>MAX; i++){
        h -= b[i];
        cnt++;

        if(h <= 0){
            cout << cnt << endl;
            return 0;
        }
    }

    cout << cnt + (h + (MAX - 1)) / MAX << endl;
}