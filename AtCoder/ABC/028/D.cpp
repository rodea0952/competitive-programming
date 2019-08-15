#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD=1e9+7;
ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int main(){
    double n, k; cin>>n>>k;
    cout << fixed << setprecision(12) << (6*n*k-6*k*k+6*k-3*n-2)/(n*n*n) << endl;
}