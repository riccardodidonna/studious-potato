//
//  area_verde.cpp
//  
//
//  Created by Riccardo Di Donna on 24/10/2019.
//

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

struct punto{
    int x;
    int y;
};

struct rettangolo{
    punto a;
    punto c;
};

void Pause(){
    cout << "Premi il tasto invio per riprovare." << endl;
    cin.ignore();
    cin.get();
}

void ClearScreen(){
    cout << string( 100, '\n' );
}

bool Check (int area, int base, int altezza){
    bool var=true;
        if (area < 0){
        cout << "Area < 0 -> i due rettangoli non si intersecano, riprova" << endl;
        Pause();
        ClearScreen();
    }
    else if (base == 0){
        cout << "Base = 0 -> errore nell'inserimento dei rettangoli, riprova" << endl;
        Pause();
        ClearScreen();
    }
    else if (altezza == 0){
        cout << "Altezza = 0 -> errore nell'inserimento dei rettangoli, riprova" << endl;
        Pause();
        ClearScreen();
    }
    else
        var = false;
    return var;
}


int main(){
    rettangolo uno, due, inters;
    int base, altezza, area;
    do{
        cout << "Inserisci angolo A (x,y) del rettangolo n.1: "<< endl;
        cin >> uno.a.x >> uno.a.y;
        cout << "Inserisci angolo C (xy): del rettangolo n.1: " << endl;
        cin >> uno.c.x >> uno.c.y;
        cout << "Inserisci angolo A (x,y): del rettangolo n.2: " << endl;
        cin >> due.a.x >> due.a.y;
        cout << "Inserisci angolo C (x,y): del rettangolo n.2: " << endl;
        cin >> due.c.x >> due.c.y;
        
        inters.a.x=max(uno.a.x, due.a.x);
        inters.a.y=max(uno.a.y, due.a.y);
        inters.c.x=min(uno.c.x, due.c.x);
        inters.c.y=min(uno.c.y, due.c.y);
        
        base = inters.c.x - inters.a.x;
        altezza = inters.c.y - inters.a.y;
        area = base * altezza;

        }while(Check(base, area, altezza)==true);

        cout << "Punto A intersezione (x,y): " << inters.a.x << " , " << inters.a.y << endl;
        cout << "Punto C intersezione (x,y): " << inters.c.x << " , " << inters.c.y << endl;
        cout << "Il rettangolo di intersezione ha base = " << base << " e altezza = " << altezza << " quindi area = " << base << " * " << altezza << " = " << area << endl;

        return 0;
}
