#include <fstream>
#include <vector>
#include <utility>
#include <map>
#include <queue>

using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

void dijkstra(vector<vector<pair<int,long long> > > Grafo, int partenza, int pigrizia, unsigned long long int *Somme, int N, int run);

int main(){
	int N; fin>>N; //nodi (aule) totali del grafo
	int M; fin>>M; //collegamenti (corridoi) totali del grafo
	int K; fin>>K; //commissioni
	
	//vettore con punti di partenza (aule commissioni) e pigrizie annesse in pair
	vector<pair<int,int> > Partenze;
	vector<vector<pair<int,long long> > > Grafo;
	map<long long,long long> Minimi;
	map<long long,long long>::iterator it;
	unsigned long long int Somme[N];
	Partenze.resize(K);
	Grafo.resize(N);
	
	//input partenze
	for(int i=0;i<K;i++){
		int a;
		fin>>a;
		Partenze[i] = make_pair(a,0);
	}
	//input pigrizie
	for(int i=0;i<K;i++){
		int a;
		fin>>a;
		Partenze[i].second=a;
	}
	//input collegamenti
	for(int i=0;i<M;i++){
		int a,b,w;
		fin>>a>>b>>w;
		Grafo[a].push_back(make_pair(b,w));	//Grafo[0].first = nodo di arrivo ; Grafo[0].second * Partenza[x].second + PesoNodo[x] = insoddisfazione minima. 
		Grafo[b].push_back(make_pair(a,w));
	}
	
	for(int i=0;i<K;i++)
		dijkstra(Grafo,Partenze[i].first,Partenze[i].second,Somme,N,i);

	for(int i=0;i<N;i++)
		Minimi[Somme[i]]++;
		
	it = Minimi.begin();
	fout<<it->second<<endl;
	fout<<it->first<<endl;
	return 0;
}

void dijkstra(vector<vector<pair<int,long long> > > Grafo, int partenza, int pigrizia, unsigned long long int *Somme, int N, int run){
	unsigned long long int Distanze[N];
	for(int i=0;i<N;i++)	Distanze[i]=1ULL<<60;
	Distanze[partenza] = 0;
	priority_queue<pair<unsigned long long int,int>,vector<pair<unsigned long long int,int> >,greater<pair<unsigned long long int,int> > > Q;
	Q.push(make_pair(0,partenza));
	while(!Q.empty()){
		unsigned long long int d = Q.top().first;
		int n = Q.top().second;
		Q.pop();
		if(d>Distanze[n]) continue;
		for(int i=0;i<Grafo[n].size();i++){
			if(Distanze[Grafo[n][i].first] > (long long)Distanze[n] + Grafo[n][i].second * (long long)pigrizia){
				Distanze[Grafo[n][i].first] = Distanze[n] + Grafo[n][i].second * pigrizia;
				Q.push(make_pair(Distanze[Grafo[n][i].first],Grafo[n][i].first));
			}
		}
	}
	for(int i=0;i<N;i++){
		if(run==0)
			Somme[i]=0;
		Somme[i]+=Distanze[i];
	}
	return ;
}
