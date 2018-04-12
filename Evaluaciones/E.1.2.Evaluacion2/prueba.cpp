// Esmeralda Magdaleno Morales
// A01023086
// Examen Parcial 2
// :D
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Visitor;

class Videogame{
    public: 
        int gameId;
        float gamePrice;
        string gameName; 
        string gameCompany;
        string gamePlatform; 
        string gameClasification;

        Videogame()=default; 
        void Start(){
            cout << "Concepción del juego" << endl;
        }
        void Design(){
            cout << "Diseño del juego" << endl;
        }
        void Planification(){
            cout << "Planificación del juego" << endl; 
        }
        void Production(){
            cout << "Producción del juego" << endl;
        }
        void Tests(){
            cout << "Puebas de aceptación del juego" << endl;
        }
        void setPrice(float p){
            gamePrice = p; 
        }
        void accept(Visitor* visitor, float a);
};

class Strategy : public Videogame {
    protected: 
        Strategy() = default;
    public: 
        void accept(Visitor* visitor, float a);
};
class Adventure : public Videogame{
    protected: 
        Adventure() = default;
    public: 
        void accept(Visitor* visitor, float a);
};
class Learning :public Videogame{
    protected: 
        Learning() = default;
    public: 
        void accept(Visitor* visitor, float a);
};
class Fight : public Strategy{
    public:
        Fight(){
            gameName = "Strategy1";
            gameCompany = "Salvato";
            gamePlatform = "Xbox";
            gameClasification = "T";
        }
};

class Arcade : public Strategy{
    public: 
        Arcade(){
            gameName = "Strategy2";
            gameCompany = "Xgames";
            gamePlatform = "Gamecube";
            gameClasification = "E";
        }
};

class Platform : public Adventure{
    public:
        Platform(){
            gameName = "Adventure1";
            gameCompany = "FunGames";
            gamePlatform = "Xbox";   
            gameClasification = "E";
        }
};

class Graphic : public Adventure{
    public: 
        Graphic(){
            gameName = "Adventure2";
            gameCompany = "YOLOGames";
            gamePlatform = "Play Station";
            gameClasification = "M";
        }
};

class Languages : public Learning{
    public: 
        Languages(){
            gameName = "Learning1";
            gameCompany = "Hercules";
            gamePlatform = "Wii";
            gameClasification = "E";
        }
};

class Music : public Learning{
    public:
        Music(){
            gameName = "Learning2"; 
            gameCompany = "DoReMiFaSolLa";
            gamePlatform = "PC";
            gameClasification = "E";
        }
};


template<class Temp>
class Iterator;

class Visitor{
    public: 
        virtual void visit(Strategy, int cant)=0;
        virtual void visit(Adventure, int cant)=0;
        virtual void visit(Learning, int cant)=0;
};

class Discount : public Visitor{
public:
    void visit (Strategy game, int cant){
        float div = cant/10;
        game.gamePrice = game.gamePrice - game.gamePrice * 1 + div;
    }
    void visit (Adventure game, int cant){
        float div = cant/10;
        game.gamePrice = game.gamePrice - game.gamePrice * 1 + div;
    }
    void visit (Learning game, int cant){
        float div = cant/10;
        game.gamePrice = game.gamePrice - game.gamePrice * 1 + div;
    }
};

class Add : public Visitor{
public:
    void visit (Strategy game, int cant){
        float div = cant/10;
        game.gamePrice = game.gamePrice * (1 + div);
    }
    void visit (Adventure game, int cant){
        float div = cant/10;
        game.gamePrice = game.gamePrice * (1 + div);
    }
    void visit (Learning game, int cant){
        float div = cant/10;
        game.gamePrice = game.gamePrice * (1 + div);
    }
};
template<class Temp>
class Collection{
    public: 
        Temp* array; 
        int max; 
        int num;

