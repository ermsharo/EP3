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
  if (consultarPrioridade(f, id, &resp) == true)
  {
    //printf("Aqui esta");
  }
  else
  {
    //printf("Aqui esta");
  }

  if (id < 0 || id >= f->maxElementos || consultarPrioridade(f, id, &resp))  return res;

  printf(" \n Inserindo elemento");
  PONT elemento = (PONT)malloc(sizeof(ELEMENTO));
  elemento->id = id;
  elemento->prioridade = prioridade;
  f->arranjo[id] = elemento;

  int i;

  //Adicionando elemento ao nosso heap

  for (i = 0; i < f->maxElementos; i++)
  {
    //printf("Trash");


    if (f->heap[i] == NULL)
    {
      elemento->posicao = 0;
      f->heap[i] = elemento;
      //Atualiazando tamanho do heap
      f->elementosNoHeap = f->elementosNoHeap + 1;
      i = f->maxElementos;
      printf("HEAP VAZIO");
    } else if (elemento->prioridade > f->heap[0]->prioridade){
      int j = f->maxElementos - 1;
      while (j >= 0)
      {
        if (f->heap[j] != NULL) { f->heap[j + 1] = f->heap[j];  f->heap[j + 1]->posicao++;}

        j--;
      }
      elemento->posicao = 0;
      f->heap[0] = elemento;

      f->elementosNoHeap = f->elementosNoHeap + 1;
      i = f->maxElementos;
    }

        //Caso o elemento pertenca ao final da fila
        else if (f->heap[i + 1] == NULL)
        {
            elemento->posicao = f->heap[i]->posicao + 1;

            f->heap[i + 1] = elemento;
            f->elementosNoHeap = f->elementosNoHeap + 1;
            i = f->maxElementos;
        }

    else if ((f->heap[i]->prioridade > elemento->prioridade) && (f->heap[i + 1]->prioridade < elemento->prioridade))
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

  float resposta;

  if (id < 0 || id >= f->maxElementos || !consultarPrioridade(f, id, &resposta))
    return res;

  //Procurar qual é o elemento dentro do heap
  //Transformar esta função em metodo depois

  int pos;
  int i;
  //Ver se não altera colocar a declaração do i dentro do laço

  //Aqui esta verificando  a existencia de uma prioridade, seria bom criar uma função pura  só para isso
  for (i = 0; i < f->maxElementos; i++)
  {
    if (f->heap[i]->id == id)
    {

      if (f->heap[i]->prioridade >= novaPrioridade)
        return res;
      pos = i;
      i = f->maxElementos;
    }
  }

  //Mudando a prioridade

  //Criar um metodo para isso tambem ???
  f->heap[pos]->prioridade = novaPrioridade;

  PONT pontElemento;
  pontElemento = f->heap[pos];

  i = pos;
  bool aux = false;

  //Refatorar

  //
  if (i > 0)
  {
    while (!aux)
    {

      if (f->heap[i + 1])
      {
        if ((f->heap[i - 1]->prioridade >= f->heap[i]->prioridade) && (f->heap[i + 1]->prioridade <= f->heap[i]->prioridade))
          aux = true;
      }
      else
      {
        if (f->heap[i - 1]->prioridade > f->heap[i]->prioridade)
          aux = true;
      }
      if (!aux)
      {
        f->heap[i] = f->heap[i - 1];
        f->heap[i - 1] = pontElemento;
        f->heap[i]->posicao++;
        f->heap[i - 1]->posicao--;
      }
      i--;
      if (i == 0)
        aux = true;
    }
  }

  res = true;

  return res;
}

bool reduzirPrioridade(PFILA f, int id, float novaPrioridade)
{
  bool res = false;

  /* COMPLETAR */

  float resposta;

  //Verificar se o elemento é valido //REFATORAR !!!
  if (id < 0 || id >= f->maxElementos || !consultarPrioridade(f, id, &resposta))
    return res;

  int i;
  int pos;
  for (i = 0; i < f->maxElementos; i++)
  {
    if (f->heap[i]->id == id)
    {

      if (f->heap[i]->prioridade <= novaPrioridade)
        return res;

      pos = i;
      i = f->maxElementos;
    }
  }




  //Mudando a prioriadade

  f->heap[pos]->prioridade = novaPrioridade;

  PONT elem;
  elem = f->heap[pos];

  i = pos;
  bool aux = false;

  if (i < f->maxElementos - 1)
  {
    while (!aux)
    {
      if (f->heap[i]->posicao > 0)
      {
        if ((f->heap[i - 1]->prioridade >= f->heap[i]->prioridade) && (f->heap[i + 1]->prioridade <= f->heap[i]->prioridade))
          aux = true;
      }
      else
      {
        if (f->heap[i + 1]->prioridade < f->heap[i]->prioridade)
          aux = true;
      }
      if (!aux)
      {
        f->heap[i] = f->heap[i + 1];
        f->heap[i + 1] = elem;

        f->heap[i]->posicao--;
        f->heap[i + 1]->posicao++;
      }

      i++;
      if (i == f->elementosNoHeap - 1)
        aux = true;
    }
  }

  res = true;
  return res;
}



bool Reordenar(PFILA f,PONT ref){

  bool resultado = true; 
  
  if(ref == NULL) return resultado;


  int esq = (2 * ref->posicao) + 1; int dir = (2 * ref->posicao)+ 2 ; 
  if(dir >= f->elementosNoHeap) return resultado;  
  if(esq >= f->elementosNoHeap) return resultado;  

  int big = esq; 
  if(dir >= 2){
    if(f->heap[esq]->prioridade < f->heap[dir]->prioridade){
      big = dir; 
    }
  }

  if(ref-> prioridade < f->heap[big]->prioridade){
    PONT aux = f->heap[big]; 
    int posAux = ref->posicao;

    f->heap[big] = ref; 
    ref->posicao = big; 

    f->heap[posAux] = aux;
    aux->posicao = posAux; 

    Reordenar(f,ref);
  }


}

PONT removerElemento(PFILA f)
{
  PONT res = NULL;

  /* COMPLETAR */
  

  if(f->elementosNoHeap == 0) return res; 

      res = f->heap[0]; 
      f->heap[0] = f->heap[f->elementosNoHeap -1]; 
      f->heap[0]->posicao = 0; 

      f->heap[f->elementosNoHeap -1] = NULL;
      (f->elementosNoHeap = f->elementosNoHeap -1); 
      f->arranjo[res->id] = NULL;
  
      PONT ref = f->heap[0];  
      
      Reordenar(f,ref);

      return res; 

}

bool consultarPrioridade(PFILA f, int id, float *resposta)
{
  bool res = false;

  /* COMPLETAR  */

  //Verifica se o elemento eh valido, caso nao for retorna false
  if (id < 0 || id >= f->maxElementos)
  {
    return res;
  }

  //Verifica se existe um elemento na fila com esse id
  PONT elemento = f->arranjo[id];
  if (elemento == NULL)
  {
    return res;
  }

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

    inserirElemento(fila, 0, 1);
    inserirElemento(fila, 1, 2);
    inserirElemento(fila, 2, 3);
    inserirElemento(fila, 3, 4);

    inserirElemento(fila, 5, 8);
    inserirElemento(fila, 6, 5);
    inserirElemento(fila, 7, 10);
    inserirElemento(fila, 8, 2);
    inserirElemento(fila, 9, 8);

    reduzirPrioridade(fila,2,0);
    aumentarPrioridade(fila,5,99);

    

  exibirLog(fila);
  tamanho(fila);

  removerElemento(fila);

  exibirLog(fila);
  tamanho(fila);

  

  return 0;
}