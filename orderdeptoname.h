#ifndef ORDERDEPTONAME_H
#define ORDERDEPTONAME_H
#include<metododeordenacao.h>

class orderDeptoName:public MetodoDeOrdenacao
{
public:
    bool Igual(Professor a, Professor b)const;
    bool maior(Professor a, Professor b)const;
    orderDeptoName(QString nomeDoArquivoNoDisco);
    orderDeptoName(MetodoDeOrdenacao* dat);
};

#endif // ORDERDEPTONAME_H
