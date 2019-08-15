#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD = 1e9 + 7;
ll INF = 1e18;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(){
    int n; cin>>n;
    vector<int> p(n);
    for(int i=0; i<n; i++){
        cin>>p[i];
    }

    int cnt=0;
    for(int i=0; i<n; i++){
        if(p[i] == i+1){
            if(i == n-1){
                swap(p[n-2], p[n-1]);
            }
            else{
                swap(p[i], p[i+1]);
            }
            cnt++;
        }
    }
    cout << cnt << endl;
}