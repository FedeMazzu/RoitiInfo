#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
	int N;
	long long int ans = 0;
	fin>>N;
	map<int,bool> Handshake;
	map<int,bool>::iterator it;
	
	for(int i=0;i<N;i++)
	{
		int a,b;
		fin>>a>>b;
		a--;
		b--;
		Handshake[a] = true;
		Handshake[b] = false;
	}
	
	int inCounter = 0;
	for(it = Handshake.begin(); it!= Handshake.end(); it++)
	{
		if(it->second)
		{
			inCounter++;
			ans += inCounter;
		}
		else
		{
			ans += inCounter;
			inCounter--;
		}
	}
	
	fout<<ans;
	return 0;
}
