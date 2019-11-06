#include <iostream>
using namespace std;

int main(){
    char a,b,c;
    cout<< "Inserire 's' o 'S' per sx, 'd' o 'D' per dx"<<endl;
    cin >> a >> b >> c;
    if (a=='s'||a=='S'){   //guardo prima colonna se è = s
        if(b=='s'||b=='S'){ //seconda colonna se è = s
            if(c=='s'||c=='S'){ //terza colonna se è = s
                cout << "Entrata A1"<<endl; //sss
            }
            else{ //terza colonna = d
                cout << "Entrata A2" << endl; //ssd
            }
        }
        else{ //seconda colonna = d 
            if(c=='s'||c=='S'){ //terza colonna = s
                cout << "Entrata A3"<<endl;  //sds
            }
            else{  //terza colonna = d
                cout << "Entrata A4" << endl; //sdd
            }
        }
    }
    else{      // prima colonna = d
         if(b=='s'||b=='S'){ // seconda colonna = s
            if(c=='s'||c=='S'){ //terza colonna = s
                cout << "Entrata A5"<<endl; //dss
            }
            else{ //terza colonna = d
                cout << "Entrata A6" << endl; //dsd
            }
        }
        else{ //seconda colonna = d 
            if(c=='s'||c=='S'){ // terza colonna = s
                cout << "Entrata A7"<<endl; //dds
            }
            else{ // terza colonna = d
                cout << "Entrata A8 " << endl; //ddd
            }
        }
    }
}