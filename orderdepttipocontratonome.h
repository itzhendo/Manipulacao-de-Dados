#ifndef ORDERDEPTTIPOCONTRATONOME_H
#define ORDERDEPTTIPOCONTRATONOME_H
#include<metododeordenacao.h>

class OrderDeptTipoContratoNome: public MetodoDeOrdenacao
{
public:
    bool Igual(Professor a, Professor b)const;
    bool maior(Professor a, Professor b)const;
    OrderDeptTipoContratoNome(QString nomeDoArquivoNoDisco);
    OrderDeptTipoContratoNome(MetodoDeOrdenacao* dat);
};

#endif // ORDERDEPTTIPOCONTRATONOME_H
