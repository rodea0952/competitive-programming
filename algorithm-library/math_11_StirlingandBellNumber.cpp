// n 個の玉を区別する
// k 個の箱を区別しない
// 入れ方は 1 個以上
// スターリング数
// S(n, k) = S(n - 1, k - 1) + k * S(n - 1, k)
// Σ(-1)^(k - i) * kCi * i^n / (k!) より O(klogn) に減らせる
vector<vector<ll>> S(1010, vector<ll>(1010, 0));
void stir_init(){
    S[0][0] = 1;
    for(int n=1; n<1010; n++){
        for(int k=1; k<1010; k++){
            S[n][k] = S[n - 1][k - 1] + k * S[n - 1][k];
            S[n][k] %= MOD;
        }
    }
}

// n 個の玉を区別する
// k 個の箱を区別しない
// 入れ方は制限なし
// ベル数
// B(n, k) = S(n, 0) + S(n, 1) + ... + S(n, k)
int bell(int n, int k){
    ll B = 0;
    for(int i=0; i<=k; i++){
        B += S[n][i];
        B %= MOD;
    }

    return B;
}