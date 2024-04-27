#ifndef HEADER_H
#define HEADER_H

#include <map>
#include <vector>
#include <string>

class Astronauta {

  // Parâmetros
  protected:
    std::string CPF;
    std::string nome;
    int idade;
    bool alive, disponivel;
    std::vector<int> listaVoos;

  // Métodos
  public:
    Astronauta();
    Astronauta(std::string CPF, std::string nome, int idade);
    ~Astronauta();
    std::string getCPF();
    void adicionarVoo(int codigo);
};

class Voo {

  // Parâmetros
  private:
    std::map <std::string, Astronauta*> passageiros;
    int codigo;
    bool disponivel;
    static int qtdVoos;

  // Métodos
  public:
    Voo();
    void adicionarPassageiro(Astronauta* tripulante);
    void explodir();
    int getCodigo();
};

class Gerenciador  {

  // Parâmetros
  private:
    std::map <int, Voo*> voos;
    
};

#endif