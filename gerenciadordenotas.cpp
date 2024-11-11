#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Definindo constantes
const int NUM_DISCIPLINAS = 3; // Número de disciplinas
const int NUM_ESTUDANTES = 5;   // Número de estudantes

// Funções
void menuPrincipal();
void entradaDeDados(string estudantes[], double notas[][NUM_DISCIPLINAS]);
void exibirNotas(const string estudantes[], const double notas[][NUM_DISCIPLINAS]);
void calcularMediaPorEstudante(const double notas[][NUM_DISCIPLINAS], double medias[]);
void calcularMediaPorDisciplina(const double notas[][NUM_DISCIPLINAS], double medias[]);
void maiorEMenorNota(const double notas[][NUM_DISCIPLINAS], double maior[], double menor[]);

int main() {
    string estudantes[NUM_ESTUDANTES];
    double notas[NUM_ESTUDANTES][NUM_DISCIPLINAS];
    double mediasEstudantes[NUM_ESTUDANTES];
    double mediasDisciplinas[NUM_DISCIPLINAS];
    double maiorNotas[NUM_DISCIPLINAS];
    double menorNotas[NUM_DISCIPLINAS];
    int opcao;

    entradaDeDados(estudantes, notas); // Preenche os dados dos estudantes

    do {
        menuPrincipal(); // Mostra o menu
        cin >> opcao; // Lê a opção escolhida

        switch (opcao) {
            case 1:
                exibirNotas(estudantes, notas); // Exibe as notas
                break;
            case 2:
                calcularMediaPorEstudante(notas, mediasEstudantes); // Calcula médias dos estudantes
                cout << "Médias por estudante:\n";
                for (int i = 0; i < NUM_ESTUDANTES; i++) {
                    cout << estudantes[i] << ": " << fixed << setprecision(2) << mediasEstudantes[i] << endl;
                }
                break;
            case 3:
                calcularMediaPorDisciplina(notas, mediasDisciplinas); // Calcula médias por disciplina
                cout << "Médias por disciplina:\n";
                for (int i = 0; i < NUM_DISCIPLINAS; i++) {
                    cout << "Disciplina " << (i + 1) << ": " << fixed << setprecision(2) << mediasDisciplinas[i] << endl;
                }
                break;
            case 4:
                maiorEMenorNota(notas, maiorNotas, menorNotas); // Encontra maior e menor nota
                cout << "Maior e menor nota por disciplina:\n";
                for (int i = 0; i < NUM_DISCIPLINAS; i++) {
                    cout << "Disciplina " << (i + 1) << " - Maior: " << maiorNotas[i] << ", Menor: " << menorNotas[i] << endl;
                }
                break;
            case 0:
                cout << "Saindo do sistema...\n"; // Sai do programa
                break;
            default:
                cout << "Opção inválida. Tente novamente.\n"; // Mensagem de erro
        }
    } while (opcao != 0); // Continua até que o usuário escolha sair

    return 0; // Fim do programa
}

// Função que exibe o menu principal
void menuPrincipal() {
    cout << "\n--- Sistema de Gerenciamento de Notas ---\n";
    cout << "1. Exibir Notas\n";
    cout << "2. Calcular Média por Estudante\n";
    cout << "3. Calcular Média por Disciplina\n";
    cout << "4. Identificar Maior e Menor Nota\n";
    cout << "0. Sair\n";
    cout << "Escolha uma opção: ";
}

// Função que lê os dados dos estudantes e suas notas
void entradaDeDados(string estudantes[], double notas[][NUM_DISCIPLINAS]) {
    for (int i = 0; i < NUM_ESTUDANTES; i++) {
        cout << "Digite o nome do estudante " << (i + 1) << ": ";
        cin >> estudantes[i]; // Lê o nome do estudante
        for (int j = 0; j < NUM_DISCIPLINAS; j++) {
            cout << "Digite a nota da disciplina " << (j + 1) << ": ";
            cin >> notas[i][j]; // Lê a nota para cada disciplina
        }
    }
}

// Função que exibe as notas dos estudantes
void exibirNotas(const string estudantes[], const double notas[][NUM_DISCIPLINAS]) {
    cout << "\nNotas dos Estudantes:\n";
    for (int i = 0; i < NUM_ESTUDANTES; i++) {
        cout << estudantes[i] << ": ";
        for (int j = 0; j < NUM_DISCIPLINAS; j++) {
            cout << notas[i][j] << " "; // Exibe as notas de cada estudante
        }
        cout << endl;
    }
}

// Função que calcula a média das notas de cada estudante
void calcularMediaPorEstudante(const double notas[][NUM_DISCIPLINAS], double medias[]) {
    for (int i = 0; i < NUM_ESTUDANTES; i++) {
        double soma = 0;
        for (int j = 0; j < NUM_DISCIPLINAS; j++) {
            soma += notas[i][j]; // Soma as notas
        }
        medias[i] = soma / NUM_DISCIPLINAS; // Calcula a média
    }
}

// Função que calcula a média das notas por disciplina
void calcularMediaPorDisciplina(const double notas[][NUM_DISCIPLINAS], double medias[]) {
    for (int j = 0; j < NUM_DISCIPLINAS; j++) {
        double soma = 0;
        for (int i = 0; i < NUM_ESTUDANTES; i++) {
            soma += notas[i][j]; // Soma as notas de cada disciplina
        }
        medias[j] = soma / NUM_ESTUDANTES; // Calcula a média
    }
}

// Função que encontra a maior e a menor nota por disciplina
void maiorEMenorNota(const double notas[][NUM_DISCIPLINAS], double maior[], double menor[]) {
    for (int j = 0; j < NUM_DISCIPLINAS; j++) {
        maior[j] = notas[0][j]; // Inicializa com a primeira nota
        menor[j] = notas[0][j]; // Inicializa com a primeira nota
        for (int i = 1; i < NUM_ESTUDANTES; i++) {
            if (notas[i][j] > maior[j]) {
                maior[j] = notas[i][j]; // Atualiza a maior nota
            }
            if (notas[i][j] < menor[j]) {
                menor[j] = notas[i][j]; // Atualiza a menor nota
            }
        }
    }
}
