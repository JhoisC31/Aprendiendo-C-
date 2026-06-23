#include "Pila.h"

Pila::Pila(): _ultimo(NULL)
{
}

void Pila::Agregar(Elemento* elemento)
{
    elemento->SetSiguiente(_ultimo);
    _ultimo = elemento;
}

Elemento* Pila::Extraer()
{
    Elemento* tope = _ultimo;
    _ultimo = (_ultimo != NULL) ? _ultimo->GetSiguiente() : NULL;
    (tope != NULL) ? tope->SetSiguiente(NULL) : void();

    return tope;
}