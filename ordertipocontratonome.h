#ifndef ORDERTIPOCONTRATONOME_H
#define ORDERTIPOCONTRATONOME_H
#include<metododeordenacao.h>

class OrderTipoContratoNome:public MetodoDeOrdenacao
{
public:
    bool Igual(Professor a, Professor b)const;
    bool maior(Professor a, Professor b)const;
    OrderTipoContratoNome(QString nomeDoArquivoNoDisco);
    OrderTipoContratoNome(MetodoDeOrdenacao* dat);
};

#endif // ORDERTIPOCONTRATONOME_H
