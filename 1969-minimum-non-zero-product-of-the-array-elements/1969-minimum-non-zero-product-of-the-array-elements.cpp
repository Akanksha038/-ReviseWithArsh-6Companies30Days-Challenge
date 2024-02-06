class Solution {
    long long modpow(long long base, long long exp, long long mod) {
        base %= mod;
        long long ans = 1;
        while (exp > 0) {
            if (exp & 1) ans = ans * base % mod;
            base = base * base % mod;
            exp >>= 1;
        }
        return ans;
    }
public:
    int minNonZeroProduct(int p) {
        long long mod = 1e9 + 7, mx = (1LL << p) - 1, next = mx - 1, ans = 1;
        return modpow(next, mx / 2, mod) * (mx % mod) % mod;
    }
};