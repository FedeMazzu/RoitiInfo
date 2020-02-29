#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
	int N;
	int ans = 0;
	fin>>N;
	
	bool italic = false;
	bool bold = false;
	
	for(int i=0;i<N;i++)
	{
		char c;
		fin>>c;	
		if(islower(c))
		{
			if(c == 'n')
			{
				if(italic == true)
				{
					italic = false;
					ans++;
				}
				if(bold == true)
				{
					bold = false;
					ans++;
				}
			}else if(c == 'i')
			{
				italic = true;
				if(bold == true)
				{
					bold = false;
					ans++;
				}
			}
		}
		else if(isupper(c))
		{
			if(c == 'N')
			{
				if(italic == true)
				{
					italic = false;
					ans++;
				}
				bold = true;
			}
			else
			{
				italic = true;
				bold = true;
			}
		}
	}
	if(italic == true)
		ans++;
	if(bold == true)
		ans++;
	
	fout<<ans;
	return 0;
}
