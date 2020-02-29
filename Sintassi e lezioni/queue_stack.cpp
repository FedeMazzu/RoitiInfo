#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main()
{
	stack<int> pila;		//località in provincia di Gressan(Val d'Aosta)
	queue<int> coda;
	
	/*
		Pensate di impilare dei piatti uno sull'altro. Per qualche motivo non potete togliere i piatti da sotto ma solo da sopra.
		Bene.
		Se impilate i piatti numero 1, 2, e 3 - poi per tornare indietro dovete togliere prima il 3 poi il 2 e poi l'1
		quindi l'ultimo elemento inserito è il primo che consideriamo per fare delle operazioni, prima di passare al successivo.
		
		ok, lol
		
		Pensate di mettervi in coda al supermercato. Per qualche motivo non potete superare la persona difronte a voi.
		Bene.
		Se mettete in coda le persone 1, 2, e 3 - poi queste devono essere considerate in ordine: prima passa 1 poi 2 e poi 3
		
		Pila: il primo elemento inserito è l'ultimo che viene esaminato
		Coda: il primo elemento inserito è il primo che viene esaminato
		
	*/
	
	//riempiamo la pila
	pila.push(1);
	pila.push(2);
	pila.push(3);
	
	//riempiamo la coda
	for(int i=0;i<3;i++) 
		coda.push(i+1);
	
	cout<<"Output pila:\n";
	while(!pila.empty())		//pila.empty() è una funzione che ci dice se la pila è vuota. !pila.empty se la pila contiene qualcosa
	{
		//pila.top() prende l'elemento da esaminare; pila.pop() toglie l'elemento esaminato 
		cout<<pila.top()<<" ";
		pila.pop();
	}
	
	cout<<"\nOutput queue:\n";
	while(!coda.empty())
	{
		cout<<coda.front()<<" ";
		coda.pop();
	}
	
	return 0;
}
