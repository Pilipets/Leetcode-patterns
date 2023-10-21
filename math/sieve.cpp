// Sieve of Eratosthenes
//
// https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
// https://leetcode.com/problems/count-primes/


// Time complexity O(n * log(log(n))), space O(n)
//
// https://www.geeksforgeeks.org/sieve-of-eratosthenes/
// https://www.geeksforgeeks.org/how-is-the-time-complexity-of-sieve-of-eratosthenes-is-nloglogn/
//
class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2)
            return 0;

        bool primes[50000001];
        memset(primes, true, n);

        for(int i = 4; i < n; i += 2)
            primes[i] = false;

        for(int i = 3; i < n; i += 2)
            if(primes[i])
                for(size_t j = i*1LL*i; j < n; j += i)
                    primes[j] = false;

        return count(begin(primes) + 2, begin(primes) + n, true);
    }
};


// bitset Time complexity O(n * log(log(n))), space O(n)
//
class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2)
            return 0;
        
        std::bitset<5000001> primes;
        primes.set();
        
        for(int i = 4; i < n; i += 2)
            primes.reset(i);

        for(int i = 3; i < n; i += 2)
            if(primes.test(i))
                for(size_t j = i*1LL*i; j < n; j += i)
                    primes.reset(j);

        return primes.count() - 2 - (5000001 - n) ;
    }
};