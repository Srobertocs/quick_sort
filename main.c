#include <stdio.h>

int particao(int vetor[], int left, int right)
{
  int pivo = vetor[right];
  int i = left - 1;
  int aux;

  for (int j = left; j < right; j++)
  {
    if (vetor[j] <= pivo)
    {
      i++;
      aux = vetor[i];
      vetor[i] = vetor[j];
      vetor[j] = aux;
    }
  }
  aux = vetor[i + 1];
  vetor[i + 1] = vetor[right];
  vetor[right] = aux;

  return i + 1;
}

void quicksort(int vetor[], int left, int right)
{
  if (left < right)
  {
    int pivo = particao(vetor, left, right);
    quicksort(vetor, left, pivo - 1);
    quicksort(vetor, pivo + 1, right);
  }
}

int main()
{
  int vetor[5] = {9, 3, 7, 1, 5};

  quicksort(vetor, 0, 4);

  for (int i = 0; i < 5; i++)
  {
    printf(" %d ", vetor[i]);
  }
}