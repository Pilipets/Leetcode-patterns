// Check if given number is prime
//
// https://www.geeksforgeeks.org/prime-numbers/
// https://en.wikipedia.org/wiki/Primality_test
// https://leetcode.com/problems/count-primes/  
//
// Goldbach Conjecture: Every even integer greater than 2 can be expressed as the sum of two primes.
//
// Time complexity O(sqrt(N)), space O(1)


bool isPrime(int n)
{
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
 
    // Check from 2 to square root of n
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return false;
 
    return true;
}


// Another approach same complexiy
//
bool IsPrime(int n)
{
    if (n == 2 || n == 3)
        return true;

    if (n <= 1 || n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
}