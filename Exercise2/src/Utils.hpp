#pragma once

using namespace std;

/*
ImportData importa corettamente i dati.
	- iFileName è il  path del file di input;
	- S è il valore iniziale del portafoglio;
	- n è il numero di asset su cui si investe;
	- w è il vettore la cui i-esima componente è la frazione di S investita nell'i-esimo asset;
	- r è il vettore dei rendimenti.
*/
bool ImportData( const string& iFileName,
				 double& S,
				 size_t& n,
				 double*& w,
				 double*& r );


/*
RateOfReturn calcola il tasso di rendita globale dell'investimento fatto.
	- n è il numero di asset su cui si investe;
	- w è il vettore la cui i-esima componente è la frazione di S investita nell'i-esimo asset;
	- r è il vettore dei rendimenti.
*/			 
double RateOfReturn( const double* const& w,
					 const double* const& r,
					 const size_t& n );


/*FinalValue calcola il valore finale del portafoglio.
	- S è il valore iniziale del portafoglio;
	- R è il tasso di rendimento totale.
*/
double FinalValue( const double& S, const double& R );


/*
ExportResult produce correttamente l'output.
	- oFileName è il  path del file di output;
	- S è il valore iniziale del portafoglio;
	- n è il numero di asset su cui si investe;
	- w è il vettore la cui i-esima componente è la frazione di S investita nell'i-esimo asset;
	- r è il vettore dei rendimenti;
	- R è il tasso di rendimento totale;
	- V è il valore finale del portafoglio.
*/
bool ExportResult( const string& oFileName,
				   const double& S,
				   const size_t& n,
				   const double* const& w,
				   const double* const& r,
				   const double& R,
				   const double& V );