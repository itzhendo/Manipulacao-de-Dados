#include "metododeordenacao.h"

MetodoDeOrdenacao::MetodoDeOrdenacao(QString nomeDoArquivoNoDisco):
    dados(0),
    tam(0)
{
  try
  {
      DadosDoArquivo aux(nomeDoArquivoNoDisco);
      dados = aux.obterDadosDoArquivo(); //retorna o vetor de dados do arquivo
      tam = aux.getTamanhoDoArquivo() - aux.getTamDoErro();
      tamErro =  aux.getTamDoErro();
  }
  catch (QString &erro)
  {
      throw erro;
  }
}

MetodoDeOrdenacao::MetodoDeOrdenacao(MetodoDeOrdenacao* dat)
{
    dados=dat->getDados();
    tam=dat->getTam();

}

void MetodoDeOrdenacao::ordenar()
{
    int i, j;
    for(i = 1; i < tam; i++)
    {
        Professor troca = dados[i];
        for( j = i-1; j >=0  && maior(dados[j],troca); j--)
            dados[j+1] = dados[j];
        dados[j+1] = troca;
    }
}
int MetodoDeOrdenacao::buscaSequencial(Professor buscado)const
{
    for(int i=0;i<tam;i++)
    {
        if(Igual(buscado, dados[i])) return i;
    }
    return -1;
}
int MetodoDeOrdenacao::buscaBinaria(Professor buscado, int inicio, int fim)const//recursiva
{   
     int meio;
     if(inicio<=fim)
     {
         meio = (inicio + fim)/2;
         if(Igual(buscado, dados[meio]))
             return meio;
         else
         {
             if(maior(buscado , dados[meio]))
                 return buscaBinaria(buscado, meio+1, fim);
             else
                 return buscaBinaria(buscado, inicio, meio-1);
         }
     }
     return -1;
}

