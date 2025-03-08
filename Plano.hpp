#pragma once
#include <string>
#include "DadosVeiculo.hpp"
#include "Proprietario.hpp"
using namespace std;

class Plano{
    protected:
    int tipo;
    DadosVeiculo veiculo;
    Proprietario proprietario;

    public:
    Plano(int t) : tipo(t){}
    Plano(int t, DadosVeiculo d, Proprietario p) : tipo(t), veiculo(d), proprietario(p){}

    void adicionarVeiculo(){
        veiculo.lerDadosVeiculo();
    }
    void adicionarProprietario(){
        proprietario.lerDadosProprietario();
    }
    void exibirveiculo(){
        veiculo.ImprimirVeiculo();
    }
    void exibirproprietario(){
        proprietario.ImprimirProprietario();
    }
    virtual void calculoPlano() = 0;
    virtual void calculoPlano() = 0;
};