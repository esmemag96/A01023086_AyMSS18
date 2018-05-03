#include <iostream>

using namespace std;

class Collection{
    public:
        virtual void add(int* element) = 0;
        virtual int* at(int position) = 0;
        Iterator* getIterator();
};

class Iterator{
    IntCollection* collection:
    int cont;
    public:
        virtual int next() = 0;
        virtual bool hasNext() = 0;
};

class IntCollection{
    public:
        virtual void add (int* element) = 0;
        virtual int at(int position) = 0;
        virtual Iterator* getIterator() = 0;

};
class IntArray : public IntCollection{
    int * array;
    int size;
    int numElems;

    public:
        intArray(){
            size = 10;
            array= new int[size];
            numElems = 0;
        }
        void add(int element){
            if(numElems >= size){
                cout << "ya no hay espacio krnal";
                return;
            }
            array[numElems++] = element;
        }
        int at(int position) {
            if(size <= position < 0){
                cout << "índice no válido krnal";
                throw "out_of_range";
            }
            return array[position];
        }
        Iterator* getIterator(){
            return
        }
};

class ArrayIterator : public Iterator{
    public: 
        ArrayIterator(IntArray* intArray){
            collection = intArray;
            cont = 0;
        }
        int next(){
            return collection -> at(cont);
        }
};