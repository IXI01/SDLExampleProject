#include "../include/Number.h"

Number::Number(int new_value)
{
    value=new_value;
}

Number::~Number()
{
    //dtor
}


void Number::add(Number second_number)
{
    value+=second_number.value;
    return;

}


int Number::getValue()
{
    return value;
}
