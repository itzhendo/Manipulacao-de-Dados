#include "buscapormatricula.h"

BuscaPorMatricula::BuscaPorMatricula(QString nomeDoArquivoNoDisco):
    MetodoDeOrdenacao(nomeDoArquivoNoDisco)
{
}
BuscaPorMatricula::BuscaPorMatricula(MetodoDeOrdenacao* dat):
    MetodoDeOrdenacao(dat)
{
}

bool BuscaPorMatricula::Igual(Professor a, Professor b)const
{
    if(a.getMatricula() == b.getMatricula()) return true;
    return false;
}

bool BuscaPorMatricula::maior(Professor a, Professor b)const
{
    if(a.getMatricula().toInt() > b.getMatricula().toInt()) return true;
    return false;
}

