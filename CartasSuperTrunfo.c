#include <stdio.h>
#include <string.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
//Teste larissa

int main() {
    // Sugestão: Defina variáveis separadas para cada atributo da cidade.
    // Exemplos de atributos: código da cidade, nome, população, área, PIB, número de pontos turísticos.
    //Variaveis 
    char estado;
    char codigo_carta[4];
    char nome_cidade[50];
    int populacao;
    float area;
    float pib;
    int numero_pontos_turisticos;
    
    // Cadastro das Cartas:
    // Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.

        //Mensagem de boas vindas
    printf("Olá, seja ben-vindo ao Desafio super trunfo! \n\n");

    //Incio do input de dados
    printf("Digite o estado : \n");
    scanf("%c", &estado);
    fflush(stdin); //Limpa o buffer da entrada
    
    printf("Digite o Código da Carta : \n");
    scanf("%s", &codigo_carta);
    fflush(stdin);

    printf("Digite o Nome da cidade : \n");
    //Le todos os caracteries até encontrar uma nova linha, resolvendo o problema quando o nome da cidade tem espaços
    scanf(" %[^\n]s", &nome_cidade); 
    //Limpa o caractere de nova linha
    getchar(); 

    printf("Digite o População : \n");
    scanf("%d", &populacao);
    fflush(stdin);

    printf("Digite a Área : \n");
    scanf("%f", &area);
    fflush(stdin);

    printf("Digite o PIB : \n");
    scanf("%f", &pib);
    fflush(stdin);

    printf("Digite o Número de Pontos turísticos : \n");
    scanf("%d", &numero_pontos_turisticos);
    fflush(stdin);
    
    // Exibição dos Dados das Cartas:
    // Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.

     //Mosta a saida dos dados
    printf("\n.:: Respostas ::.");

    printf("\n\nEstado: %c \n", estado);
    printf("Código da Carta: %s \n",codigo_carta);
    printf("Nome da Cidade: %s \n",nome_cidade);
    printf("População: %d \n",populacao);
    printf("Área: %f km²\n",area);
    printf("PIB: %f bilhões de reais\n", pib);
    printf("Número de Pontos Turísticos: %d \n\n\n",numero_pontos_turisticos);

    //retorna 0
    
    return 0;
}
