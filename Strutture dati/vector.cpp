#include <iostream>
#include <vector>

using namespace std;

int main()
{
	//array dalla dimensione dinamica
	vector<int> ilCoccodrilloDiSonic;
	
	//scegliamo una dimensione
	ilCoccodrilloDiSonic.resize(4);
	
	//riempiamo
	for(int i=0;i<ilCoccodrilloDiSonic.size();i++)
		ilCoccodrilloDiSonic[i] = 232;
	
	//cambiamo idea ed aggiungiamo degli elementi alla fine del vector
	ilCoccodrilloDiSonic.push_back(666);
	ilCoccodrilloDiSonic.push_back(69);
	ilCoccodrilloDiSonic.push_back(911);
	ilCoccodrilloDiSonic.push_back(420);
	
	//la nuova dimensione del vector è 4 + 4 = 8; 4 del resize e 1 del push_back ripetuto 4 volte
	
	cout<<ilCoccodrilloDiSonic[4];
	
    return 0;
}
