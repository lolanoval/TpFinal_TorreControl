#include "cTorreControl.h"

cTorreControl::cTorreControl()
{
	ListaAviones = new cLista<cAvion>();
	Pistas = new ListaPistas();
}

cTorreControl::cTorreControl(cLista<cAvion>* _ListaAviones, ListaPistas* _Pistas)
{
	ListaAviones = new cLista<cAvion>();
	Pistas = new ListaPistas();
	try
	{
		this->ListaAviones = _ListaAviones;
		this->Pistas = _Pistas;
	}
	catch (exception* e)
	{
		cout << string(e->what()) << endl;
		delete e;
	}
	/*this->ListaAviones = new cLista<cAvion>;
	for (int i = 0; i < _ListaAviones->getCA(); i++)
	{
		(*ListaAviones) + (*_ListaAviones)[i];
	}
	this->Pistas = new cLista<cPista>;
	for (int i = 0; i < _Pistas->getCA(); i++)
	{
		(*Pistas) + (*_Pistas)[i];
	}*/
}

cTorreControl::~cTorreControl()
{
	//if (ListaAviones != NULL)
	//{
	//	delete ListaAviones;
	//}
	//if (Pistas != NULL)
	//{
	//	delete Pistas;
	//}
	delete ListaAviones;
	delete Pistas;
}

cPista* cTorreControl::AsignarPista(cAvion* avion) //try catch
{
	if (avion == NULL)
		throw new exception("Puntero nulo");
	int pos = ListaAviones->getItemPos(avion);
	if (pos == -1)
	{
		throw new exception("El avion no se encuentra en el sistema");
	}
		int tamanio = avion->getTam();
		float distancia = avion->Distancia();
		//cLista<cPista>* subLista = subListaPistasLibres();
		int i = 0;
		for (i = 0; i < Pistas->getCA() + 1; i++)
		{
			if ((*Pistas)[i]->getDistancia() <= distancia && (*Pistas)[i]->getTamanio() <= tamanio && (*Pistas)[i]->getOcupada() == false)
			{
				return (*Pistas)[i];
				//cPista* pistaLibre = (*subLista)[i]; //ver si xq se elimina la subLista no se elimina el puntero; en ese caso hay que crear un new 
				//delete subLista;
				//return pistaLibre;
			}
		}
		//delete subLista;
		if (i == Pistas->getCA() + 1)
			throw new exception("No hay pistas libres");
}

void cTorreControl::ImprimirAvionesEnVuelo()
{
	for (int i = 0; i < ListaAviones->getCA(); i++)
	{
		if (EstadoToString((*ListaAviones)[i]->getEstado()) == "Volando")
			(*ListaAviones)[i]->ImprimirDatos();
	}
}

void cTorreControl::ImprimirAvionesAterrizando()
{
	for (int i = 0; i < ListaAviones->getCA(); i++)
	{
		if (EstadoToString((*ListaAviones)[i]->getEstado()) == "Aterrizando")
			(*ListaAviones)[i]->ImprimirDatos();
	}
}

void cTorreControl::ImprimirAvionesDespegando()
{
	for (int i = 0; i < ListaAviones->getCA(); i++)
	{
		if (EstadoToString((*ListaAviones)[i]->getEstado()) == "Despegando")
			(*ListaAviones)[i]->ImprimirDatos();
	}
}

void cTorreControl::ImprimirPistasLibres()
{
	Pistas->Listar();
	//int j = Pistas->getCA();
	//for (int i = 0; i < j; i++)
	//{
	//	//if ((*Pistas)[i]->getOcupada() == false)
	//	//Pistas[i]->ImprimirDatos();
	//}
}

void cTorreControl::DespegarAvion(cAvion* avion)
{
	try
	{
		AsignarPista(avion);
	}
	catch (exception* e)
	{
		cout << string(e->what()) << endl;
		delete e;
	}
	avion->Despegar(AsignarPista(avion));

}

void cTorreControl::AterrizarAvion(cAvion* avion)
{
	try
	{
		AsignarPista(avion);
	}
	catch (exception* e)//chequear esto si era asi
	{
		cout << e->what() << endl;
		delete e;
	}
	avion->Aterrizar(AsignarPista(avion)); 
}

float cTorreControl::TiempoOcupacionPista(cAvion* avion)
{
	return NULL;
}

//otra prueba:
//cLista<cPista>* cTorreControl::subListaPistasLibres()
//{
//	cLista<cPista>* subLista = new cLista<cPista>;
//	for (int i = 0; i < Pistas->getCA(); i++)
//	{
//		if ((*Pistas)[i]->getOcupada() == false)
//		{
//			(*subLista) + (*Pistas)[i];
//		}
//	}
//	return subLista;
//}

bool cTorreControl::AgregarPista(cPista* pista)
{
	return (*Pistas) + pista;
}

bool cTorreControl::AgregarAvion(cAvion* avion)
{
	return (*ListaAviones) + avion;
}

