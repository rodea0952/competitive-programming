vector<ll> prime_factorization(ll n){
    vector<ll> v;
    ll num = n;
    for(int i=2; i*i<=n; i++){
        while(num % i == 0){
            num /= i;
            v.emplace_back(i);
        }
    }

    if(num != 1){
        v.emplace_back(num);
    }

    return v;
}