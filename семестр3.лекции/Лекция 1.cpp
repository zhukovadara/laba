#include <string>
#include <iostream>
// класс - тип переменных
using namespace std;

class Spravka {
	int num;
	string about;
	string data;

	// конструктор по умолч (назван совпалает сименем класса)
	//Spravka(); num(0), about(""), data("") {}
	//Spravka(int n, string st);num(n), about(st){}
	//Spravka(int n); num(n),about(""){}
	// деструктор
	// пользовательские методы
	void print() { //метод Spravka *this
		cout << num << about << data << endl;
	}
};
// вызов конструктора происходит как только мы создаём объект класса
Spravka x(3);
x.about = "";
x.print()
Spravka* s = new Spravka();
//s->about = "";
//s->print();
//delete s; //десттруктор
// абстракция
// инкапсуляция (сокрытие данных)

