#pragma once
#include "Plano.hpp"
#include <string>
using namespace std;

class Planobasico : public Plano{
    public:
    Planobasico(DadosVeiculo d, Proprietario p) : Plano(d, p){}

    float calculoPlano()override{
        return getFipeVeiculo()*0.1;
    }
    void imprimirPlano()const override{
        exibirveiculo();
        exibirproprietario();
        cout << "\nValor do plano: R$ " << calculoPlano();
    }
};