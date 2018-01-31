#include <iostream>

using namespace std;

int suma(int a, int b){
    return a+b;
}
int resta(int a, int b){
    return a-b;
}
int operacion (int a, int b, int (*f)(int,int)){
    return f(a,b);
}


template <class T, class Function>
doTemplateFunction(T a, T b, Function F){
    return F(a,b);
}    

template <class Function>
Function getTemplateOperation(char c){
     if (c == 's'){
        return suma;
    }
    if (c == 'd'){
        return duplica;
    }
    return resta;
}
int main(){
    cout << operacion(2,2,suma) << endl;
    cout<< operacion(3,1, resta) << endl;
    cout << doTemplateFunction(2,2,suma);
    cout << getTemplateOperation <int (*) (int,int)> ('s')(2,2);
    cout << getTemplateOperation <int (*) (int)> ('d')(3);
    
}