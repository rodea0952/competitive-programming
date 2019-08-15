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
    vector<int> a(n+10, 0);
    for(int i=1; i<=n; i++) cin>>a[i];

    int sum=0;
    for(int i=0; i<=n; i++){
        sum += abs(a[i+1] - a[i]);
    }
    
    for(int i=1; i<=n; i++){
        int i_sum = sum + abs(a[i+1] - a[i-1]) - (abs(a[i] - a[i-1]) + abs(a[i+1] - a[i]));
        cout << i_sum << endl;
    }
}