#ifndef BUSCAPORMATRICULA_H
#define BUSCAPORMATRICULA_H

#include <metododeordenacao.h>

class BuscaPorMatricula: public MetodoDeOrdenacao
{
public:
    bool Igual(Professor a, Professor b)const;
    bool maior(Professor a, Professor b)const;
    BuscaPorMatricula(QString nomeDoArquivoNoDisco);
    BuscaPorMatricula(MetodoDeOrdenacao* dat);
};

#endif // BUSCAPORMATRICULA_H
