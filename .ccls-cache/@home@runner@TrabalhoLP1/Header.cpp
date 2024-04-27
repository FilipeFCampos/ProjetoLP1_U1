#ifndef HEADER_H
#define HEADER_H

#include <string>
#include <vector>

class Astronauta  {

  protected:
    std::string cpf;
    std::string nome;
    int idade;
  public:

};

class Voo  {

  private:
    std::vector <Astronauta> passageiros;
    int codigo;
  public:

};

#endif