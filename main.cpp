#include <stdio.h>
#include <iostream>

using namespace std;

struct Nodo
{
	float valor;
	int fila,col;
	Nodo *sigFila, *sigCol;
};

struct NodoLinea
{
	int nolinea;
	Nodo *cabLinea;
	NodoLinea *sigLinea;
};

class Matriz
{
	private:
		NodoLinea *cabFila;
		NodoLinea *cabColumna;
		int filas, columnas;
	public:
		Matriz();
		Matriz(int,int);
		void cargar();
		void mostrar();
		Matriz operator=(Matriz);
		Matriz operator+(Matriz);
		Matriz operator*(Matriz);
};


Matriz::Matriz(int filas,int columnas)
{
	this->filas=filas;
	this->columnas=columnas;
	cabFila=cabColumna=NULL;
}

Matriz::Matriz()
{
	cabFila=cabColumna=NULL;
}

void Matriz::mostrar()
{
	NodoLinea *tempfila;
	Nodo *temp;
	tempfila=this->cabFila;
	for (int i=0; i<this->filas;i++)
	{
		if (!tempfila) temp=NULL;
		else temp=tempfila->cabLinea;
		cout<<"[ ";
		for (int j=0; j<this->columnas;j++)
			if (!temp) cout<<"0 ";
			else
			{
				if (temp->col==j) cout<<temp->valor<<" ";	
				else
					for (int k=j;k<temp->col;k++)cout<<"0 ";
				temp=temp->sigCol;
			}
		cout<<"]"<<endl;
		if (tempfila) tempfila=tempfila->sigLinea;
	}
}

int main(int argc, char** argv) 
{
	Matriz mat(20,15);
	mat.mostrar();
	system("pause");
	return 0;
}
