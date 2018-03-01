#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>


using namespace std;

class SMS {
    public:
        string telefono;
        string texto;

        SMS(string tel, string txt){
            telefono = tel; 
            texto = txt;
        }
};

class Email {
    public:
        string from;
        string to; 
        string subject;
        string body;

        Email(string f, string t, string s, string b){
            from = f;
            to = t;
            subject = s; 
            body = b; 
        }
};

class Llamada {
    public:
        string telefono;
        string nombre;
        string mensaje;

        Llamada(string tel, string nom, string msj){
            telefono = tel; 
            nombre = nom; 
            mensaje = msj; 
        }
};

class Command{
    public:
        virtual void manda()=0;
};

class receiver {
    public: 
        void mandaSMS(){
            cout << "Se envió un SMS" << endl;
        }
        void mandaEmail(){
            cout << "Se envió un Email" << endl;
        }
        void llamarCliente(){
            cout << "Se envió una Llamada" << endl;
        }
};

class Cliente : public receiver{

    public:
        string ID;
        string nombre;
        string apellido;
        string formaDeContacto;
        string mail;
        string tel; 
        string calle; 
        string numero; 
        string colonia;
        
        static Cliente* instancia;

        Cliente() {}
        Cliente(string i, string nom, string ap, string FdC, string m, string t, string c, string num, string col){
            ID = i;
            nombre = nom; 
            apellido = ap; 
            formaDeContacto = FdC;
            mail = m; 
            tel = t; 
            calle = c; 
            numero = num; 
            colonia = col;
        }

        static Cliente* getInstancia(){
            if(instancia == 0){
                instancia = new Cliente();
            }
            return instancia;
        }
};

Cliente* Cliente::instancia = 0; 

class mandaSMS : public Command{
    private: 
        Cliente *pruebaC;
    public: 
        mandaSMS(Cliente *Cliente) : pruebaC(Cliente){}
        void manda(){
            pruebaC->mandaSMS();
        }
    
};

class mandaEmail : public Command {
    private: 
        Cliente *pruebaC;
    public:
        mandaEmail(Cliente *Cliente) : pruebaC(Cliente){}
        void manda(){
            pruebaC->mandaEmail();
        }
   
};

class llamarCliente : public Command{
    private: 
        Cliente *pruebaC;
    public: 
        llamarCliente(Cliente *Cliente) : pruebaC(Cliente){}
    
        void manda(){
            pruebaC->llamarCliente();
        }
    
};

class Invoker {
    private:
        Command *pa;
    public: 
        void opcion(Command *a){
            pa = a;
        }
        void commandP(){
            pa->manda();
        }
 
};

vector<Cliente> Clientes;

void leerArchivo(string archivo){
    ifstream arch;
    arch.open(archivo);

    while (arch){
        string linea; 
        string ID;
        getline(arch, ID, ',');
        string nombre;
        getline(arch, nombre, ',');
        string apellido;
        getline(arch, apellido, ',');
        string formaDeContacto;
        getline(arch, formaDeContacto, ',');
        string mail;
        getline(arch, mail, ',');
        string tel;
        getline(arch, tel, ',');
        string calle;
        getline(arch, calle, ',');
        string numero;
        getline(arch, numero, ',');
        string colonia;
        getline(arch, colonia);

        Cliente xs(ID,nombre,apellido,formaDeContacto,mail,tel,calle,numero,colonia);
        Clientes.push_back(xs);
    }
}



int main(){

    leerArchivo("clientes.txt");

    Cliente *prueba = new Cliente;

    mandaSMS *sms = new mandaSMS(prueba);
    mandaEmail *mail = new mandaEmail(prueba);
    llamarCliente *llamada = new llamarCliente(prueba);
 
    Invoker *a = new Invoker;

    for (int i = 0 ; i < Clientes.size()-1 ; i++){
        if (Clientes[i].formaDeContacto == "sms"){
            a->opcion(sms);
            a->commandP();
        }
        else if(Clientes[i].formaDeContacto == "mail"){
            a->opcion(mail);
            a->commandP();
        }
        else{
            a->opcion(llamada);
            a->commandP();
        }
    }
    return 0; 
}