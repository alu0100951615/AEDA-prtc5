#pragma once
#include <iostream>
#include <vector>

using namespace std;

void update_data(int comparaciones, int& min, int& max, int& med)
{
	if (min == -1) min = comparaciones;
	else if (comparaciones < min) min = comparaciones;

	if (max == -1) max = comparaciones;
	else if (comparaciones > max) max = comparaciones;

	med += comparaciones;

}

template<class T>
void print_it(const vector<T>& seq, int a = -1, int b = -1)
{
	for (int i = 0; i < seq.size(); i++)
	{
		if ((i == a) || (i == b)) {
			cout << " *";
			seq[i].write(cout);
			//seq[i].write(cout);
			cout<< "* ";
		}
		else {
			cout << "  ";
			seq[i].write(cout);
			//seq[i].write(cout);
			cout<< "  ";
		}
	}
	cout << endl;
}

template<class T>
void insercion(vector<T>& seq, int mode)
{

	
	
		
		T actual;
		int j = 1;
		for (int i = 1; i < seq.size(); i++) {
			
			actual = seq[i];
			for (j = i; j > 0 && seq[j - 1] > actual; j--) {
				seq[j] = seq[j - 1];
			}
			seq[j] = actual;
			if (mode == 1) {
				print_it(seq, i, j);
				cout << endl;
			}
		}
		
	

}

template<class T>
void sacudida(vector<T>& seq, int mode)
{
	int ini = 1;
	int fin = seq.size() - 1;
	int cam = seq.size();

	bool cambio = 1;

	while ((ini <= fin) && cambio)
	{
		cambio = 0;

		for (int j = fin; j >= ini; j--)
		{
			if (seq[j] < seq[j - 1])
			{
				cambio = 1;
				if (mode == 1) { cout << "< "; print_it(seq, j, j - 1); }

				T x = seq[j - 1];
				seq[j - 1] = seq[j];
				seq[j] = x;
				cam = j;
			}
		}

		ini = cam + 1;
		for (int j = ini; j <= fin; j++)
		{
			if (seq[j] < seq[j - 1])
			{
				cambio = 1;
				if (mode == 1) { cout << "> "; print_it(seq, j, j - 1); }

				T x = seq[j - 1];
				seq[j - 1] = seq[j];
				seq[j] = x;
				cam = j;
			}
		}
		fin = cam - 1;

	}

	if (mode == 1) { cout << "> "; print_it(seq); }
}

template<class T>
void heapSort(vector<T>& seq, int mode)
{
		for (int i = seq.size() / 2 -1; i >= 0; i--)
			baja(i, seq, seq.size(), mode);
		for (int i = seq.size()-1 ; i >= 0; i--){
			T x = seq[0];
			seq[0] = seq[i];
			seq[i] = x;
			baja(0, seq, i, mode);
		}
		if (mode == 1)
			print_it(seq);
}

template<class T>
void baja(int i, vector<T>& seq, int n, int mode)
{
	int h = i; 
	int h1 = 2 * i + 1;  
	int h2 = 2 * i + 2;

						
	if (h1 < n && seq[h1] > seq[h])
		h = h1;

	
	if (h2 < n && seq[h2] > seq[h])
		h = h2;

	
	if (h != i)
	{
		if (mode == 1)
			print_it(seq, i, h);
		T x = seq[i];
		seq[i] = seq[h];
		seq[h] = x;
		if (mode == 1) {
			print_it(seq, i, h); cout << endl;
		}
		baja( h, seq, n, mode);
	}

}

template<class T>
void fusionar(vector<T>& X, vector<T>& Y, vector<T>& seq)
{
	int k = 0;
	int a = 0;
	int b = 0;

	while ((k < seq.size()) && (a != X.size()) && (b != Y.size()))
	{
		if (X[a] < Y[b])
		{
			seq[k++] = X[a++];
		}
		else
			seq[k++] = Y[b++];
	}

	// Si se acabó X relleno con Y
	if ((a >= X.size()) && (k<seq.size()))
	{
		while (seq.size() != k)
			seq[k++] = Y[b++];
	}

	// Si se acabó Y relleno con X
	if ((b >= Y.size()) && (k<seq.size()))
	{
		while (seq.size() != k)
			seq[k++] = X[a++];
	}
}



template<class T>
void quickSort(vector<T>& seq, int mode, int ini, int fin)
{

	int i = ini;
	int f = fin;
	T p = seq[(i + f) / 2];


	if (mode == 1)
	{
		cout << "-------" << endl;
		cout << "ini #" << i + 1 << endl;
		cout << "fin #" << f + 1 << endl;
		cout << "Pivote #" << ((i + f) / 2) + 1 << endl;
	}

	while (i <= f)
	{
		while (seq[i] < p) i++;
		while (p < seq[f]) f--;

		if (mode == 1) { cout << '\t'; print_it(seq, i, f); }

		if (i <= f)
		{
			T x = seq[i];
			seq[i] = seq[f];
			seq[f] = x;
			i++; f--;
		}
	}

	if (ini < f) quickSort(seq, mode, ini, f);
	if (i < fin) quickSort(seq, mode, i, fin);

}

template<class T>
void incDec(vector<T>& seq, int mode, double alfa)
{

	double del = (double)seq.size();
	while (del > 1)
	{
		del = del * alfa;
		deltasort(seq, mode, del);
		if (mode == 1) print_it(seq);
	}

}

template<class T>
void deltasort(vector<T>& seq, int mode, double del)
{
	for (int i = round(del); i < seq.size(); i++)
	{
		T x = seq[i];
		double j = (double)i;

		while ((j >= del) && (x < seq[round(j - del)]))
		{
			seq[round(j)] = seq[round(j - del)];
			j = j - del;
		}

		seq[round(j)] = x;

	}
}

