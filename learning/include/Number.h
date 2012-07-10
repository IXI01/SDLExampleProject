#ifndef NUMBER_H
#define NUMBER_H


class Number
{
    public:
        Number(int new_value);
        virtual ~Number();
        void add(Number second_number);
        int getValue();
    protected:
    private:
        int value;

};

#endif // NUMBER_H
