#ifndef CLASSES_HPP
#define CLASSES_HPP

#include <map>
#include <vector>
#include <string>

// Classe Astronauta
class Astronauta {

  // Parâmetros
  private:
    std::string CPF;
    std::string nome;
    int idade;
    bool alive, disponivel;
    std::vector <int> listaVoos;

  // Métodos
  public:
    // Construtores e destrutores
    Astronauta();
    Astronauta(std::string CPF, std::string nome, int idade);
    ~Astronauta();
    // Getters
    std::string getCPF();
    std::string getNome();
    int getIdade();
    bool getAlive();
    bool getDisponivel();
    // Outros
    void morrer();
    void setDisponivel(bool set);
    void adicionarVoo(int codigo);
};

// Classe Voo
class Voo {

  // Parâmetros
  private:
    std::map <std::string, Astronauta*> passageiros;
    int codigo;
    bool disponivel;
    bool explodido;
    static int qtdVoos;

  // Métodos
  public:
    // Construtores e destrutores
    Voo();
    Voo(int codigo);
    ~Voo();
    // Getters
    bool getDisponivel();
    bool getExplodido();
    int getCodigo();
    int getQtdPassageiros();
    // Outros
    void adicionarPassageiro(Astronauta* tripulante);
    void removerPassageiro(std::string cpf);
    void explodir();
    void setDisponivel(bool set);
    int decolar();
    int checkPassageiros(std::string CPF);
};

//Classe Gerenciador
class Gerenciador  {

  // Parâmetros
  private:
    std::map <int, Voo*> viagens;
    std::map <std::string, Astronauta*> viajantes;

  // Métodos
  public:
    // Construtores e destrutores
    Gerenciador();
    ~Gerenciador();
    // Getters
    int getQtdViagens();
    int getQtdViajantes();
    // Outros
    void cadastrarVoo(Voo *voo);
    int cadastrarAstronauta(Astronauta *astronauta);
    void adicionarTripulante(std::string CPF, int codigo);
    void removerTripulante(std::string cpf, int codigo);
    int lancarVoo(int codigo);
    int explodirVoo(int codigo);
    int finalizarVoo(int codigo);
};

#endif