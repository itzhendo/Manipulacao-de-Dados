#ifndef BUSCAPORNOME_H
#define BUSCAPORNOME_H


#include <metododeordenacao.h>

class BuscaPorNome: public MetodoDeOrdenacao
{
public:
    bool Igual(Professor a, Professor b)const;
    bool maior(Professor a, Professor b)const;
    BuscaPorNome(QString nomeDoArquivoNoDisco);
    BuscaPorNome(MetodoDeOrdenacao* dat);
};


#endif // BUSCAPORNOME_H
