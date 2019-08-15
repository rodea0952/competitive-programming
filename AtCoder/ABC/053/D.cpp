#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD=1e9+7;
ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int main(){
    int n; cin>>n;
    vector<int> cnt(100010, 0);
    for(int i=0; i<n; i++){
        int a; cin>>a;
        cnt[a]++;
    }

    int sum=0;
    for(int i=1; i<=100000; i++){
        if(cnt[i] > 0) cnt[i]--;
        sum += cnt[i];
    }

    if(sum % 2 == 1) sum++;

    cout << n - sum << endl;
}