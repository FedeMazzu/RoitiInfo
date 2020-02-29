#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
	int N;
	int ans = -1;
	fin>>N;
	
	for(int i=0;i<N;i++)
	{
		int a,b;
		fin>>a>>b;
		if((a+b) %2 == 0 && a+b > ans)
			ans = a+b;
	}
	fout<<ans;
	return 0;
}
