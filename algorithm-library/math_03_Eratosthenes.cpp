bool isPrime[MAX_N];
void eratosthenes(int n){
    for(int i=0; i<=n; i++) isPrime[i] = true;
    isPrime[0] = false, isPrime[1] = false;

    for(int i=2; i*i<=n; i++){
        if(isPrime[i]){
            for(int j=2; i*j<=n; j++){
                isPrime[i*j] = false;
            }
        }
    }
}

bool isPrime[MAX_L];
bool isPrimeSmall[MAX_SQRT_B];

void segment_sieve(ll a, ll b){
    for(int i=0; (ll)i*i<b; i++) isPrimeSmall[i] = true;
    for(int i=0; i<b-a; i++) isPrime[i] = true;

    for(int i=2; (ll)i*i<b; i++){
        if(isPrimeSmall[i]){
            for(int j=2*i; (ll)j*j<b; j+=i) isPrimeSmall[j] = false;
            for(ll j=max(2LL, (a+i-1)/i)*i; j<b; j+=i) isPrime[j] = false;
        }
    }
}