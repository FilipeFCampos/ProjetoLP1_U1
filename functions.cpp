#include <iostream>
#include <ctime>
#include "functions.hpp"
#include "classes.hpp"

std::string gerarCPF() { 
  
  /*Esse algorítmo de geração de CPF aleatório que eu escrevi 
    simula o modo pelo qual os CPFs são gerados na vida real*/
  //É bem legal

  std::string CPF;

  std::srand(std::time(0));

  //Definir os nove primeiros dígitos do CPF
  for (int i = 0; i < 9; i++)
    CPF += std::to_string(rand() % 10);

  //Definir o décimo dígito do CPF
  int digito = 0;

  for (size_t i = 0, n = 10; i < CPF.size(); i++, n--)
    digito += std::stoi(CPF.substr(i, 1)) * n;

  if (digito % 11 < 2)  {
    CPF += "0";
  }
  else {
    CPF += std::to_string(11 - (digito % 11));
  }

  //Definir o décimo primeiro dígito do CPF
  digito = 0;

  for (size_t i = 0, n = 10; i < CPF.size() - 1; i++, n--)
    digito += std::stoi(CPF.substr(i + 1, 1)) * n;

  if (digito % 11 < 2)  {
    CPF += "0";
  }
  else {
    CPF += std::to_string(11 - (digito % 11));
  }

  
  return CPF; 
}


void fatalidades()  {
  
}


void interface() {
  std::cout << "Selecione a funcao que deseja realizar:\n" << std::endl;
  std::cout << "1: Cadastrar voo" << std::endl;
  std::cout << "2: Cadastrar astronauta" << std::endl;
  std::cout << "3: Adicionar astronauta em um voo" << std::endl;
  std::cout << "4: Remover astronauta de um voo" << std::endl;
}