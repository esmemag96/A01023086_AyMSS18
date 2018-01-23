#include <iostream>
#include <string>

using namespace std;

class Mobiles{
	public:
		string *marca;
		string *SerialNum;
		string *modelo;
		virtual Mobiles* clone() = 0;
		Mobiles(){}
		
		Mobiles(string marca, string SerialNum, string modelo):marca(new string(marca)), SerialNum(new string(SerialNum)), modelo(new string(modelo)) {
			cout << "parametros " << marca << endl;
		}
		void encender(){
			cout << "Encendido" << endl;
		}
		void apagar(){
			cout << "Apagado" << endl;
		}
		void reiniciar(){
			cout << "Reiniciando" << endl;
		}
		void restaurar(){
			cout << "Restaurado" << endl;
		}

};

class Tablet:public Mobiles{
	public:
		Tablet(string marca, string SerialNum, string modelo): Mobiles (marca, SerialNum, modelo){
			
		}
		Mobiles* clone(){
			return new Tablet(*this);
		}
};


int main(){
	Tablet* t = new Tablet("Apple", "56483930", "iPad");
	cout << *(t->marca) << endl;
	cout << *(t->SerialNum) << endl;
	cout << *(t->modelo) << endl;
	return 0;
}