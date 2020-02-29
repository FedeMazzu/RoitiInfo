#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
	int N;
	fin>>N;
	
	int max;
	
	int a;
	fin>>a;
	max=a;
	
	for(int i=1;i<N;i++)
	{
		fin>>a;		
		if(a>max)
			max=a;
	}
	
	fout<<max;
	return 0;
}
