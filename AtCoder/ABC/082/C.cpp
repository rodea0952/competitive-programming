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
    int sum=0;
    vector<int> cnt(100010, 0);
    for(int i=0; i<n; i++){
        int a; cin>>a;
        if(a > 1e5) sum++;
        else cnt[a]++;
    }

    for(int i=1; i<=1e5; i++){
        if(cnt[i] < i) sum += cnt[i];
        else if(cnt[i] > i) sum += (cnt[i] - i);
    }
    cout << sum << endl;
}