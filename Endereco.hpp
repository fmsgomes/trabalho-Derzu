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
    Endereco(string r, int n, string b, string c, string e, string cep, string complemento) : rua(r), 
    num(n), bairro(b), cidade(c), estado(e), CEP(cep), complemento(complemento){}

    string getRua()const{return rua;}
    int getNum()const{return num;}
    string getBairro()const{return bairro;}
    string getCidade()const{return cidade;}
    string getEstado()const{return estado;}
    string getCEP()const{return CEP;}
    string getComplemento()const{return complemento;}

    void imprimirEndereco()const{
        cout << getRua() << ", " << getNum() << ", " << getBairro() << ", " << getCidade() <<
         ", "<<getEstado() << ", " << getCEP() << ", " << getComplemento();
    }
};