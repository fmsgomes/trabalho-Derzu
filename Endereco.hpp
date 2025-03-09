#pragma once
#include <iostream>
#include <string>
using namespace std;

class Endereco{
    private:
    string rua;
    int num;
    string bairro;
    string cidade;
    string estado;
    string CEP;
    string complemento;

    public:
    Endereco() : rua(""), num(0), bairro(""), cidade(""), estado(""), CEP(""), complemento("") {}
    Endereco(string r, int n, string b, string c, string e, string cep, string comp) : rua(r), num(n), bairro(b), cidade(c), estado(e), CEP(cep), complemento(comp){}

    string getRua()const{return rua;}
    int getNum()const{return num;}
    string getBairro()const{return bairro;}
    string getCidade()const{return cidade;}
    string getEstado()const{return estado;}
    string getCEP()const{return CEP;}
    string getComplemento()const{return complemento;}

    void lerEndereco(){
        cout << "\nRua: ";
        cin.ignore();
        getline(cin, rua);
        cout << "\nNúmero da casa: ";
        cin >> num;
        cin.ignore();
        while(num < 0){
            cout << "\nNúmero inválido. Digite um número positivo: ";
            cin >> num;
            cin.ignore();
        }
        cout << "\nBairro: ";
        getline(cin, bairro);
        cout << "\nCidade: ";
        getline(cin, cidade);
        cout << "\nEstado: ";
        getline(cin, estado);
        cout << "\nCEP: ";
        getline(cin, CEP);
        cout << "\nComplemento: ";
        getline(cin, complemento);
    }

    void imprimirEndereco()const{
        cout << getRua() << ", " << getNum() << ", " << getBairro() << ", " << getCidade() <<
         ", "<<getEstado() << ", " << getCEP() << ", " << getComplemento();
    }
};