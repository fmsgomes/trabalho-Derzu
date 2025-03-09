#pragma once
#include "Plano.hpp"
#include <string>
using namespace std;

class Planocompleto : public Plano{
    public:
    Planocompleto(DadosVeiculo d, Proprietario p) : Plano(d, p){}

    float calculoPlano()override{
        return getFipeVeiculo()*0.2;
    }
    void imprimirPlano()const override{
        exibirveiculo();
        exibirproprietario();
        cout << "\nValor do plano: R$ " << calculoPlano();
    }
};