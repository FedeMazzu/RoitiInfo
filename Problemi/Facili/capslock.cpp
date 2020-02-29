#include <string>
#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
    int N;
    string ans = "";
    char c;
    fin>>N;
    
    fin.get(c); //remove \n char
    
    for(int i=0;i<N;i++)
    {
        fin.get(c);
        if(islower(c))
            c = toupper(c);
        else
            c = tolower(c);
        ans += c;
    }
        
    fout<<ans;
    return 0;
}
