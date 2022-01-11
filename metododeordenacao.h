#ifndef METODODEORDENACAO_H
#define METODODEORDENACAO_H
#include <dadosdoarquivo.h>
#include <professor.h>


class MetodoDeOrdenacao
{
private:
    Professor* dados;
    int tam;
    int tamErro;
public:
    MetodoDeOrdenacao(QString nomeDoArquivoNoDisco);
    MetodoDeOrdenacao(MetodoDeOrdenacao* dat);
    virtual bool Igual(Professor a, Professor b)const=0;
    virtual bool maior(Professor a, Professor b)const=0;
    void ordenar();
    int buscaSequencial(Professor buscado)const;
    int buscaBinaria(Professor buscado, int inicio, int fim)const;
    Professor * getDados()const{return dados;}
    int getTam(){return tam;}
    int getTamDoArquivo(){return tamErro;}
};



#endif // METODODEORDENACAO_H
