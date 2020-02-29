#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
	int N,K;
	fin>>N>>K;
	
	long int kAns = 0;
	long int mAns = 0;
	
	for(int i=0;i<N;i++)
	{
		int x;
		fin>>x;
		if(x < K)
			mAns += x;
		else
		{
			if(x - (K*10) >= K)
			{
				kAns += 10;
				if(x - (K * 10) == K)
					kAns += 1;
				else
					mAns += (x - (K * 10));
			}
			else
			{
				while(x >= K)
				{
					kAns += 1;
					x -= K;
				}
				mAns += x;
			}
		}
	}
	
	fout<<kAns << " "<<mAns;
	
	return 0;
}
