#include <string>
#include <list>
#include <iostream>
using namespace std;

class DocPart{
    public:
        string text;
        virtual string toHTML() = 0;
};
class Text : public DocPart {
    public:
        string toHTML(){
            return text;
        }
};
class Bold : public DocPart {
   public:
        string toHTML(){
            return "<b>" +text + "</b>";
        }
};
class HyperLink : public DocPart {
    public:
        string URL;
        string toHTML(){
            return "<a href='" +URL +"'>" + text +  "</a>";
        }
};
class Document {
    public:
        list<DocPart*> docpart;
        string toHTML(){
            string out = "";
            for (DocPart* d : docpart){
                out += d->toHTML();
            }
            return out;
        }
};

int main(){
    Document d;
    Text t1;
    t1.text = "Hola";
    Bold t2;
    t2.text =  "que tranza";
    HyperLink t3;
    t3.text= "krnal";
    t3.URL="www.bambiesunvenado.com";
    d.docpart.push_back(&t1);
    d.docpart.push_back(&t2);
    d.docpart.push_back(&t3);

    cout << d.toHTML();
}