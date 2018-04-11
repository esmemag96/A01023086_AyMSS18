#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Videogame{
    public: 
        int gameId;
        float gamePrice;
        string gameName; 
        string gameCompany;
        string gamePlatform; 

        Videogame()=default; 

        void Start(){
            cout << "Concepción..." << endl;
        }
        void Design(){
            cout << "Diseño..." << endl;
        }
        void Planification(){
            cout << "Planificación..." << endl; 
        }
        void Production(){
            cout << "Producción..." << endl;
        }
        void Tests(){
            cout << "Puebas de aceptación..." << endl;
        }
        void setPrice(float p){
            gamePrice = p; 
        }
};

class Strategy : public Videogame {
    protected: 
        Strategy() = default;
};
class Adventure : public Videogame{
    protected: 
        Adventure() = default;
};
class Learning :public Videogame{
    protected: 
        Learning() = default;
};
class Fight : public Strategy{
    public:
        Fight(){
            gameName = "Strategy1";
            gameCompany = "Salvato";
            gamePlatform = "Xbox";
        }
};

class Arcade : public Strategy{
    public: 
        Arcade(){
            gameName = "Strategy2";
            gameCompany = "Xgames";
            gamePlatform = "Gamecube";
        }
};

class Plataforma : public Adventure{
    public:
        Plataforma(){
            gameName = "Adventure1";
            gameCompany = "FunGames";
            gamePlatform = "Xbox";   
        }
};

class Graphic : public Adventure{
    public: 
        Graphic(){
            gameName = "Adventure2";
            gameCompany = "YOLOGames";
            gamePlatform = "Play Station";
        }
};

class Languages : public Learning{
    public: 
        Languages(){
            gameName = "Learning1";
            gameCompany = "Hercules";
            gamePlatform = "Wii";
        }
};

class Music : public Learning{
    public:
        Music(){
            gameName = "Learning2"; 
            gameCompany = "DoReMiFaSolLa";
            gamePlatform = "PC";
        }
};


template<class T>
class Iterator;

template<class T>
    class Collection{
        public: 
            T* array; 
            int max; 
            int act;

            friend class Iterator<T>; 

            Collection(){
                max = 15;
                act = 0; 
                array = new T[max]; 
            }

            void add(T game){
                if (act <= max){
                    array[act++] = game; 
                }
                else{
                    cout << "Espacio en el inventario insuficiente" << endl;
                }
            }

            T at (int position){
                if (0 > position){
                    cout << "índice no valido" << endl; 
                    throw "out of range"; 
                }
            }

            int getNumElements(){
                return act;
            }

            void imprimirColl(){
                for (int i = 0; i < act; i++){
                    cout << "name = " << array[i]->gameName <<
                    ", " << "gameCompany = " << array[i]->gameCompany << 
                    ",  " << "gamePlatform = " << array[i]->gamePlatform <<
                    ",  " << "Price = " << array[i]->gamePrice << endl;
                }
            }

            Iterator<T>* getIterator();
    };

template<class T>
class Iterator{
protected:
    Collection<T> collection;
    int cont = 0;
public:
    Iterator(const Collection<T>& collection) : collection(collection){}


    virtual T next(){
        T a  = collection.at(cont);
        cont++;
        return a; 
    }
    virtual bool hasNext(){
        if (cont < collection.act){
            return true; 
        }else{
            return false; 
        }
    }
};

template<class T>

Iterator<T>* Collection<T>:: getIterator(){
    return new Iterator<T>(*this);
} 

class Inventario{
protected: 
    int i = 1;
    int t = 0; 
public: 
    Inventario(){}
    Collection<Videogame*> inv; 
    Iterator<Videogame*> *it; 

    void crearjuego(){
        Inventario* inventario = new Inventario(); 
    }
    void addGame (Videogame* v){
        it = inv.getIterator();
        inv.add(v);
        i++;
    }

    int getElements(){
        return inv.getNumElements();
    }

    void imprimir(){
        inv.imprimirColl();
    }

};

//COMMANDS

class Command
{
public:
	virtual void execute() = 0;
};
 
// Receiver 
class Accion 
{
public:
	void undo() {
		cout << "undo" << endl;
	}
	void redo() {
		cout << "redo" << endl;
	}
}; 

class undoCommand : public Command 
{
public:
    undoCommand(Accion *Accion) : mAction(Accion) {}
	void execute(){
		mAction->redo();
	}
private:
	Accion *mAction;
};
 
class redoCommand : public Command 
{
public:
        redoCommand(Accion *Accion) : mAction(Accion) {}
	void execute(){
		mAction->undo();
	}
private:
	Accion *mAction;
};

// Invoker 
// Stores the ConcreteCommand object 
class RemoteControl 
{
public:
	void setCommand(Command *cmd) {
		mCmd = cmd;
	}

	void buttonPressed() {
		mCmd->execute();
	} 
private:
	Command *mCmd;
};
 


int main()
{
    Inventario* uno = new Inventario();

    cout << "///////////////// MENÚ INVENTARIO \\\\\\\\\\\\\\\\" << endl;
    cout << "1.- Agregar un nuevo juego" <<endl;
    cout <<"2.- Borrar un juego" <<endl;
    cout <<"3.- Revisar el inventario" <<endl;
    cout <<"4.- Buscar un juego" << endl;

    int ans;
    cin >> ans;


    switch(ans){
        case 1:
            cout << "Agregando juego..." << endl;
            break;
        case 2:
            cout << "Borrando juego ..." << endl;
            break;
        case 3:
            cout << "Revisando inventario..." << endl;
            break;
        case 4:
            cout << "Buscando juego..." << endl;
    }



  
    return 0;
}