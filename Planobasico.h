#pragma once
#include "Plano.h"
#include <string>
using namespace std;

class Planobasico : public Plano{
public:
    Planobasico(DadosVeiculo d, Proprietario p) : Plano(d, p){}

    DadosVeiculo getVeiculo() const override {
        return veiculo;
    }


    float calculoPlano()override{
        return getFipeVeiculo()*0.1;
    }
    void imprimirPlano()override{
        exibirproprietario();
        exibirveiculo();
        cout << "Valor do plano: R$ " << calculoPlano();
    }
};