        friend class Iterator<Temp>; 
        Collection(){
            max = 15;
            num = 0; 
            array = new Temp[max]; 
        }
        void add(Temp game){
            if (num <= max){
                game->gameId = num;
                array[num++] = game;

            }
            else{
                cout << "Lo sentimos, no hay suficiente espacio en el Inventory" << endl;
            }
        }
        Temp indice (int position){
            if (0 > position){
                cout << "Índice fuera de lugar" << endl; 
                throw "out of range"; 
            }
        }
        int getNumElements(){
            return num;
        }
        void print(){
            for (int i = 0; i < num; i++){
                cout  << "No. Serie: " << array[i]->gameId << endl;
                cout << "Nombre: " << array[i]->gameName << endl; 
                cout << "Compañia: " << array[i]->gameCompany << endl; 
                cout << "Consola: " << array[i]->gamePlatform << endl;
                cout << "Clasificación: " << array[i]->gameClasification << endl;
                cout << "Precio: " << array[i]->gamePrice << endl;
            }
        }
        void searchN(string n){
            for(int i = 0; i < num; i++){
                if (n == array[i]->gameName){
                    cout << "No. Serie: " << array[i]->gameId << endl;
                    cout << "Nombre: "<< array[i]->gameName << endl;
                    cout << "Compañia: " << array[i]->gameCompany << endl;
                    cout << "Consola: " << array[i]->gamePlatform << endl;
                    cout << "Clasificación:" << array[i]->gameClasification << endl;
                    cout << "Precio: " << array[i]->gamePrice << endl;
                }
                else{
                    cout << "Lo sentimos, no se encontró el juego" << endl;
                }
            }
        }
        void searchI(int n){
            for(int i = 0; i < num; i++){
                if (n == array[i]->gameId){
                    cout << "No. gameId: " << array[i]->gameId << endl;
                    cout << "Nombre: "<< array[i]->gameName << endl;
                    cout << "Compañia: " << array[i]->gameCompany << endl;
                    cout << "Consola: " << array[i]->gamePlatform << endl;
                    cout << "Clasificación:" << array[i]->gameClasification << endl;
                    cout << "gamePrice: " << array[i]->gamePrice << endl;
                }
                else{
                    cout << "Lo sentimos, no se encontró el juego" << endl;
                }
            }
        }
        void deleteN(string n){
            for(int i = 0; i < num; i++){
                if (n == array[i]->gameName){
                    array[i] = NULL;
                    num--;
                }
            }
        }
        void deleteI(int n){
            for(int i = 0; i < num; i++){
                if (n == array[i]->gameId){
                    array[i] = NULL;
                    num--;
                }
            }
        }
        void accept(Visitor* visitor, float a){
            for(int i = 0; i < num; i++){
                array[i]->accept(visitor, a);
            }
        }
        void changePrice(string option, float a){
            if (option == "aumentar"){
                Add* c = new Add();
                accept(c, a);
            }
            else{
                Discount* c = new Discount();
                accept(c, a);
            }
        }

        Iterator<Temp>* getIterator();
};

template<class Temp>
class Iterator{
    protected:
        Collection<Temp> collection;
        int cont = 0;
    public:
        Iterator(const Collection<Temp>& collection) : collection(collection){}
        virtual Temp next(){
            Temp a  = collection.indice(cont);
            cont++;
            return a; 
        }
        virtual bool hasNext(){
            if (cont < collection.num){
                return true; 
            }
            else{
                return false; 
            }
        }
};

template<class Temp>

Iterator<Temp>* Collection<Temp>:: getIterator(){
    return new Iterator<Temp>(*this);
} 


class Inventory{
    protected: 
        int i = 1;
        int t = 0; 
    public: 
        Inventory(){}
        Collection<Videogame*> inventory; 
        Iterator<Videogame*> *items; 

        void crearjuego(){
            Inventory* inv = new Inventory(); 
        }
        void addGame (Videogame* v){
            items = inventory.getIterator();
            inventory.add(v);
            i++;
        }
        int getElements(){
            return inventory.getNumElements();
        }
        void imprimir(){
            inventory.print();
        }
        void buscarN(string n){
            inventory.searchN(n);
        }
        void buscarI(int n){
            inventory.searchI(n);
        }
        void borrarN(string n){
            inventory.deleteN(n);
        }
        void borrarI(int n){
            inventory.deleteI(n);
        }
        void priceChange(string s, float a){
            inventory.changePrice(s,a);
        }

   
};


class Command{
    public:
        virtual void execute() = 0;
};


class Receiver {
    public:
        void undo() {
            cout << "undo" << endl;
        }
        void redo() {
            cout << "redo" << endl;
        }
}; 

class undoCommand : public Command {
    public:
        undoCommand(Receiver *Receiver) : w(Receiver) {}
        void execute(){
            w->redo();
        }
    private:
        Receiver *w;
};
 
class redoCommand : public Command 
{
public:
        redoCommand(Receiver *Receiver) : w(Receiver) {}
	void execute(){
		w->undo();
	}
private:
	Receiver *w;
};

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


Inventory* n = new Inventory();

void Strategy::accept(Visitor* visitor, float a){
    visitor->visit(*this, a);
}
void Adventure::accept(Visitor* visitor, float a){
    visitor->visit(*this, a);
}
void Learning::accept(Visitor* visitor, float a){
    visitor->visit(*this, a);
}




void menuOptions(int a);

