#include <iostream>

using namespace std;

enum sort_type {BUBBLE, QUICK, INSERTION};

class Sorter{
public:
    void _sort(int tab[], sort_type type){
    Strategy* strategy;

    switch(type){
    case BUBBLE:
        strategy = new BubbleSortStrategy();
        break;

    case QUICK:
        strategy = new QuickSortStrategy();
        break;

    case INSERTION:
        strategy = new InsertionSortStrategy();
        break;
    }
    strategy->_sort(tab);
}

class Strategy{
public:
    virtual void _sort(int tab[]){}
};


class BubbleSortStrategy : public Strategy{
public:

    void _sort(int tab[]){
        cout<<"BubbleSort"<<endl;
    }

};

class QuickSortStrategy : public Strategy{
public:

    void _sort(int tab[]){

        cout<<"QuickSort"<<endl;
    }
};

class InsertionSortStrategy : public Strategy{
public:

    void _sort(int tab[]){
        cout<<"InsertionSort"<<endl;
    }
};


};

int main(){

    int input[] = {2,3,1};
    Sorter sorter;
    sorter._sort(input,QUICK);

    return 0;
}
