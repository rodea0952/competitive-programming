#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD=1e9+7;
ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int main(){
    int n, k; cin>>n>>k;
    vector<int> a(n);
    int MIN=MOD, MAX=0;
    for(int i=0; i<n; i++){
        cin>>a[i];
        MIN=min(MIN, a[i]);
        MAX=max(MAX, a[i]);

        if(a[i] == k){
            cout << "POSSIBLE" << endl;
            return 0;
        }
    }

    vector<int> div;
    for(int i=2; i<=sqrt(MIN); i++){
        if(MIN%i == 0){
            div.emplace_back(i);
            div.emplace_back(MIN/i);
        }
    }
    div.emplace_back(MIN);

    for(int i=0; i<div.size(); i++){
        bool f=true;
        for(int j=0; j<n; j++){
            if(a[j]%div[i] != 0) f=false;
        }

        if(f){
            if(k%div[i] != 0 || MAX-MIN < k){
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }
    cout << "POSSIBLE" << endl;
}