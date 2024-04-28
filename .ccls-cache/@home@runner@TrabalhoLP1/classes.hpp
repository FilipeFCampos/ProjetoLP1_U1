#ifndef HEADER_H
#define HEADER_H

#include <map>
#include <vector>
#include <string>

// Classe Astronauta
class Astronauta {

  // Parâmetros
  protected:
    std::string CPF;
    std::string nome;
    int idade;
    bool alive, disponivel;
    std::vector <int> listaVoos;

  // Métodos
  public:
    Astronauta();
    Astronauta(std::string CPF, std::string nome, int idade);
    ~Astronauta();
    std::string getCPF();
    std::string getNome();
    int getIdade();
    void morrer();
    void adicionarVoo(int codigo);
};

// Classe Voo
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
    Voo(int codigo);
    ~Voo();
    void adicionarPassageiro(Astronauta* tripulante);
    void explodir();
    int getCodigo();
};

//Classe Gerenciador
class Gerenciador  {

  // Parâmetros
  private:
    std::map <int, Voo*> viagens;
    std::map <std::string, Astronauta*> viajantes;

  public:
    Gerenciador();
    ~Gerenciador();
    void cadastrarVoo(Voo *voo);
    void cadastrarAstronauta(Astronauta *astronauta);
};

#endif