#pragma once
#include <string>
#include "DadosVeiculo.hpp"
#include "Proprietario.hpp"
using namespace std;

class Plano{
    protected:
    DadosVeiculo veiculo;
    Proprietario proprietario;

    public:
    Plano(DadosVeiculo d, Proprietario p) : veiculo(d), proprietario(p){}

    void adicionarVeiculo(){
        veiculo.lerDadosVeiculo();
    }
    void adicionarProprietario(){
        proprietario.lerDadosProprietario();
    }
    void exibirveiculo()const{
        veiculo.ImprimirVeiculo();
    }
    void exibirproprietario()const{
        proprietario.ImprimirProprietario();
    }
    float getFipeVeiculo(){return veiculo.getFipe();}
    virtual float calculoPlano() = 0;
    virtual void imprimirPlano() = 0;
};