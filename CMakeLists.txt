cmake_minimum_required(VERSION 3.30)
project(SeguradoraVeiculos)

set(CMAKE_CXX_STANDARD 20)

add_executable(SeguradoraVeiculos main.cpp
        DadosVeiculo.h
        Data.h
        Endereco.h
        Gerenciarplanos.h
        Plano.h
        Planobasico.h
        Planocompleto.h
        Planointermediario.h
        Proprietario.h
        cmake-build-debug/dados_planos.txt
)
