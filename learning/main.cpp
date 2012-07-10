#include <iostream>
#include "include/Number.h"

using namespace std;

int main()
{
    Number number1(5);
    Number number2(6);

    number1.add(number2);

    cout << number1.getValue() << endl;



    return 0;
}
