#include <iostream>

using namespace std;

template <int n>
class Repeat : public Repeat<n-1>{
    public:
        Repeat() {cout << n << " ";}

};

template <>
class Repeat<0>
{
    public:
        Repeat() {cout << "0";}
};  

int main() {
    Repeat<1000> a;
}
