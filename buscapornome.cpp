#include "buscapornome.h"

BuscaPorNome::BuscaPorNome(QString nomeDoArquivoNoDisco):
    MetodoDeOrdenacao(nomeDoArquivoNoDisco)
{
}
BuscaPorNome::BuscaPorNome(MetodoDeOrdenacao* dat):
    MetodoDeOrdenacao(dat)
{
}

bool BuscaPorNome::Igual(Professor a, Professor b)const
{

    if(a.getNome() == b.getNome()) return true;
    return false;

}
bool BuscaPorNome::maior(Professor a, Professor b)const
{
    if(a.getNome().toStdString() > b.getNome().toStdString()) return true;
    return false;
}
