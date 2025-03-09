#pragma once
#include "Plano.hpp"
#include <string>
using namespace std;

class Planointermediario : public Plano{
    public:
    Planointermediario(DadosVeiculo d, Proprietario p) : Plano(d, p){}

    float calculoPlano()override{
        return getFipeVeiculo()*0.14;
    }
    void imprimirPlano()const override{
        exibirveiculo();
        exibirproprietario();
        getFipeVeiculo();
    }
};