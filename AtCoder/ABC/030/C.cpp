#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD = 1e9 + 7;
ll INF = 1e18;

int main() {
    int n, m, x, y; cin>>n>>m>>x>>y;
    vector<int> a(n), b(m);
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<m; i++) cin>>b[i];

    int i=0, j=-1, anow=a[0], bnow, sum=0;
    while(1){

        while(j<m){ //b
            j++;
            if(anow + x <= b[j] && j < m) {
                bnow = b[j];
                sum++;
                break;
            }
        }

        while(i<n){ //a 
            i++;
            if(bnow + y <= a[i] && i < n){
                anow = a[i];
                break;
            }
        }

        if(i == n || j == m) break;
    }
    cout << sum << endl;
}