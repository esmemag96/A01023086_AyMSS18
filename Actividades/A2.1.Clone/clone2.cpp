#include <iostream>
#include <string>

using namespace std;

class Mobiles{
	public:
		string *marca;
		string modelo;
		string *SerialNum;
		string version;
		string capacidad;
		virtual Mobiles* clone() = 0;

		Mobiles(){}	
		Mobiles(string marca, string SerialNum, string version, string modelo, string capacidad):marca(new string(marca)), SerialNum(new string(SerialNum)), version(version), modelo(modelo), capacidad(capacidad){
			cout << "Parametros " << marca << endl;
		}
		void encender(){
			cout << " Encendido" << endl;
		}
		void apagar(){
			cout << "Apagado" << endl;
		}
		void reiniciar(){
			cout << "Reiniciando" << endl;
		}
		void restaurar(){
			cout << "Restaurando" << endl;
		}

};

template<class A, class B>
class ClaseHija:public B{
	public:
		Mobiles* clone(){
			return new A(static_cast<A&> (*this));
		}
		ClaseHija(){}
};

class Tablet:public ClaseHija<Tablet, Mobiles>{
	
	public:
		Tablet(string m, string s, string mod, string v, string c){
			marca = &m;
			SerialNum = &s;
			modelo = mod;
			version = v;
			capacidad = c;
		}
		Tablet(){}
		
		Tablet(const Tablet& m){
			marca = m.marca;
			SerialNum = m.SerialNum;
			modelo = m.modelo;
		}
};

class SmartPhone: public ClaseHija<SmartPhone, Mobiles>{
	public: 
		SmartPhone(string m, string s, string mod, string v, string c){
			marca = &m;
			SerialNum = &s;
			modelo = mod;
			version = v;
			capacidad = c;
		}
		SmartPhone(){}
		SmartPhone(const SmartPhone& m){
			marca = m.marca;
			SerialNum = m.SerialNum;
			modelo = m.modelo;
		}
};

class SmartWatch: public ClaseHija<SmartWatch, Mobiles>{
		public: 
		SmartWatch(string m, string s, string mod, string v, string c){
			marca = &m;
			SerialNum = &s;
			modelo = mod;
			version = v;
			capacidad = c;
		}
		SmartWatch(){}
		SmartWatch(const SmartPhone& m){
			marca = m.marca;
			SerialNum = m.SerialNum;
			modelo = m.modelo;
		}
	
};

int main(){
	Tablet* tablet1 = new Tablet("Apple", "0090992", "iPad", "Pro", "256");
	Tablet* tablet2 = new Tablet("Apple", "0090995", "iPad", "3", "64");
	SmartPhone* phone1 = new SmartPhone("Apple", "0090994", "iPhone", "8", "64");
	SmartPhone* phone2 = new SmartPhone("Samsung", "6435984", "Galaxy", "S8", "32");
	SmartWatch* watch1 = new SmartWatch("Apple", "0090993", "Apple Watch", "3", "16");
	SmartWatch* watch2 = new SmartWatch("Samsung", "6435985", "Gear", "S3", "64");

	cout << "Tablet" << endl << "Marca: " << *(tablet1->marca) << endl << "Numero Serial: " << *(tablet1->SerialNum) << endl << "Modelo: " << (tablet1-> modelo) << endl << "Versión: " << (tablet1->version)  << endl << "Capacidad: "  << (tablet1->capacidad) << endl;
	cout << endl << "SmartPhone" << endl << "Marca: " << *(phone1->marca) << endl << "Numero Serial: " << *(phone1->SerialNum) << endl << "Modelo: " << (phone1-> modelo) << endl << "Versión: " << (phone1->version)  << endl << "Capacidad: "  << (phone1->capacidad) << endl;
	cout << endl << "SmartWatch" << endl << "Marca: " << *(watch1->marca) << endl << "Numero Serial: " << *(watch1->SerialNum) << endl << "Modelo: " << (watch1-> modelo) << endl << "Versión: " << (watch1->version)  << endl << "Capacidad: "  << (watch1->capacidad) << endl;

	(tablet1->encender());
	(phone1->reiniciar());
	(watch1->apagar());
	(tablet2->restaurar());

	return 0;
}