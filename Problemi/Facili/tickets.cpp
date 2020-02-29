#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
    ll N;
    fin>>N;
    
	ll ans = (-1+sqrt(1+(8*N)))/2;

    fout<<ans;
    return 0;
}
