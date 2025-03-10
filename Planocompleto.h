#pragma once
#include "Plano.h"
#include <string>
using namespace std;

class Planocompleto : public Plano{
public:
    Planocompleto(DadosVeiculo d, Proprietario p) : Plano(d, p){}

    DadosVeiculo getVeiculo() const override {
        return veiculo;
    }


    float calculoPlano()override{
        return getFipeVeiculo()*0.2;
    }
    void imprimirPlano()override{
        exibirproprietario();
        exibirveiculo();
        cout << "Valor do plano: R$ " << calculoPlano();
    }
};