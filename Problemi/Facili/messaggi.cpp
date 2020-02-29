#include <fstream>
#include <map>
#include <vector>
#include <string>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
	map<string, vector<string> > inviati;
	map<string, vector<string> > ricevuti;
	
	//N righe : mittente -> destinatario
	//R righe : operazione -> nome
	
	int N,R;
	fin>>N>>R;
	
	for(int i=0;i<N;i++)
	{
		string mittente, destinatario;
		fin>>mittente>>destinatario;
		inviati[mittente].push_back(destinatario);
		ricevuti[destinatario].push_back(mittente);
	}
	
	for(int i=0;i<R;i++)
	{
		string tizio, operazione;
		fin>>tizio>>operazione;
		if(operazione == "INVIATI")
		{
			fout<<inviati[tizio].size()<<" ";
			for(int j=0;j<inviati[tizio].size(); j++)
				fout<<inviati[tizio].at(j)<<" ";
			fout<<endl;
		}
		else
		{
			fout<<ricevuti[tizio].size()<<" ";
			for(int j=0;j<ricevuti[tizio].size(); j++)
				fout<<ricevuti[tizio].at(j)<<" ";
			fout<<endl;
		}
	}
	
	return 0;
}
