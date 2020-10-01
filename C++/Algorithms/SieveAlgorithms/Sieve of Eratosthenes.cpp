/* Sieve of Erathosthenes
** Generate all primes less than an integer n
*/
#include <iostream>
#include <cmath>
#include <cstring>

void print_primes(int n) {
    bool prime[n+1];
    std::memset(prime, true, sizeof(prime));
    for (int i=2; pow(i, 2)<=n; i++) {
        if(prime[i]) {
            for (int j=pow(i, 2); j<=i; j+=i) {
                prime[j] = false;
            }
        }
    }
    for (int i=2; i<=n; i++) {
        if (prime[i] == true)
            std::cout << i << std::endl;
        }
}

int main() {
    print_primes(25);
}
