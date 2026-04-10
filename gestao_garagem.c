#include <stdio.h>
#include <string.h>

int main(void) 
{
  struct garagem
  {
  char modelo[15];
  int ano;
  int consumo;
  char codigo[15];
  float valor_compra;
  };

  struct garagem veiculos[25];
  int quantidade, i, op, indice, cont=0, aux, aux2;
  float media, soma=0, maior=0;
  char cod[15];
  printf("\nInforme a quantidade de veículos: \n\n>> ");
  scanf("%d", &quantidade);
  if(quantidade <= 0 || quantidade > 25)
  {
    printf("\nQuantidade Inválida.\n");
  }
  else
  {
    printf("\n-------------------------------------------\n");
    printf("\n--> INFORMAÇÕES\n");
    for(i=0; i<quantidade; i++)
      {
        printf("\n.Informe o modelo de seu veículo: \n\n>> ");
        scanf("%s", veiculos[i].modelo);
        printf("\n.Informe o ano de seu veículo: \n\n>> ");
        scanf("%d", &veiculos[i].ano);
        printf("\n.Informe o código de seu veículo: \n\n>> ");
        scanf("%s", veiculos[i].codigo);
        printf("\n.Informe o consumo de seu veículo: \n\n>> ");
        scanf("%d", &veiculos[i].consumo);
        printf("\n.Informe o valor de compra de seu veículo: \n\n>> ");
        scanf("%f", &veiculos[i].valor_compra);
        printf("\n-------------------------------------------\n");
      }
  }
  do
    {
      printf("\n\n----MENU DE OPÇÕES-----\n"); 
      printf("\n1 - Atualizar dados do carro;\n");
      printf("\n2 - Média do valor gasto;\n");
      printf("\n3 - Busca de carro mais caro;\n");
      printf("\n4 - Apresentar dados;\n");
      printf("\nInforme uma opção \n\n>> ");
      scanf("%d", &op);
      if(op == 0)
      {
        break;
      }
      switch(op)
        {
          case 1:
          printf("\n.Informe o índice desejado: \n\n>> ");
          scanf("%d", &indice);
          printf("\n.Informe o modelo de seu veículo: \n\n>> ");
          scanf("%s", veiculos[indice].modelo);
          printf("\n.Informe o ano de seu veículo: \n\n>> ");
          scanf("%d", &veiculos[indice].ano);
          printf("\n.Informe o código de seu veículo: \n\n>> ");
          scanf("%s", veiculos[indice].codigo);
          printf("\n.Informe o consumo de seu veículo: \n\n>> ");
          scanf("%d", &veiculos[indice].consumo);
          printf("\n.Informe o valor de compra de seu veículo: \n\n>> ");
          scanf("%f", &veiculos[indice].valor_compra);
          printf("\n- > Veículo atualizado com sucesso!");
          break;

          case 2:
          media=0;
          soma=0;
          for(i=0; i<quantidade; i++)
            {
              soma += veiculos[i].valor_compra; 
              cont++; 
            }
          media = soma/cont;
          printf("\n- > A média dos valores de todos os carros é de R$%.2f\n", media);
          break;

          case 3:
          for(i=0; i<quantidade; i++)
            {
              if(veiculos[i].valor_compra > maior)
              {
                aux = i;
                maior = veiculos[i].valor_compra;
              }
            }
          printf("\n- > O maior valor de compra é: R$%.2f\n", maior);
          printf("\n.MODELO: %s\n", veiculos[aux].modelo);
          printf("\n.ANO: %d\n", veiculos[aux].ano);
          printf("\n.CÓDIGO: %s", veiculos[aux].codigo);
          printf("\n.CONSUMO: %d\n", veiculos[aux].consumo);
          break;
          
          case 4:
          printf("\nInforme o código do carro: \n\n>> ");
          scanf("%s", cod);
          for(i=0; i<quantidade; i++)
            {
              if(strcmp(cod, veiculos[i]. codigo) == 0)
              {
                aux2 = i;
                printf("\n.MODELO: %s\n", veiculos[aux2].modelo);
                printf("\n.ANO: %d\n", veiculos[aux2].ano);
                printf("\n.CONSUMO: %d\n", veiculos[aux2].consumo);
                printf("\n.VALOR DE COMPRA: R$%.2f\n", veiculos[aux2].valor_compra);
              }
            }
          break;
          default:
          printf("\nOpção Inválida.\n");
        }
        printf("\n.Informe 0 a seguir para encerrar o programa: ---> ");
    }
    while(op!=0);
    printf("\nPrograma Encerrado!");
  return 0;
}  
