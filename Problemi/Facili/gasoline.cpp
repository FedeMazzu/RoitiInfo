#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
	int N;	fin>>N;
	int Costo[N],Distanza[N];
	int minCosto = 1001;
	unsigned long long int ans = 0;
	
	for(int i=0;i<N;i++)
		fin>>Costo[i];
	for(int i=0;i<N;i++)
		fin>>Distanza[i];
		
	for(int i=0;i<N;i++)
	{
		if(Costo[i] < minCosto)
			minCosto = Costo[i];
		ans += minCosto * Distanza[i];
	}
	
	fout<<ans;
	return 0;
}
