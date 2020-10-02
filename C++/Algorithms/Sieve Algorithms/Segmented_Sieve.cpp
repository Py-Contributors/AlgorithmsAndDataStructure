#include <bits/stdc++.h>

using namespace std;

/*considering the range to find primes between variable low and high,
we first need to create a simple sieve function t find all primes less than root of high*/
void simpleSieve(int lmt, vector<int>& prime)
{
    //a boolean array containing all numbers till high
   bool mark[lmt + 1];
   memset(mark, false, sizeof(mark));

   //marking all the indices of mark[] true, if they are prime
   for (int i = 2; i*i <= lmt; i++)
    {
      if (mark[i] == false)
      {
         prime.push_back(i);
         for (int j = i*i; j <= lmt; j += i)
            mark[j] = true;
      }
    }
}

//this function prints all prime numbers between low and high
//using primes from simple sieve
void PrimeInRange(int low, int high)
{
    //
   int lmt = floor(sqrt(high)) + 1;
   vector<int> prime;
   //simple sieve that will be used to find primes between low and high
   simpleSieve(lmt, prime);
   int n = high - low + 1;
   bool mark[n + 1];//an bool array having number of elements equal to high-low+1
   memset(mark, false, sizeof(mark));//initially, we will consider all values non prime

   //find primes in range between low and high using primes from simple sieve
   for (int i = 0; i < prime.size(); i++)
    {
      //minimum number of elements that are multiples of prime[i]
      int lowLim = floor(low / prime[i]) * prime[i];
      if (lowLim < low)
         lowLim += prime[i];

      //since mark has indices from 0 to n, and j starts from lower limit,
      //we mark [j - low] index
      for (int j = lowLim; j <= high; j += prime[i])
         mark[j - low] = true;
   }

   // All numbers left untouched, i.e, marked true are primes
   //So we print all primes between low and high
   for (int i = low; i <= high; i++)
      if (!mark[i - low])
         cout << i << " ";
}

int main()
{
   //initializing value of low and high as 10 and 80, you make take input
   int low = 10, high = 80;
   PrimeInRange(low, high);
   return 0;
}

