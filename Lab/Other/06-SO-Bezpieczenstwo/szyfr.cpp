#include <cstdlib>
#include <iostream>

using namespace std;

void szyfr(char *x) 
{
        for (; *x; *x = (*x - 1 / (~(~(*x) | 32) / 13 * 2 - 11 ) *13), x++);
}

int main(int argc, char *argv[])
{
    char tab[] = {'s','z','y','f','r'};
    
    for (int i=0; i<5; ++i)
        cout << tab[i] << " ";
	cout<< endl;
    szyfr(tab);
     for (int i=0; i<5; ++i)
        cout << tab[i] << " ";
     cout<< endl;
     szyfr(tab);
     for (int i=0; i<5; ++i)
        cout << tab[i] << " ";
      cout<< endl;
    return 0;
}
