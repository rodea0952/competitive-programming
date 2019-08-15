#include<bits/stdc++.h>
using namespace std;

int main(){
    int r, c, k, n; cin>>r>>c>>k>>n;
    int R[n+10], C[n+10];
    vector<int> R_sum(r+10, 0), C_sum(c+10, 0);
    for(int i=0; i<n; i++){
        cin>>R[i]>>C[i];
        R[i]--, C[i]--;
        R_sum[R[i]]++;
        C_sum[C[i]]++;
    }

    vector<int> R_candy(n+10, 0), C_candy(n+10, 0);
    for(int i=0; i<r; i++){
        R_candy[R_sum[i]]++;
    }
    for(int i=0; i<c; i++){
        C_candy[C_sum[i]]++;
    }

    long long sum=0;
    for(int i=0; i<=k; i++){
        sum += R_candy[i] * C_candy[k-i];
    }

    for(int i=0; i<n; i++){
        if(R_sum[R[i]] + C_sum[C[i]] == k) sum--;
        else if(R_sum[R[i]] + C_sum[C[i]] == k + 1) sum++;
    }
    cout << sum << endl;
}