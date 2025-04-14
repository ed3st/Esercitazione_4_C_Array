#include <iostream>
#include <fstream> 
#include <sstream>

#include "Utils.hpp"

using namespace std;

int main()
{
	string iFileName = "./data.txt"; //Nome file input.
	string oFileName = "./result.txt"; //Nome file output.
	double Sum;
	size_t n;
	double* Weights = nullptr;
	double* Rates = nullptr;
	
	//Eseguo l'import dei dati.
	if ( !ImportData(iFileName, Sum, n, Weights, Rates) ) {
		cerr << "Somethig went wrong with import from " << iFileName << " ." << endl;
		return 1;
	}
	else {
		cout << "Import successful." << endl;
	}
	
	//Calcolo il tasso di rendimento e il valore finale del portafoglio.
	double TotalRate = RateOfReturn(Weights, Rates, n); 
	double ValuePortfolio = FinalValue(Sum, TotalRate);
	
	//Eseguo l'export dell'output.
	if ( !ExportResult(oFileName, Sum, n, Weights, Rates, TotalRate, ValuePortfolio) ) {
		cerr << "Somethig went wrong with export." << endl;
		return 2;
	}
	else {
		cout << "Export successful." << endl;
	}
	
	delete[] Weights;
	delete[] Rates;
	
    return 0;
}

