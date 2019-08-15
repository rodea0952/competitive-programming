#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD = 1e9 + 7;
ll INF = 1e18;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(){
    int t, n; cin>>t>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i]; 
    int m; cin>>m;
    vector<int> b(m);
    for(int i=0; i<m; i++) cin>>b[i];

    if(n < m){
        cout << "no" << endl;
        return 0;
    }

    for(int i=0; i<m; i++){
        bool flag=false;
        for(int j=0; j<n; j++){
            if(b[i] - a[j] <= t && b[i] - a[j] >= 0){
                n--;
                for(int k=0; k<n; k++) a[k] = a[k+1];
                flag=true;
                break;
            }
        }
        if(!flag){
            cout << "no" << endl;
            return 0;
        }
    }
    cout << "yes" << endl;
}