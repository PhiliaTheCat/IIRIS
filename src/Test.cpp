#include <iostream>

#include "../include/PNG_Interface"
#include "../include/Processor"

using namespace std;
using namespace ptc;

int main()
{
    Pic test = Read_from_PNG("test\\in\\1.png");

    Write_into_PNG(test, "test\\out\\1.png");

    test = Compress(test, .5);

    cout << test.get_height() << ' ' << test.get_width() << endl;

    for (int i = 0; i < 16; i += 1)
        cout << int(test[0][i]) << ' ';

    Write_into_PNG(test, "test\\out\\2.png");

    cout << endl;

    return 0;
}
