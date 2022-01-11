#ifndef ORDERDEPARTAMENTOTITULACAONOME_H
#define ORDERDEPARTAMENTOTITULACAONOME_H
#include<metododeordenacao.h>

class OrderDepartamentoTitulacaoNome:public MetodoDeOrdenacao
{
public:
    bool Igual(Professor a, Professor b)const;
    bool maior(Professor a, Professor b)const;
    OrderDepartamentoTitulacaoNome(QString nomeDoArquivoNoDisco);
    OrderDepartamentoTitulacaoNome(MetodoDeOrdenacao* dat);
};

#endif // ORDERDEPARTAMENTOTITULACAONOME_H
