#include <stdio.h>
#include <string.h>


/**
 * Struct da Carta
 */
typedef struct Carta{

    char estado;
    char codigo_carta[4];
    char nome_cidade[50];
    int populacao;
    float area;
    float pib;
    int numero_pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    double super_poder;
};


/**
 * @param struct Carta - Recebe um poiteiro da struct Carta
 * Calculada como população dividida pela área da cidade. 
 */
float CalculaDensidade( struct Carta *carta){
    
    carta->densidade_populacional = (float)(carta->populacao / carta->area);

    return carta->densidade_populacional;

}
/**
 * @param struct Carta - Recebe um poiteiro da struct Carta
 * Calculado como PIB total da cidade dividido pela população
 */
float CalculaPibPerCapita( struct Carta *carta){
    
    carta->pib_per_capita = (float)(carta->pib / carta->populacao);

    return carta->pib_per_capita;
}

/**
 * @param struct Carta - Recebe um poiteiro da struct Carta
 * Calcula o super poder da carta
 */
float CriaSuperPoder( struct Carta *carta ){
    float densidade_populacional_invertida = carta->densidade_populacional / 1.0;
    carta->super_poder = (float) (carta->populacao + carta->area + carta->pib + carta->pib_per_capita + carta->numero_pontos_turisticos + densidade_populacional_invertida);

    return carta->super_poder;
}


/**
 * @param struct Carta - Recebe um poiteiro da struct Carta
 * Recebe os inputs do usuario e atribui na struct carta
 */

void RecebeEntrada(struct Carta *carta){

    printf("Digite o estado : \n");
    scanf(" %c", &carta->estado);
    fflush(stdin);
    
    printf("Digite o Código da Carta : \n");
    scanf("%s", &carta->codigo_carta);
    fflush(stdin);

    printf("Digite o Nome da cidade : \n");
    //Le todos os caracteries até encontrar uma nova linha, resolvendo o problema quando o nome da cidade tem espaços
    scanf(" %[^\n]s", &carta->nome_cidade); 
    //Limpa o caractere de nova linha
    getchar(); 

    printf("Digite o População : \n");
    scanf("%d", &carta->populacao);
    fflush(stdin);

    printf("Digite a Área : \n");
    scanf("%f", &carta->area);
    fflush(stdin);

    printf("Digite o PIB : \n");
    scanf("%f", &carta->pib);
    fflush(stdin);

    printf("Digite o Número de Pontos turísticos : \n");
    scanf("%d", &carta->numero_pontos_turisticos);
    fflush(stdin);

}

/**
 * @param struct carta1,carta2 - cada uma das variaveis rebece um ponteira da struct Carta
 * Compara as propriedade, mostra as etapas de comparação e mostra a carta vencedora
 */
void ComparaCartas( struct Carta *carta1 , struct Carta *carta2){

    printf(".: Comparação de Cartas :.\n\n");

    if( carta1->densidade_populacional < carta2->densidade_populacional ){
        printf("Densidade Populacional: Carta 1 '%s' Venceu \n",&carta1->nome_cidade);
        
    }else{
        printf("Densidade Populacional: Carta 2 '%s' Venceu \n",&carta2->nome_cidade);
        
    }

    if(&carta1->populacao > &carta2->populacao){
        printf("População: Carta 1 '%s' Venceu \n",&carta1->nome_cidade);
        
    }else{
        printf("População: Carta 2 '%s' Venceu \n",&carta2->nome_cidade);
        
    }

    if(&carta1->area > &carta2->area){
        printf("Área: Carta 1 '%s' Venceu\n",&carta1->nome_cidade);
    }else{
        printf("Área: Carta 2 '%s' Venceu\n",&carta2->nome_cidade);
        
    }


    if(&carta1->pib > &carta2->pib){
        printf("PIB: Carta 1 '%s' Venceu \n",&carta1->nome_cidade);
        
    }else{
        printf("PIB: Carta 2 '%s' Venceu \n",&carta2->nome_cidade);
        
    }
    
    if(&carta1->pib_per_capita > &carta2->pib_per_capita){
        printf("PIB per Capita: Carta 1 '%s' Venceu \n",&carta1->nome_cidade);
        
    }else{
        printf("PIB per Capita: Carta 2 '%s' Venceu \n",&carta2->nome_cidade);
        
    }

    if(&carta1->numero_pontos_turisticos > &carta2->numero_pontos_turisticos){
        printf("Pontos Turísticos: Carta 1 '%s' Venceu \n",&carta1->nome_cidade);
        
    }else{
        printf("Pontos Turísticos: Carta 2 '%s' Venceu \n",&carta2->nome_cidade);
        
    }


    if(&carta1->super_poder > &carta2->super_poder){
        printf("Super Poder: Carta 1 '%s' Venceu\n\n",&carta1->nome_cidade);
        
    }else{
        printf("Super Poder: Carta 2 '%s' Venceu\n\n",&carta2->nome_cidade);
        
    }


}


/**
 * @param struct Carta - Recebe struct Carta
 * Mostra as Respostas da Entrada de Dados
 */
void MostraConteudo( struct Carta carta ){

    printf("\n\nEstado: %c \n", carta.estado);
    printf("Código da Carta: %s \n",carta.codigo_carta);
    printf("Nome da Cidade: %s \n",carta.nome_cidade);
    printf("População: %d \n",carta.populacao);
    printf("Área: %.2f km²\n",carta.area);
    printf("Densidade Populacional: %.2f pessoas/km²\n",carta.densidade_populacional);
    printf("PIB: %.2f bilhões de reais\n", carta.pib);
    printf("PIB per Capita: %.2f reais\n", carta.pib_per_capita);
    printf("Número de Pontos Turísticos: %d \n",carta.numero_pontos_turisticos);
    printf("Super Trunfo: %.2f Pontos\n\n\n", carta.super_poder);
}


int main() {

    //Mensagem de Boas Vindas
    printf("Olá, seja ben-vindo ao Desafio super trunfo! \n\n");

    
    struct Carta cartas[2];
    
    for( int i = 0; i < 2; i++ ){
        RecebeEntrada(&cartas[i]);
        //Calcula Desindade Populacional
        CalculaDensidade(&cartas[i]);
        //Calcula Pib Per Capito
        CalculaPibPerCapita(&cartas[i]);
        //Cria Super Poder
        CriaSuperPoder(&cartas[i]);
        
    }
    
    
    for( int i = 0; i < 2; i++ ){
        MostraConteudo(*&cartas[i]);
    }

    ComparaCartas(&cartas[0],&cartas[1]);

    return 0; 
}