void menu(){

    cout << "///////////////// MENÚ INVENTARIO \\\\\\\\\\\\\\\\"  << endl;
    cout << "Nota: Este menú es case sensitive \n"  << endl;
    cout << "1.Agregar un nuevo juego" <<endl;
    cout <<"2. Borrar un juego" <<endl;
    cout <<"3. Revisar el inventario" <<endl;
    cout <<"4.Buscar un juego" << endl;
    cout <<"5.Modificar precio de unjuego" << endl;
    cout << "6. Salir" <<endl;

    int ans;
    cin >> ans;

    menuOptions(ans);
    
}

void menuOptions(int ans){

    switch(ans){
        case 1:{
            cout << "Ingrese la letra del tipo de juego que desea agregar: " << endl;
            cout <<"A: Estrategia" << endl;
            cout <<"B: Aventura" << endl;
            cout <<"C: Aprendizaje" << endl;

            char ans2; 
            cin >> ans2;
            switch(ans2){
                
                case 'A':{
                    cout << "Escoga una opción" <<endl;
                    cout << "L: Lucha" << endl;
                    cout << "A:  Arcade" << endl;
                    char ans3;
                    cin >> ans3;
                    switch(ans3){
                        case 'L':{
                            cout << "Inserte el precio" << endl;
                            float p; 
                            cin >> p;
                            Fight* g1 = new Fight(); 
                            g1->setPrice(p);
                            n->addGame(g1);
                            menu();
                            break;
                        }
                        case 'A':
                            cout << "Inserte el precio" << endl;
                            float p2; 
                            cin >> p2;
                            Arcade* g1 = new Arcade(); 
                            g1->setPrice(p2);
                            n->addGame(g1);
                            menu();
                            break;
                    }
                    break;
                }
                case 'B':{
                    cout << "Escoga una opción" <<endl;
                    cout << "P: Plataforma" << endl;
                    cout << "G: Gráfica" << endl;
                    char ans4;
                    cin >> ans4;
                    switch(ans4){
                        case 'P':{
                            cout << "Inserte el nombre" << endl;
                            string a3; 
                            cin >> a3;
                            cout << "Inserte el precio" << endl;
                            float p3; 
                            cin >> p3;
                            Platform* g1 = new Platform();
                            g1->setPrice(p3);
                            n->addGame(g1);
                            menu();
                            break;
                        }
                        case 'G':{
                            cout << "Inserte el nombre" << endl;
                            float a4; 
                            cin >> a4;
                            cout << "Inserte el precio" << endl;
                            float p4; 
                            cin >> p4;
                            Graphic* g1 = new Graphic();
                            g1->setPrice(p4);
                            n->addGame(g1);
                            menu();
                            break;
                        }
                    }
                }
                case 'C':{
                    cout << "Escoga una opción" <<endl;
                    cout << "I:Idiomas" << endl;
                    cout << "M: Musica" << endl;
                    char c1;
                    cin >> c1;
                    switch(c1){
                        case 'I':{
                            cout << "Inserte el precio" << endl;
                            float p5; 
                            cin >> p5;
                            Languages* g1 = new Languages();
                            g1->setPrice(p5);
                            n->addGame(g1);
                            menu();
                            break;
                        }
                        case 'M':{
                            cout << "Inserte el precio" << endl;
                            float p6; 
                            cin >> p6;
                            Music* g1 = new Music();
                            g1->setPrice(p6);
                            n->addGame(g1);
                            menu();
                            break;
                        }
                    }
                    break;
                }
            }
        
        case 2:
            cout << "Escoga una opción" <<endl;
            cout << "S:Borrar por numero de serie" << endl;
            cout << "N: Borrar por nombre" << endl;
            char k;
            cin >> k;
            switch(k){
                case 'S':{
                    cout << "Inserte el numero de serie" << endl;
                    int busq; 
                    cin >> busq;
                    n->borrarI(busq);
                    menu();
                    break;
                }
                case 'N':{
                    cout << "Inserte el nombre" << endl;
                    string busqn;
                    cin >> busqn;
                    n->borrarN(busqn);
                    menu();
                    break;
                }
            }
            break;
        case 3:
            cout << "Inventario: "<< n->getElements() << endl;
            n->imprimir();
            menu();
            break;
            
        case 4:
            cout << "Escoga una opción" <<endl;
            cout << "S:Buscar por numero de serie" << endl;
            cout << "N: Buscarr por nombre" << endl;
            char j;
            cin >> j;
            switch(j){
                case 'S':{
                    cout << "Inserte el numero de serie" << endl;
                    int busq; 
                    cin >> busq;
                    n->buscarI(busq);
                    menu();
                    break;
                }
                case 'N':{
                    cout << "Inserte el nombre" << endl;
                    string busqn;
                    cin >> busqn;
                    n->buscarN(busqn);
                    menu();
                    break;
                }
            }
            break;
        case 5:
            break;
        case 6:
            break;
        }
    }  
}

int main(){

    menu();
    return 0;
}