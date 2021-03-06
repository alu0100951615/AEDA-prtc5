// Practica5.cpp: define el punto de entrada de la aplicación de consola.
//

#include <iostream>
#include <vector>

#include "FuncionesOrdenacion.hpp"
#include "DNI.h"

int DNI::comparaciones_ = 0;

void result(int min, int max, int med, int p);
int main(void)
{
	srand(5646354);



	int opcion = 0;
	do
	{
		system("@cls");
		std::cout << "1 - Modo desmostracion" << std::endl;
		std::cout << "2 - Modo estadistica" << std::endl;
		std::cout << std::endl << ">> ";
		std::cin >> opcion;

	} while ((opcion != 1) && (opcion != 2));

	// Modo demostración
	if (opcion == 1)
	{
		system("@cls");
		std::cout << "~ Modo demostración ~" << std::endl << std::endl;

		int n, a;


		// Solicita parámetros ~~~~~~~~~~~~~~~~~~~~~~
		do
		{
			std::cout << "Tamaño de la secuencia a ordenar (max 25) >> ";
			std::cin >> n;
			std::cout << std::endl;

		} while ((n<1) || (n>25));

		do
		{
			std::cout << "Algoritmo a ejecutar: " << std::endl;
			std::cout << " 1 - Insercion" << std::endl;
			std::cout << " 2 - Por intercambio: Metodo de la sacudida" << std::endl;
			std::cout << " 3 - HeapSort" << std::endl;
			std::cout << " 4 - QuickSort" << std::endl;
			std::cout << " 5 - Por incrementos decrecientes" << std::endl << std::endl;
			std::cout << ">> ";
			std::cin >> a;

		} while ((a<1) || (a>5));


		// Crear vector ~~~~~~~~~~~~~~~~~~~~~~
		vector<DNI> seq(n);

		std::cout << "Secuencia original: " << std::endl;
		print_it(seq);
		std::cout << std::endl;


		// Ordenar mediante el método insercionado ~~~~~~~~~~~~~~~~~~~~~~~
		switch (a)
		{
		case 1:
			insercion(seq, 1);
			break;
		case 2:
			sacudida(seq, 1);
			break;
		case 3:
			heapSort(seq, 1);
			break;
		case 4:
			quickSort(seq, 1, 0, seq.size() - 1);
			std::cout << '\t'; print_it(seq);
			break;
		case 5:
			double alfa;
			cout << "Constante de reduccion alfa (0-1) >> ";
			cin >> alfa;
			incDec(seq, 1, alfa);
			break;
		}

	}

	// Modo estadística
	else
	{
		system("@cls");
		std::cout << "~ Modo estadistica ~" << std::endl << std::endl;

		int n, p;


		// Solicitar parametros ~~~~~~~~~~~~~~~~~~~~~~
		do
		{
			std::cout << "Tamaño de la secuencia a ordenar >> ";
			std::cin >> n;

		} while (n<1);

		do
		{
			std::cout << "Numero de pruebas a realizar >> ";
			std::cin >> p;
			std::cout << std::endl;

		} while (p<1);


		// Calcular estadísticas ~~~~~~~~~~~~~~~~~~~~~~

		// 1 Selección

		int min = -1, max = -1, med = 0;
		int counter = 0;

		while (counter < p)
		{
			DNI::comparaciones_ = 0;

			vector<DNI> seq(n);
			insercion(seq, 2);

			update_data(DNI::comparaciones_, min, max, med);
			counter++;
		}

		std::cout << "Insercion:" << std::endl;
		result(min, max, med, p);


		// 2 Sacudida

		min = -1; max = -1; med = 0;
		counter = 0;

		while (counter < p)
		{
			DNI::comparaciones_ = 0;

			vector<DNI> seq(n);
			sacudida(seq, 2);

			update_data(DNI::comparaciones_, min, max, med);
			counter++;
		}

		std::cout << "Sacudida:" << std::endl;
		result(min, max, med, p);

		// 3 MergeSort

		min = -1; max = -1; med = 0;
		counter = 0;

		while (counter < p)
		{
			DNI::comparaciones_ = 0;

			vector<DNI> seq(n);
			heapSort(seq, 2);

			update_data(DNI::comparaciones_, min, max, med);
			counter++;
		}

		std::cout << "HeapSort:" << std::endl;
		result(min, max, med, p);

		// 4 QuickSort

		min = -1, max = -1, med = 0;
		counter = 0;

		while (counter < p)
		{
			DNI::comparaciones_ = 0;

			vector<DNI> seq(n);
			quickSort(seq, 2, 0, seq.size() - 1);

			update_data(DNI::comparaciones_, min, max, med);
			counter++;
		}

		std::cout << "QuickSort" << std::endl;
		result(min, max, med, p);

		// 5 Incrementos decrecientes

		min = -1, max = -1, med = 0;
		counter = 0;

		double alfa;
		cout << "Constante de reduccion alfa (0-1) >> ";
		cin >> alfa;

		while (counter < p)
		{
			DNI::comparaciones_ = 0;

			vector<DNI> seq(n);
			incDec(seq, 2, alfa);

			update_data(DNI::comparaciones_, min, max, med);
			counter++;
		}

		std::cout << "Incrementos Decrecientes: " << std::endl;
		result(min, max, med, p);
	}
}




void result(int min, int max, int med, int p)
{
	std::cout << "min " << min << ", max " << max << ", media " << (float)med / (float)p << std::endl;
}