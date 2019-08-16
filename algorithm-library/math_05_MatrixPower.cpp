#include <bits/stdc++.h>
using namespace std;

const int M = 10000;

// Fibonacci sequence

vector<vector<ll>> mul(vector<vector<ll>> &A, vector<vector<ll>> &B){
    vector<vector<ll>> C(A.size(), vector<ll>(B.size()));

    for(int i=0; i<A.size(); i++){
        for(int k=0; k<B.size(); k++){
            for(int j=0; j<B[0].size(); j++){
                (C[i][j] += (A[i][k] * B[k][j]) % M) %= M;
            }
        }
    }
    
    return C;
}

vector<vector<ll>> pow(vector<vector<ll>> A, ll n){
    vector<vector<ll>> B(A.size(), vector<ll>(A.size()));

    for(int i=0; i<A.size(); i++){
        B[i][i] = 1;
    }

    while(n > 0){
        if(n & 1LL) B = mul(B, A);
        A = mul(A, A);
        n >>= 1LL;
    }

    return B;
}

int main(){
    ll n; cin>>n;
    vector<vector<int>> A(2, vector<int>(2));
    A[0][0] = 1; A[0][1] = 1;
    A[1][0] = 1; A[1][1] = 0;
    A = pow(A, n);

    cout << A[1][0] << endl;
}