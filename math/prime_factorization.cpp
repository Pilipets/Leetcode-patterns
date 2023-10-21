//
// Get all prime factors of a given number
//
// https://www.geeksforgeeks.org/print-all-prime-factors-of-a-given-number/
//
// Algorithm:
// - While n is divisible by 2, print 2 and divide n by 2.
// - After step 1, n must be odd. Loop from i=3 to the square root of n. While i divides n, print i, n /= i.
// - If n is a prime number and is greater than 2, then n will not become 1 by the above two steps.
//
// O(sqrt(n)) complexity, O(1) space
//
void primeFactors(int n)
{
    while (n % 2 == 0)
    {
        cout << 2 << " ";
        n >>= 1;
    }
 
    for (int i = 3; i * i <= n; i += 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            cout << i << " ";
            n /= i;
        }
    }
 
    if (n > 2)
        cout << n << " ";
}


//
// prime factorization using O(n) space and O(log n) time complexity with sive pre-compute
//
// https://www.geeksforgeeks.org/prime-factorization-using-sieve-olog-n-multiple-queries/
//
// Calculating SPF (Smallest Prime Factor) for every number till n
// Time Complexity : O(nloglogn)
//
vector<int> sieve(int n)
{
    vector<int> spf(n);

    spf[1] = 1;
    for (int i = 2; i < n; i++)
        spf[i] = i;
 
    for (int i = 4; i < n; i += 2)
        spf[i] = 2;
 
    for (int i = 3; i * i < n; i++)
        if (spf[i] == i)
            for (int j = i * i; j < n; j += i)
                if (spf[j] == j)
                    spf[j] = i;

    return spf;
}
 
// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step
vector<int> getFactorization(const vector<int> &spf, int x)
{
    vector<int> ret;
    while (x != 1) {
        ret.push_back(spf[x]);
        x /= spf[x];
    }
    return ret;
}