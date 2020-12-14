/*********************************************************************/
/**   ACH2023 - Algoritmos e Estruturas de Dados I                  **/
/**   EACH-USP - Segundo Semestre de 2020                           **/
/**   <ACH2023-2020204> - Prof. Luciano Antonio Digiampietri        **/
/**                                                                 **/
/**   EP3 - Fila de Prioridade (utilizando heap)                    **/
/**                                                                 **/
/**   <Emilio Haro>                   <10816857>                    **/
/**                                                                 **/
/*********************************************************************/

#include "filaDePrioridade.h"

/* static bool verificaELemento(int id, PFILA f , *float vf)
{

  bool resp = 0;

  float resposta;

  if (id < 0 || id >= f->maxElementos || !consultarPrioridade(f, id, &vf))
    return resp;

  resp = true;

  return resp;
}*/

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

  if (id < 0 || id >= f->maxElementos || consultarPrioridade(f, id, &resp))
    return res;

  PONT elemento = (PONT)malloc(sizeof(ELEMENTO));
  elemento->id = id;
  elemento->prioridade = prioridade;
  f->arranjo[id] = elemento;

  int i;

  for (i = 0; i < f->maxElementos; i++)
  {

    if (f->heap[i] == NULL)
    {
      elemento->posicao = 0;
      f->heap[i] = elemento;
      f->elementosNoHeap = f->elementosNoHeap + 1;
      i = f->maxElementos;
    }
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

  int pos;
  int i;

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

  f->heap[pos]->prioridade = novaPrioridade;

  PONT pontElemento;
  pontElemento = f->heap[pos];

  i = pos;
  bool aux = false;

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

  float resposta;

if(id < 0 || id >= f->maxElementos -1 || !consultarPrioridade(f, id, &resposta)) return res;

  int i;
  int pos;
  for (i = 0; i <= f->maxElementos; i++)
  {
    if (f->heap[i]->id == id)
    {

      if (f->heap[i]->prioridade <= novaPrioridade)
        return res;

      pos = i;
      i = f->maxElementos;
    }
  }

  f->heap[pos]->prioridade = novaPrioridade;

  PONT elem;
  elem = f->heap[pos];

  i = pos;
  bool aux = false;

  if (i <= f->maxElementos - 1)
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
        if (f->heap[i + 1]->prioridade <= f->heap[i]->prioridade)
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

bool Reordenar(PFILA f, PONT ref)
{

  bool resultado = true;

  if (ref == NULL)
    return resultado;

  int esq = (2 * ref->posicao) + 1;
  int dir = (2 * ref->posicao) + 2;
  if (dir >= f->elementosNoHeap)
    return resultado;
  if (esq >= f->elementosNoHeap)
    return resultado;

  int big = esq;
  if (dir >= 2)
  {
    if (f->heap[esq]->prioridade < f->heap[dir]->prioridade)
    {
      big = dir;
    }
  }

  if (ref->prioridade < f->heap[big]->prioridade)
  {
    PONT aux = f->heap[big];
    int posAux = ref->posicao;

    f->heap[big] = ref;
    ref->posicao = big;

    f->heap[posAux] = aux;
    aux->posicao = posAux;

    Reordenar(f, ref);
  }
}

PONT removerElemento(PFILA f)
{
  PONT res = NULL;


  if (f->elementosNoHeap == 0)
    return res;

  res = f->heap[0];
  f->heap[0] = f->heap[f->elementosNoHeap - 1];
  f->heap[0]->posicao = 0;

  f->heap[f->elementosNoHeap - 1] = NULL;
  (f->elementosNoHeap = f->elementosNoHeap - 1);
  f->arranjo[res->id] = NULL;

  PONT ref = f->heap[0];

  Reordenar(f, ref);

  return res;
}



bool consultarPrioridade(PFILA f, int id, float *resposta)
{
  bool res = false;

  if (id < 0 || id >= f->maxElementos - 1)
  {
    return res;
  }

  PONT elemento = f->arranjo[id];
  if (elemento == NULL)
  {
    return res;
  }


  *resposta = elemento->prioridade;

  res = true;

  return res;
}

