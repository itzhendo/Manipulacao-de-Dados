#include "professor.h"

QString Professor::getMatricula() const
{
    return matricula;
}

void Professor::setMatricula(QString value)
{
    matricula = value;
}

QString Professor::getNome() const
{
    return nome;
}

void Professor::setNome(const QString &value)
{
    nome = value;
}

QString Professor::getDepartamento() const
{
    return departamento;
}

void Professor::setDepartamento(const QString &value)
{
    departamento = value;
}

QString Professor::getTitulacao() const
{
    return titulacao;
}

void Professor::setTitulacao(const QString &value)
{
    titulacao = value;
}

QString Professor::getTipoDeContrato() const
{
    return tipoDeContrato;
}

void Professor::setTipoDeContrato(const QString &value)
{
    tipoDeContrato = value;
}

Professor::Professor()
{

}
