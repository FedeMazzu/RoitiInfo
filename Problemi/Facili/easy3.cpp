#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
    int N;
    int temp;
    int max = -1;
    int sum;
    std::vector<int> s;

    fin >> N;

    for(int i = 0; i < N; i++)
    {
        fin >> temp;
        s.push_back(temp);
    }

    sort(s.begin(), s.end(), std::greater<int>());

    for(int j = 1; j < N; j++)
    {
            sum = s[0] + s[j];
            if(sum%2 == 0 && sum > max)
            {
                max = sum;
                break;
            }
    }

    for(int j = 2; j < N; j++)
    {
            sum = s[1] + s[j];
            if(sum%2 == 0 && sum > max)
            {
                max = sum;
                break;
            }
    }


    fout << max;

    return 0;
}
