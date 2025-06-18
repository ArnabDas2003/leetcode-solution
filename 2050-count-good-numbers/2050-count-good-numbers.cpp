class Solution {
public:
    const int MOD = 1e9 + 7;

    // Fast modular exponentiation
    long long modPow(long long base, long long exp) {
        long long result = 1;
        base = base % MOD;

        while (exp > 0) {
            if (exp % 2 == 1)
                result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long evenCount, oddCount;
        if (n % 2 == 0) {
            evenCount = n / 2;
            oddCount = n / 2;
        } else {
            evenCount = n / 2 + 1;
            oddCount = n / 2;
        }

        long long evenPow = modPow(5, evenCount); // 5 choices at even indices
        long long oddPow = modPow(4, oddCount);   // 4 choices at odd indices

        return (evenPow * oddPow) % MOD;
    }
};
