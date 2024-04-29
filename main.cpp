#include <iostream>
#include "classes.hpp"
#include "functions.hpp"

int main(void) {

  int option;
  Gerenciador gerenciador;

  std::cout << ".    _     *       \\|/   .       .      -*-              +" << std::endl;
  std::cout << "  .' \\\\`.     +    -*-     *   .         '       .   *" << std::endl;
  std::cout << ". |__''_|  .       /|\\ +         .    +       .           |" << std::endl;
  std::cout << "  |     | .                                        .     -*-" << std::endl;
  std::cout << "  |     |           `  .    '             . *   .    +    |" << std::endl;
  std::cout << "_.'-----'-.__    *                  ." << std::endl;
  std::cout << "/          AEB\\__.__.--._______________\n\n" << std::endl;
  std::cout << "\033[1;34mBem vindo ao gerenciador de viagens espaciais!\033[0m\n" << std::endl;

  while (true)  {

    interface();
    /*Selecione a funcao que deseja realizar:
    [1]: Cadastrar voo
    [2]: Cadastrar astronauta
    [3]: Adicionar astronauta em um voo
    [4]: Remover astronauta de um voo
    [0]: Sair*/

    option = -1;
    /*Eu defini o option como -1 aqui só para caso haja um erro e o 
      std::cin não funcione, o código não comece a alocar novos voos
      ou astronautas em loop por acidente e sim dê erro de opção inválida*/
    std::cin >> option;
    
    switch (option)  {
      
      // Cadastrar voo
      case 1:
        {
          Voo *voo = new Voo();
          gerenciador.cadastrarVoo(voo);
        }
        break;

      // Cadastrar astronauta
      case 2:
        {
          int escolha;
          std::cout << "\nDeseja definir os parametros do astronauta ou gerar um astronauta aleatorio?\n" << std::endl;
          std::cout << "[1] Passar parametros" << std::endl;
          std::cout << "[2] Gerar astronauta aleatorio" << std::endl;
          std::cin >> escolha;

          if (escolha == 1)  {
            std::string CPF, nome;
            int idade;
            std::cout << "Digite o CPF do astronauta: ";
            std::cin >> CPF;
            std::cout << "Digite o nome do astronauta: ";
            std::getline(std::cin >> std::ws, nome);
            std::cout << "Digite a idade do astronauta: ";
            std::cin >> idade;

            Astronauta *astronauta = new Astronauta(CPF, nome, idade);
            gerenciador.cadastrarAstronauta(astronauta);
          }
          else if (escolha == 2)  {
            Astronauta *astronauta = new Astronauta();
            gerenciador.cadastrarAstronauta(astronauta);
          }
          else  {
            std::cout << "\033[31;1mERRO: Opcao invalida.\033[m" << std::endl;
          }
        }
        break;

      // Castrar astronauta em um voo
      case 3:
        {
          if (gerenciador.getQtdViagens() == 0)  {
            std::cout << "\n\033[31;1mERRO: Nao ha voos cadastrados.\033[m" << std::endl;
          }
          else if (gerenciador.getQtdViajantes() == 0)  {
            std::cout << "\n\033[31;1mERRO: Nao ha astronautas cadastrados.\033[m" << std::endl;
          }
          else {
            std::string cpf;
            int codigo;
            std::cout << "Por favor digite o CPF do astronauta que deseja adicionar:" << std::endl;
            std::cin >> cpf;
            std::cout << "Por favor digite o codigo do voo que deseja atribuir:" << std::endl;
            std::cin >> codigo;
            gerenciador.adicionarTripulante(cpf, codigo);
          }
        }
        break;

      case 4:
        {/*Remover astronauta de um voo*/}
        break;

      // Sair
      case 0:
        {
          char confirmacao;
          
          std::cout << "Tem certeza que deseja sair? (S/N)" << std::endl;
          std::cin >> confirmacao;
          
          if (confirmacao == 'S' || confirmacao == 's')  {
            std::cout << "\n\033[32;1mObrigado por usar o gerenciador de viagens espaciais!!\033[m\n" << std::endl;
            return 0;
          }
          else if (confirmacao == 'N' || confirmacao == 'n')  {
            std::cout << "\nVoltando ao menu principal...\n" << std::endl;
          }
          else {
            std::cout << "\n\033[31;1mERRO: Opcao invalida.\033[m" << std::endl;
          }
        }
        break;

      // Opção inválida
      default:
        {
          std::cout << "\n\033[31;1mERRO: Opcao invalida.\033[m" << std::endl;
        }
        break;
    }
  }
  

  return 1;
}