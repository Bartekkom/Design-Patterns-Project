#include <iostream>

using namespace std;

class Singleton{
public:
  void hello(){
    cout<<"Hello World!"<<endl;
  }

  static Singleton* getInstance(){
    if(_instance == 0){
      _instance = new Singleton();
    }
    return _instance;
  }

private:
  Singleton(){}
  static Singleton* _instance;

  int x = 10;
};

Singleton* Singleton::_instance = 0;


 int main(){
   Singleton::getInstance()->hello();

}