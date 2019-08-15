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
    set<int> ans;
    for(int i=0; i<n; i++){
        int a; cin>>a;
        while(a % 2 == 0){
            a /= 2;
        }
        ans.insert(a);
    }
    cout << ans.size() << endl;
}