#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class Data {
private:
    int dia, mes, ano;

public:

    Data(){mes = dia = ano = 0;}
    Data(int d, int m, int a){
        dia = d; mes = m; ano = a;
    }
    int getdia()const{return dia;}
    int getmes()const{return mes;}
    int getano()const{return ano;}
    int getDaysMonth(int m){
        switch (m) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
            case 4: case 6: case 9: case 11: return 30;
            case 2: return 28;
            default: return 0;
        }
    }
    void lerData(){
        cout << "Dia: ";
        cin >> dia;
        while (dia < 1 || dia > 31) {
            cout << "Dia inválido! Digite um valor entre 1 e 31: ";
            cin >> dia;
        }

        cout << "\nMês: ";
        cin >> mes;
        while (mes < 1 || mes > 12) {
            cout << "Mês inválido! Digite um valor entre 1 e 12: ";
            cin >> mes;
        }

        cout << "\nAno: ";
        cin >> ano;
        while (ano < 0) {
            cout << "Ano inválido! Digite um valor positivo: ";
            cin >> ano;
        }
    }



    void setdia(int d){

        while (dia > getDaysMonth(mes)) {
            dia -= getDaysMonth(mes);
            mes++;
        }
    }

    void setmes(int m){mes = m;}
    void setano(int a){ano = a;}

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
    void imprimirData()const {
            cout << setw(2) << setfill('0') << dia << "/"
                      << setw(2) << setfill('0') << mes << "/"
                      << setw(4) << setfill('0') << ano << endl;
        }
};