#include <ctime>
#include <fstream>
#include <limits>
#include "../libraries/name_generator.hpp"

// Gera um nome aleatório a patir da lista em nomes.txt
std::string gerarNome() {

    std::string nome;
    std::ifstream file;

    file.open("./name_generator-v1.0/nomes.txt", std::ios::in);

    if (file.is_open()) {

        std::srand(std::time(0));
        int n_linha = rand() % 501;

        nome = GotoLine(file, n_linha);
    }
    else    {
        //KKKKKKKKKKKKKKKKKKK
        return "Isaac Franco";
    }

    file.close();

    return nome;
}

// Pula para uma determinada linha do arquivo
std::string GotoLine(std::ifstream &file, unsigned int n_linha) {

    file.seekg(std::ios::beg);
    for(unsigned int i = 0; i < n_linha - 1; i++){
        file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }

    std::string linha;
    std::getline(file, linha);

    return linha;
}