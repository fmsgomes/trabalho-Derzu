#pragma once
#include <string>
#include <iostream>
using namespace std;

class DadosVeiculo{
    private:
    string marca; //  Toyota
    string modelo; // corolla
    string placa; //xxx-0x00
    string categoria; // Carro de passeio, trabalho...
    float fipe; // Valor de mercado do carro.

    public:

    DadosVeiculo(string m, string mo, string p, string c, float f) : marca(m), modelo(mo), placa(p), 
    categoria(c), fipe(f){}
    
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

    void lerDadosVeiculo(){
        cout << "Insira os dados seguintes para cadastrar o veículo:\n";
        cout << "Marca do veículo: ";
        getline(cin, marca);
        cout << "\nModelo do veículo: ";
        getline(cin, modelo);
        cout << "\nPlaca do veículo: ";
        getline(cin, placa);
        cout << "\nCategoria do veículo: ";
        getline(cin, categoria);
        cout << "\nFipe do Carro: ";
        cin >> fipe;
        cin.ignore();
        while(fipe < 0){
            cout << "\nValor da fipe inválido. Digite um valor positivo: ";
            cin >> fipe;
            cin.ignore();
        }
    }

    void ImprimirVeiculo(){
        cout << "Marca: " << getMarca() <<endl;
        cout << "Modelo: " << getModelo() <<endl;
        cout << "Placa: " << getPlaca() <<endl;
        cout << "Categoria: " << getCategoria() <<endl;
        cout << "Fipe: R$ " << getFipe() <<endl;
    }

};