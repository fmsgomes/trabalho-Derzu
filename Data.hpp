#pragma once
#include <iostream>
using namespace std;

class Data{
    private: 
    int dia, mes, ano;

    public:

    Data(){mes = dia = ano = 0;}
    Data(int d, int m, int a){
        dia = d; mes = m; ano = a;
        if(mes > 12){ mes = 1;
        cout <<  "Atributo mês Inválido\n";}
        else if(dia > getDaysMonth(mes)){
        dia = 1;cout << "Atributo dia Inválido\n"; }
        
    }

    int getdia(){return dia;}
    int getmes(){return mes;}
    int getano(){return ano;}
    int getDaysMonth(int m){
        switch (m) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
    case 4: case 6: case 9: case 11: return 30;
    case 2: return 28;
    default: return 0;
}

    }

    void setdia(int d){

        while (dia > getDaysMonth(mes)) {
            dia -= getDaysMonth(mes);
            mes++;

            if (mes > 12) {
                mes = 1;
                ano++;
            }
        }
        }
    
    void setmes(int m){if(m > 12){mes =1;}else{
        mes = m;}
        }    
    void setano(int a){
        ano = a;}
    
    void avancardia(){dia++;
    while (dia > getDaysMonth(mes)) {
            dia -= getDaysMonth(mes);
            mes++;

            if (mes > 12) {
                mes = 1;
                ano++;
            }
        }
    }
    void imprimirData(){
        cout << getdia() << "/" << getmes() << "/" << getano();
    }

};