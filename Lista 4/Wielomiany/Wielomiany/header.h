#include <iostream>


class wielomian
{
private:
	int stopien;
	double *wspolczynniki;

public:
	wielomian(int st = 0, double wsp = 1.0);
	wielomian(int st, const double wsp[]);
	wielomian(std::initializer_list<double> wsp);
	wielomian(const wielomian &w);
	wielomian(wielomian &&w);
	wielomian& operator=(const wielomian &w);
	wielomian& operator=(wielomian &&w);
	~wielomian();

	wielomian& operator+=(const wielomian &v);
	wielomian& operator-=(const wielomian &v);
	wielomian& operator*=(const wielomian &v);
	wielomian& operator*=(double c);
	double operator()(double x) const; // obliczenie wartości wielomianu w x-sie
	double operator[](int i) const; // odczytanie i-tego współczynnika

	int get_stopien();

	friend std::istream& operator>>(std::istream &we, wielomian &w);
	friend std::ostream& operator<<(std::ostream &wy, const wielomian &w);
	friend wielomian operator+(const wielomian &u, const wielomian &v);
	friend wielomian operator-(const wielomian &u, const wielomian &v);
	friend wielomian operator*(const wielomian &u, const wielomian &v);
	friend wielomian operator*(const wielomian &u, double c);
	friend double* policz_suma(const wielomian &u, const wielomian &v, int st);
	friend double* policz_roznica(const wielomian &u, const wielomian &v, int st);
	friend double* policz_iloczyn(const wielomian &u, const wielomian &v, int st);
};