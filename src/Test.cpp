#include <iostream>

#include "../include/PNG_Interface"

using namespace std;
using namespace ptc;

int main()
{
    Pic test;
    
    try
    {
        test = Read_from_PNG("test/1.png");
    }
    catch (const char info[])
    {
        cout << info << endl;
    }

    for (int i = 0; i < 16; i += 1)
        cout << int(test[0][i]) << ' ';
    cout << endl;
    
    return 0;
}
