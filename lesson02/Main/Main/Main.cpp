#include <iostream>
using namespace std;

class Animal {

public :
	Animal(int a) {
	}

	virtual void eat() {
		cout << "animal eat" << endl;
	}

	void sleep() {
		cout << "animal sleep" << endl;
	}

	void breathe() {
		cout << "animal breathe" << endl;
	}
};

class Fish : public Animal {
public:
	Fish() : Animal(0), a(1) {
	}

	virtual void eat() {
		cout << "fish eat" << endl;
	}

	void sleep() {
		cout << "fish sleep" << endl;
	}

private:
	const int a;
};

void fn(Animal *pAnimal) {
	pAnimal->eat();
	pAnimal->sleep();
}

void main() {
	Fish fh;
	fh.eat();
	fh.sleep();

	Animal *pAn;
	pAn = &fh;
	fn(pAn);
}