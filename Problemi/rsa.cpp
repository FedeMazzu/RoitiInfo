#include <cstring>
#include <iostream>

using namespace std;

//FAST EXPO

int power(long long x, int y, int p)
{
    long long res = 1;

    x = x % p;

    while (y > 0) 
	{
        if (y % 2 == 1)
            res = (res*x) % p;
        y = y / 2;
        x = (x*x) % p;  
    }

    return res;
}

int rsa(int N, int d, int c) {
    // Decifra c calcolando c^d mod N
    return power(c, d, N);
}

void decifra(int N, int d, int L, int* messaggio, char* plaintext) {

    for (int i = 0; i < L; i++) {
        plaintext[i] = (char)rsa(N, d, messaggio[i]);
    }

    plaintext[L] = '\0';

}
