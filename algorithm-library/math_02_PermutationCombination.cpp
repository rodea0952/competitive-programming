const int MAX_N = ;
mint fact[MAX_N], finv[MAX_N];
mint comb(int n, int r){
    if(n < r || r < 0) return 0;
    return fact[n] / fact[n - r] / fact[r];
}

mint perm(int n, int r){
    if(n < r || r < 0) return 0;
    return comb(n, r) * fact[r];
} 

void fact_init(int n){
    fact[0] = 1;
    for(int i=1; i<=n; i++){
        fact[i] = fact[i - 1] * i;
    }
}