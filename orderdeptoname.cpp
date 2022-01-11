#include "orderdeptoname.h"

orderDeptoName::orderDeptoName(QString nomeDoArquivoNoDisco):
    MetodoDeOrdenacao(nomeDoArquivoNoDisco)
{
}
orderDeptoName::orderDeptoName(MetodoDeOrdenacao* dat):
    MetodoDeOrdenacao(dat)
{
}

bool orderDeptoName::Igual(Professor a, Professor b)const
{
    if(a.getDepartamento() == b.getDepartamento() && a.getNome() == b.getNome()) return true;
    return false;
}

bool orderDeptoName::maior(Professor a, Professor b)const
{
    if(a.getDepartamento() > b.getDepartamento())return true;
    if(a.getDepartamento() == b.getDepartamento() && a.getNome() > b.getNome())return true;
    return false;
}
