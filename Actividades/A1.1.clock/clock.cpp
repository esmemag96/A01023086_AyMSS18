#include <iostream>
#include <ctime>
 
using namespace std;

class Clock {
public:
    static Clock * getInstance(){
        if (instance == 0){
            instance = new Clock;
        }
        return instance;
    }
    void getTime(){
        time_t t = time(0); 
        cout << t << endl;
    }
    static Clock * deleteInstance(){
        if(instance != NULL){
            delete instance;
            instance = NULL;
        }
        return instance;
    }
	

private:
    static Clock* instance;
    Clock(){}
}; 

Clock* Clock::instance = 0; 

int main() {
	Clock* instance1 =Clock::getInstance();
	instance1->getTime();
	instance1->deleteInstance();
	return 0;
} 