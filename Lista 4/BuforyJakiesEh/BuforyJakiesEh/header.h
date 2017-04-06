#pragma once
using namespace std;
int tab[1000];

class Lista {
	protected:
	class Node {
		Node();
		Node* prev;
		double val;
		Node* next;
		void wstaw(double, int);
		void usun(int);
		int rozmiar();
		Node& operator[](int);
		void* operator new(size_t);
		void operator delete(void* wsk);

	};
public:
	Node* first;
	Node* last;
};
class kolejka : Lista {

};