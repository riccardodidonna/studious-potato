#include <iostream>

using namespace std;

int NumGiorniMese(int mese, int anno)   //trova numero di giorni del mese x nell'anno y
{
    int ng;
    if(mese==0)
        mese=12;
    if (mese==1||mese==3||mese==5||mese==7||mese==8||mese==10||mese==12) 
        ng=31;
    else if(mese==2 && (anno%400==0||(anno%4==0&&!(anno%100==0)))) //febbraio bisestile
        ng=29;
    else if(mese==2)
        ng=28; //febbraio normale
    else
        ng=30;
    return ng;
}

int AnniDiff (int aa, int an, int ma, int mn, int ga, int gn) //fa la differenza degli anni tenendo conto se è passato il giorno del compleanno o no
{
    int adiff;
    adiff=aa-an;
    if(ma<mn||(ma==mn&&ga<gn)) 
       adiff--;
    return adiff;
}

int main()
{
    int ga,ma,aa,gn,mn,an,mdiff,gdiff;  //ga,ma,aa -> giorno mese anno ATTUALI --- gn,mn,an -> giorno mese anno NASCITA
    cout <<"Inserisci giorno, mese e anno attuale (GG ↵ MM ↵ AA): "<<endl;
    cin>>ga>>ma>>aa;
    cout <<"Inserisci giorno, mese e anno di nascita (GG ↵ MM ↵ AA): "<<endl;
    cin>>gn>>mn>>an;
    if(gn>NumGiorniMese(mn,an)||ga>NumGiorniMese(ma,aa)||an>aa||gn<1||ga<1||mn<1||ma<1||mn>12||ma>12)
        cout <<"ERROR\n";
    else if(aa-an>100)
        cout << "Eta' superiore a 100 anni ---> "<< AnniDiff(aa,an,ma,mn,ga,gn)<<endl;
    else if (AnniDiff(aa,an,ma,mn,ga,gn)<1)
    {
        if(ma<=mn)
            mdiff=12-mn+ma;
        else
            mdiff=ma-mn;
        if(ga>=gn)
            gdiff=ga-gn;
        else
        {
           mdiff--;
           gdiff=NumGiorniMese(ma-1,aa)-gn+ga;
        }
        cout <<"Eta' bambino < 1 anno ---> "<<mdiff<<" mesi e "<<gdiff<<" giorni\n";
    }
    else
        cout<<AnniDiff(aa,an,ma,mn,ga,gn)<<" anni\n";
    return 0;
}