// Sieve of Eratosthenes
//
// https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
// https://leetcode.com/problems/count-primes/
//
// Faster implementation from geeksforgeeks, but still time O(n*log(log(n))), space O(n)
//
// https://leetcode.com/problems/count-primes/discuss/57593/12-ms-Java-solution-modified-from-the-hint-method-beats-99.95
// https://www.geeksforgeeks.org/sieve-of-eratosthenes/
//
// Algorithm:
// - It inverts the true / false meanings in the traditional Sieve of Eratosthenes implementation.
// true, here, means a composite number, not a prime.
// - It doesn't update the array values for any even numbers.
// They all stay false, because changing them to true would be needless bookkeeping.
//
class Solution {
public:
    int countPrimes(int n) {
        if (n < 3) return 0;
        
        /** 
         * Start with the assumption that half the numbers below n are
         * prime candidates, since we know that half of them are even,
         * and so _in general_ aren't prime.
         * 1 and 2 cancel each other as odd non-prime and even prime
         */
        int c = n / 2;
        
        bool composite[5000001]{};
        
        for (int i = 3; i * i < n; i += 2) {
            if (composite[i]) {
                continue;
            }

            for (int j = i * i; j < n; j += 2 * i) {
                if (!composite[j]) {
                    c--;
                    composite[j] = true;
                }
            }
        }
        return c;
    }
};




// Implementation from geeksforgeeks, still time O(n*log(log(n))), but O(n/2) space
//
// https://www.geeksforgeeks.org/sieve-of-eratosthenes/
//
class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2)
            return 0;

        bool primes[2500001]{}; // n/2+1

        primes[0] = true;
        for (int i = 3; i*i <= n; i += 2)
            if (primes[i >> 1] == false)
                for (int j = 3 * i; j <= n; j += 2 * i)
                    primes[j >> 1] = true;
        
        int res = 1; // 2
        for (int i = 3; i < n; i += 2)
            if (primes[i >> 1] == false) // i is prime
                res += 1;

        return res;
    }
};


// Sieve of Eratosthenes in O(n) time, O(n) space
// Quite slow for whatever reason, so non-practical
//
// https://www.geeksforgeeks.org/sieve-eratosthenes-0n-time-complexity/
//
// Algorithm:
// - For every number i where i varies from 2 to N-1:
// Check if the number is prime. If the number is prime, store it in prime array.
// - For every prime numbers j less than or equal to the smallest prime factor p of i:
// Mark all numbers i*p as non_prime.
// Mark smallest prime factor of i*p as j
//
class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2)
            return 0;
        
        bool isprime[5000001];
        memset(isprime, true, n);

        vector<int> prime;
        int SPF[5000001]{};

        isprime[0] = isprime[1] = false; // 0 and 1 are not prime
 
        // Fill rest of the entries
        for (int i = 2; i < n; i++)
        {
            if (isprime[i])
            {
                prime.push_back(i);
                SPF[i] = i;
            }

            // Remove all multiples of  i * prime[j] which are not prime by making isPrime[i*prime[j]] = false
            // and put smallest prime factor of i * Prime[j] as prime[j]
            // [ for exp :let  i = 5 , j = 0 , prime[j] = 2 [ i*prime[j] = 10 ]
            // so smallest prime factor of '10' is '2' that is prime[j] ]
            // this loop run only one time for number which are not prime
            for (int j = 0; j < prime.size() && i * prime[j] < n && prime[j] <= SPF[i]; j++)
            {
                isprime[i * prime[j]] = false;
                SPF[i * prime[j]] = prime[j]; // put smallest prime factor of i*prime[j]
            }
        }

        return prime.size();
    }
};