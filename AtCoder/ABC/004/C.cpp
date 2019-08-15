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
    n = n % 30;

    vector<int> a={1, 2, 3, 4, 5, 6};
    for(int i=0; i<n; i++){
        int x = i%5 + 1, y = i%5 + 2;
        swap(a[x-1], a[y-1]);
    }
    for(int i=0; i<6; i++) cout << a[i];
    cout << endl;
}