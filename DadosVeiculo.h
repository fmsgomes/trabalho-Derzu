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

    string getMarca()const{return marca;}
    string getModelo()const{return modelo;}
    string getPlaca()const{return placa;}
    string getCategoria()const{return categoria;}
    float getFipe()const{return fipe;}

    void lerDadosVeiculo(){
        cout << "Insira os dados seguintes para cadastrar o veículo:\n";
        cout << "Marca do veículo: ";
        cin.ignore();
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
        return;
    }

    void ImprimirVeiculo()const{
        cout << "Marca: " << getMarca() <<endl;
        cout << "Modelo: " << getModelo() <<endl;
        cout << "Placa: " << getPlaca() <<endl;
        cout << "Categoria: " << getCategoria() <<endl;
        cout << "Fipe: R$ " << getFipe() <<endl;
    }

};