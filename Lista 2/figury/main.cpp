#include <iostream>
#include <math.h>
#include "figury.h"
using namespace std;

int main()
{
    /*Punkt punkcik = Punkt(1, 1);

	cout << "punkt " << punkcik.x <<" "<< punkcik.y << endl;
	Punkt x = Punkt(3, 1);
	cout<<"obracam wzgledem "<<x.x<<" "<<x.y<<"o pi/2"<<endl;
	punkcik.obroc(x, M_PI / 2);
	cout << "punkt " << punkcik.x <<" "<< punkcik.y << endl;
	punkcik.przesun(1, 2);
	cout << "punkt " << punkcik.x <<" "<< punkcik.y << endl;
	Odcinek odc = Odcinek(punkcik, x);
    odc.wydrukuj();
    cout<<"przesuwam o 2, 5"<<endl;
    odc.przesun(2, 5);
    odc.wydrukuj();
    cout<<"obracam wzgledem "<<x.x<<" "<<x.y<<"o pi*2"<<endl;
    odc.obroc(x, M_PI*2);

    odc.wydrukuj();

    Odcinek nowyodcinek = Odcinek(Punkt(0,0), Punkt(0, 5));
    nowyodcinek.wydrukuj();
    cout<<"sprawdzam czy 0,2 nalezy do odcinka"<<endl;
    cout<<nowyodcinek.czyLezy(Punkt(0, 2))<<endl;
    nowyodcinek.wydrukuj();
    cout<<"srodek "<<nowyodcinek.srodek().x<<" "<<nowyodcinek.srodek().y<<endl;
    cout<<endl;
    cout<<"trojkaty"<<endl;








    cout<<endl;

    Punkt p1(-3,-3);
    Punkt p2(0,-3);
    cout<<"odleglosc "<<dystans(p1, p2)<<endl;
    Punkt p3(-2, -1);
    Trojkat t(p1, p2, p3);
    t.obroc(Punkt(0,0), M_PI*2);
    t.wydrukuj();
    cout<<t.czyLezy(Punkt(-2, -1.5))<<endl;
    Trojkat t1(Punkt(-2,-3), Punkt(-1,-3),Punkt(-2, -2));
    cout<<endl;
    cout<<"przesuwam o 2,2"<<endl;
    t.przesun(2,2);
    t.wydrukuj();

    cout<<"obracam o pi/2 wzgledem 0,0"<<endl;
    t.obroc(Punkt(0,0), M_PI/2);
    t.wydrukuj();

    cout<<"obwod "<<t.obwod()<< endl;
    cout<<"pole "<<t.pole()<< endl;
    cout<<"srodek "<<t.srodek().x<<" "<<t.srodek().y<<endl;
    cout<<"czy punkt 5,5 lezy w t: "<<t.czyLezy(Punkt(-5,5))<< endl;

*/
cout<<"czy rownolegle odcinek 0,0  5,5 i odcinek -1,-1  4,4: "<<czyRownolegle(Odcinek(Punkt(0,0), Punkt(5,5)),Odcinek(Punkt(-1,-1), Punkt(4,4)))<<endl;

    cout<<endl;
    cout<<endl;
    Punkt pkt1(-10, 6);
    pkt1.obroc(Punkt(1,1), M_PI*2);
    cout<<pkt1.x<<" "<<pkt1.y<<endl;
    pkt1.przesun(1,1);
    pkt1.przesun(-1,-1);
     cout<<pkt1.x<<" "<<pkt1.y<<endl;

    Punkt pkt2(-8,10);

    Odcinek odcinek(pkt1, pkt2);
    cout<<odcinek.dlugosc()<<endl;
    cout<<odcinek.czyLezy(Punkt(-9,20))<<endl;

    Punkt pkt3(-5, 6);

    Trojkat tri(pkt1, pkt2, pkt3);
    cout<<tri.czyLezy(Punkt(-8, 9))<<endl;
    cout<<tri.obwod()<<endl;
    cout<<tri.pole()<<endl;
    return 0;
}
