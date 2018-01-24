#include <iostream>
#include <string>

using namespace std;

class Vehiculo{
    public:
        virtual void ensamblado() = 0;
        virtual void hojalateria() = 0;
        virtual void pintura() = 0;
        virtual void entrega() = 0;
};

class Vehiculo1: public Vehiculo{
    public: 
        void ensamblado(){
            cout << "Estoy en ensamblado" << endl;
        }
        void hojalateria(){
            cout << "Estoy en hojalateria" << endl;
        }
        void pintura(){
            cout << "Estoy en pintura" << endl;
        }
        void entrega(){
            cout << "Estoy en entrega" << endl;
        }
};

class Creator{
      
    public:   
        template <class Tipo> 
        Tipo* factoryMethod(){
            return new Tipo;
        }    
        template <class Tipo>
        Tipo* create(){
            Tipo* myVehiculo;
            myVehiculo = factoryMethod<Tipo>();
            myVehiculo->ensamblado();
            myVehiculo->hojalateria();
            myVehiculo->pintura();
            myVehiculo->entrega();
            return myVehiculo;
        }

};


int main (){
    Creator* cliente = new Creator();
    
    Vehiculo1* BMW = cliente-> create<Vehiculo1>();
    Vehiculo1* NISSAN = cliente-> create<Vehiculo1>();
    Vehiculo1* DODGE = cliente-> create<Vehiculo1>();
    Vehiculo1* VV = cliente-> create<Vehiculo1>();

    return 1;
}