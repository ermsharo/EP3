/*********************************************************************/
/**   ACH2023 - Algoritmos e Estruturas de Dados I                  **/
/**   EACH-USP - Segundo Semestre de 2020                           **/
/**   <turma> - Prof. Luciano Antonio Digiampietri                  **/
/**                                                                 **/
/**   EP3 - Fila de Prioridade (utilizando heap)                    **/
/**                                                                 **/
/**   <Emilio Haro>                   <10816857>                    **/
/**                                                                 **/
/*********************************************************************/

#include "filaDePrioridade.h"

PFILA criarFila(int max)
{
  PFILA res = (PFILA)malloc(sizeof(FILADEPRIORIDADE));
  res->maxElementos = max;
  res->arranjo = (PONT *)malloc(sizeof(PONT) * max);
  res->heap = (PONT *)malloc(sizeof(PONT) * max);
  int i;
  for (i = 0; i < max; i++)
  {
    res->arranjo[i] = NULL;
    res->heap[i] = NULL;
  }
  res->elementosNoHeap = 0;
  return res;
}

void exibirLog(PFILA f)
{
  printf("Log [elementos: %i]\n", f->elementosNoHeap);
  PONT atual;
  int i;
  for (i = 0; i < f->elementosNoHeap; i++)
  {
    atual = f->heap[i];
    printf("[%i;%f;%i] ", atual->id, atual->prioridade, atual->posicao);
  }
  printf("\n\n");
}

int tamanho(PFILA f)
{
  int tam = 0;
  /* COMPLETAR */

  while (f->heap[tam] != NULL)
  {
    tam++;
  }

  printf(" \n \n Tamanho eh (%i)", tam);

  return tam;
}

bool inserirElemento(PFILA f, int id, float prioridade)
{


  bool res = false;

  /* COMPLETAR */
  float resp;

  //Verificando se o elemento é valido
  if(consultarPrioridade(f, id, &resp) == true){
    //printf("Aqui esta");
  }else{
    //printf("Aqui esta");
  }

  if (id < 0 || id >= f->maxElementos || consultarPrioridade(f, id, &resp))   return res;



printf(" \n Inserindo elemento");
  PONT elemento = (PONT)malloc(sizeof(ELEMENTO));
  elemento->id = id;
  elemento->prioridade = prioridade;
  f->arranjo[id] = elemento;


  int i;

  //Adicionando elemento ao nosso heap

  for (i = 0 ; i < f->maxElementos; i++){
    printf("Trash");
    //HeapVazio

    if (f->heap[i] == NULL){
      elemento->posicao = 0;
      f->heap[i] = elemento;
      //Atualiazando tamanho do heap
      f->elementosNoHeap = f->elementosNoHeap + 1;
      i = f->maxElementos;
      printf("HEAP VAZIO");
    }

    //Elemento é o primeiro da fila não vazia
    else if (elemento->prioridade > f->heap[0]->prioridade)
    {
      int j = f->maxElementos - 1;
      while (j >= 0)
      {
        if (f->heap[j] != NULL)
        {
          f->heap[j + 1] = f->heap[j];
          f->heap[j + 1]->posicao++;
        }
        j--;
      }
      elemento->posicao = 0;
      f->heap[0] = elemento;

      f->elementosNoHeap = f->elementosNoHeap + 1;
      i = f->maxElementos;
    }

    //Caso elemento esteja no fim da fila

    else if (f->heap[i]->prioridade > elemento->prioridade && f->heap[i + 1]->prioridade < elemento->prioridade)
    {
      int j = f->maxElementos - 1;
      while (j > i)
      {
        if (f->heap[j] != NULL)
        {
          f->heap[j + 1] = f->heap[j];
          f->heap[j + 1]->posicao++;
        }
        j--;
      }

      elemento->posicao = f->heap[i]->posicao + 1;
      f->heap[i + 1] = elemento;
      f->elementosNoHeap = f->elementosNoHeap + 1;
      i = f->maxElementos;
    }
  }

  res = true;
  return res;
}

bool aumentarPrioridade(PFILA f, int id, float novaPrioridade)
{
  bool res = false;




  /* COMPLETAR */

  return res;
}

bool reduzirPrioridade(PFILA f, int id, float novaPrioridade)
{
  bool res = false;

  /* COMPLETAR */

  return res;
}

PONT removerElemento(PFILA f)
{
  PONT res = NULL;

  /* COMPLETAR */

  return res;
}

bool consultarPrioridade(PFILA f, int id, float *resposta)
{
  bool res = false;

  /* COMPLETAR  */

   //Verifica se o elemento eh valido, caso nao for retorna false
    if (id < 0 || id >= f->maxElementos){
        return res;}

    //Verifica se existe um elemento na fila com esse id
    PONT elemento = f->arranjo[id];
    if (elemento == NULL) {return res;}


printf("FOI AQUI");

    *resposta = elemento->prioridade;

    res = true;

    return res;

}

int main()
{

  printf("EP3 \n \n ");
  //Pega os casos de teste gerais depois

  //Criando a referencia para a nossa fila

  PFILA fila = malloc(sizeof(FILADEPRIORIDADE));
  fila = criarFila(15);
  exibirLog(fila);
  tamanho(fila);
  inserirElemento(fila, 0, 10);
  inserirElemento(fila, 1, 10);
  inserirElemento(fila, 2, 10);
  inserirElemento(fila, 3, 10);
  inserirElemento(fila, 4, 10);
  inserirElemento(fila, 5, 10);
  inserirElemento(fila, 6, 10);
  inserirElemento(fila, 7, 10);
  inserirElemento(fila, 8, 10);
  inserirElemento(fila, 9, 10);
  exibirLog(fila);
  tamanho(fila);

  return 0;
}