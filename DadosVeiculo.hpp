#pragma once
#include <string>
using namespace std;

class DadosVeiculo{
    private:
    string marca; //  Toyota
    string modelo; // corolla
    string placa; //xxx-0x00
    string categoria; // Carro de passeio, trabalho...
    float fipe; // Valor de mercado do carro.

    public:
    
    void setMarca(string m){marca = m;}
    void setModelo(string md){modelo = md;}
    void setPlaca(string p){placa = p;}
    void setCategoria(string c){categoria = c;}
    void setFipe(float f){fipe = f;}

    string getMarca(){return marca;}
    string getModelo(){return modelo;}
    string getPlaca(){return placa;}
    string getCategoria(){return categoria;}
    float getFipe(){return fipe;}

    void ImprimirVeiculo(){
        cout << "Marca: " << getMarca() <<endl;
        cout << "Modelo: " << getModelo() <<endl;
        cout << "Placa: " << getPlaca() <<endl;
        cout << "Categoria: " << getCategoria() <<endl;
        cout << "Fipe: " << getFipe() <<endl;
    }

};