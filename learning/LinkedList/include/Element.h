#ifndef ELEMENT_H
#define ELEMENT_H


class Element
{
    public:
        Element(int new_value);
        virtual ~Element();
        Element *next;
        void printList(Element *p);

    protected:
    private:
        int value;

};

#endif // ELEMENT_H
