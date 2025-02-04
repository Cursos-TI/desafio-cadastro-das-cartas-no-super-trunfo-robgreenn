#include <stdio.h>
#include <string.h>

/**
 * Struct da Carta
 */
struct Carta{

    char estado;
    char codigo_carta[4];
    char nome_cidade[50];
    int populacao;
    float area;
    float pib;
    int numero_pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
};

/**
 * Recebe os dados da Carta
 */
void RecebeEntrada(  ){
        
        struct Carta carta;

        printf("Digite o estado : \n");
        scanf(" %c", &carta.estado);
        fflush(stdin);
        
        printf("Digite o Código da Carta : \n");
        scanf("%s", &carta.codigo_carta);
        fflush(stdin);

        printf("Digite o Nome da cidade : \n");
        //Le todos os caracteries até encontrar uma nova linha, resolvendo o problema quando o nome da cidade tem espaços
        scanf(" %[^\n]s", &carta.nome_cidade); 
        //Limpa o caractere de nova linha
        getchar(); 

        printf("Digite o População : \n");
        scanf("%d", &carta.populacao);
        fflush(stdin);

        printf("Digite a Área : \n");
        scanf("%f", &carta.area);
        fflush(stdin);

        printf("Digite o PIB : \n");
        scanf("%f", &carta.pib);
        fflush(stdin);

        printf("Digite o Número de Pontos turísticos : \n");
        scanf("%d", &carta.numero_pontos_turisticos);
        fflush(stdin);
}
/**
 * Calculada como população dividida pela área da cidade. 
 */
float CalculaDensidade(){
    struct Carta carta;
    
    carta.densidade_populacional = (float)(carta.populacao / carta.area);

    return carta.densidade_populacional;

}
/**
 * Calculado como PIB total da cidade dividido pela população
 */
float CalculaPibPerCapita(){
    struct Carta carta;
    
    carta.pib_per_capita = (float)(carta.pib / carta.populacao);

    return carta.pib_per_capita;
}

/**
 * Mostra as Respostas da Entrada de Dados
 */
void MostraConteudo(){

    struct Carta carta;

    printf("\n.:: Respostas ::.");

    printf("\n\nEstado: %c \n", carta.estado);
    printf("Código da Carta: %s \n",carta.codigo_carta);
    printf("Nome da Cidade: %s \n",carta.nome_cidade);
    printf("População: %d \n",carta.populacao);
    printf("Área: %f km²\n",carta.area);
    printf("Densidade Populacional: %f pessoas/km²\n",carta.densidade_populacional);
    printf("PIB: %f bilhões de reais\n", carta.pib);
    printf("PIB per Capita: %f reais\n", carta.pib_per_capita);
    printf("Número de Pontos Turísticos: %d \n\n\n",carta.numero_pontos_turisticos);
}


int main() {

    //Mensagem de Boas Vindas
    printf("Olá, seja ben-vindo ao Desafio super trunfo! \n\n");
    
    RecebeEntrada();
    CalculaDensidade();
    CalculaPibPerCapita();
    MostraConteudo();

    return 0; 
}