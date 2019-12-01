//altri programmatori gentili ci semplificano la vita e quindi bella
//fstream sta per file stream; è una libreria che ci serve per prendere in input da file o mandare in output 
#include <fstream>

//bo frega volendo non vi serve
using namespace std;

//scegliamo 2 file: d'ora in poi prenderemo in input da "input.txt" e manderemo in output in "output.txt"
//tutti i file devono trovarsi nella stessa directory di questo programma
ifstream fin("input.txt");
ofstream fout("output.txt");

/*	
	il main è il punto di accesso del programma
	è una funzione: una roba che prende qualcosa e restituisce altro
	nel nostro caso il main non prende niente ma restituisce uno 0 se il programma termina correttamente
*/

int main()
{
	//numero intero
	int oneTimeIateAbagel;
	//input da file con l'operatore " >> " che vuol dire "HEY sposta dal file dentro la variabile" (verso destra)
	fin>>oneTimeIateAbagel;
	//output su file con l'operatore " << " che vuol dire "HEY sposta dalla variabile verso il file" (verso sinistra)
	fout<<oneTimeIateAbagel; 
	
	return 0;
}
