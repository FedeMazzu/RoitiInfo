#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

/*
	Bella iscriviti su training.olinfo.it
	e ragiona su come fare il problema "La dieta di poldo"
	
	se non riesci l'importante è capire
	
	per arrivare a pensare una soluzione di questo tipo 
	è comodo ridurre il problema ad una sua istanza più piccola
	
	per saperne di più sulla programmazione dinamica (estremamente importante) : 
	http://ioi.di.unimi.it/dinamica.pdf
*/

int main()
{
	//lunghezza menù
	int N;
	fin>>N;
	
	//riempio un array prendendo in input i panini da file
	int panini[N];
	for(int i=0;i<N;i++)
		fin>>panini[i];
	
	//massimo conterrà la risposta al problema
	int massimo = 0;
	//lunghezza segna quanti panini posso mangiare al massimo se considero solo
	//quelli contenuti tra l'indice attuale i e l'ultimo con i che viene decrementato
	//puoi anche ragionare tenendo fisso lo 0 e facendo scorrere i verso destra bo fai un disegnino sry
	int lunghezza[N];
	for(int i=0;i<N;i++)
		lunghezza[i] = 1;
	
	//parto dall'ultimo elemento (N-1) e arrivo fino allo 0. tra 0 ed N-1 ci sono N numeri quindi torna tutto
	for(int i=N-1; i>=0; i--)
	{
		//i rappresenta l'indice del panino che sto considerando. ora lo confronto con il panino di indice j
		//con j che va nel senso opposto di i partendo dallo stesso
		for(int j=i; j<N; j++)
		{
			//se è fattibile e se così facendo otterremo una lunghezza più lunga...
			if( panini[j] < panini[i] && lunghezza[j]+1 > lunghezza[i] )
				//modifico la lunghezza del panino[i]
				lunghezza[i] = lunghezza[j]+1;
		}
		//in massimo metto la soluzione più grande tra la precedente (1 è la lunghezza minima sempre) e l'attuale
		massimo = max(lunghezza[i], massimo); 
	}
	
	//output
	fout<<massimo;
	return 0;
}
