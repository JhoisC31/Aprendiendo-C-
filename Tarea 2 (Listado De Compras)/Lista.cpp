#include "Lista.h"

Lista::Lista(): _primer(NULL) , _ultimo(NULL)
{
}

/*IMPLEMENTE ESTE METODO
		Dado un objeto de tipo puntero a Elemento agréguelo a la lista.

		Tenga pendiente que el atributo _primer guarda un puntero al primer elemento de la lista y que _ultimo es un puntero al al último elemento de la lista
	*/
void Lista::Agregar(Elemento* elemento)
{
    if (_primer == NULL)
    {
        _primer = elemento;
        _ultimo = elemento;
    }
    else
    {
        _ultimo->SetSiguiente(elemento);
        _ultimo = elemento;
    }
}
/*
	IMPLEMENTE ESTE METODO
	Dado un indice entero elimine el objeto en esa posición.  Ejemplo si el parámetro indice es igual a 0 se eliminará el primer elemento.

	Esta función retorna un booleano,  retorno verdadero si el índice está contenido en la lista.

	Ejemplo, si la lista tiene 4 elementos y se pide eliminar el índice 9 este método retornará falso porque ese índice no está contenido en la lista.
	*/

bool Lista::Eliminar(int indice)
{
    if (_primer == NULL)
        return false;

    Elemento* actual = _primer;
    Elemento* anterior = NULL;
    int i = 0;

    while (actual != NULL)
    {
        if (i == indice)
        {
            if (anterior == NULL)
                _primer = actual->GetSiguiente();
            else
                anterior->SetSiguiente(actual->GetSiguiente());

            delete actual;
            return true;
        }
        anterior = actual;
        actual = actual->GetSiguiente();
        i++;
    }

    return false;
}
