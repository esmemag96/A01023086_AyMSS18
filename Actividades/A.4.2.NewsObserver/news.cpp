#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Observer{
	public:
    	virtual void share(string message) = 0;
};

class MVS : public Observer{
	private:
		string news;

	public:	
		MVS(string n){ news = n; }
    	void share(string message){
    		cout << "\t - Noticieros " << news << ": " << message << endl;
    	}       
};

class Televisa : public Observer{
	private:
		string news;

	public:
		Televisa(string n){ news = n; }
    	void share(string message){
    		cout << "\t - Noticieros " << news << ": " << message << endl;
    	}          
};

class Azteca : public Observer{
	private:
		string news;

	public:
		Azteca(string n){ news = n; }
    	void share(string message){
    		cout << "\t - Noticieros " << news << ": " << message << endl;
    	}
};



class Subject{
   vector<Observer*> list;
	public:
		Subject() = default;
		void attach(Observer* observer){
			list.push_back(observer);
		}
		void detach(Observer* observer){
			list.push_back(observer);
		}
		void notify(string message){
			for(int i = 0; list.size()>i; i++){
				list[i]->share(message);
			}
		}
};

class Trump : public Subject{
	public:
		Trump() = default;
		void update(string message){
			notify(message);
		}
};

class Anaya : public Subject{
	public:
		Anaya() = default;
		void update(string message){
			notify(message);
		}
};

class Meade : public Subject{
	public:
		Meade() = default;
		void update(string message){
			notify(message);
		}
};

class Zavala : public Subject{
	public:
		Zavala() = default;
		void update(string message){
			notify(message);
		}
};
class AMLO : public Subject{
	public:
		AMLO() = default;
		void update(string message){
			notify(message);
		}
};

int main(){
	MVS* mvs = new MVS("MVS");
	Televisa* televisa = new Televisa("Televisa");
	Azteca* azteca = new Azteca("Azteca");

	Trump* trump = new Trump();
	Anaya* anaya = new Anaya();
	Meade* meade = new Meade();
    Zavala* zavala = new Zavala();
    AMLO* amlo = new AMLO();


	trump->attach(mvs);
	trump->attach(televisa);
	trump->attach(azteca);

	anaya->attach(televisa);
	anaya->attach(azteca);

    meade->attach(mvs);
	meade->attach(televisa);
	meade->attach(azteca);

	zavala->attach(televisa);

    amlo->attach(mvs);
	amlo->attach(televisa);
	amlo->attach(azteca);


	cout << endl << "Donald Trump:" << endl;
	trump->notify("Ya se armó el muro");

	cout << endl << "Ricardo Anaya:" << endl;
	anaya->notify("na na na na na na na");

	cout << endl << "Pepe Meade:" << endl;
	meade->notify("nadie me pela :(");
	
    cout << endl << "Margarita Zavala:" << endl;
	zavala->notify("esas son puras mentiras");

    cout << endl << "AMLO bebé:" << endl;
	amlo->notify("la mafia del poder");

	return 0;
}