#include <stdio.h>
#include <math.h>

void KBeMB (int , double *, double *);

int main()
{
    int bytes;
    double kb, mb;

    printf("Digite o tamanho do arquivo em bytes: ");
    scanf("%d", &bytes);

    KBeMB(bytes, &kb, &mb);

    printf("O tamanho desse arquivo de %d bytes em KB e': %lf / em MB e': %lf\n", bytes, kb, mb);

}

void KBeMB(int bytes, double * pKB, double * pMB)
{
    *pKB = bytes / pow(2, 10);
    *pMB = bytes / pow(2, 20);
}