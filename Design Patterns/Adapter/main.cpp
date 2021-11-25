
#include <iostream>
#include <string>
#include <boost/algorithm/string.hpp>

using namespace std;

class Target{
public:
    virtual string Request() const{
        return "poprawny tekst";
        }
};

class Odd_Data{
public:
    string SpecificRequest() const{
    return "TSKET YNLIBYTAPMOKEIN";
    }
};

class Adapter :public Target, public Odd_Data{
public:

    string Request() const override{
        string to_adapt = SpecificRequest();
        //Reversing//
        reverse(to_adapt.begin(),to_adapt.end());
        //Lowering Case//
        boost::algorithm::to_lower(to_adapt); 
    return to_adapt;
    }
};

  void ClientCode(const Target* target){
    cout << target->Request() << endl;
  }


int main()
{
    Target* target = new Target;
    ClientCode(target);

    Odd_Data* odd_data = new Odd_Data;
    cout << odd_data->SpecificRequest() << endl;
    
    Adapter* adapter = new Adapter;
    ClientCode(adapter);

  delete adapter;
  delete odd_data;
  delete target;

    return 0;
}
