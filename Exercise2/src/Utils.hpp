#pragma once

using namespace std;

//ImportData importa corettamente i dati.
bool ImportData( const string& iFileName,
				 double& S,
				 size_t& n,
				 double*& w,
				 double*& r );

//RateOfReturn calcola il tasso di rendita globale dell'investimento fatto.				 
double RateOfReturn( const double* const& w,
					 const double* const& r,
					 const size_t& n );

//FinalValue calcola il valore finale del portafoglio.
double FinalValue( const double& S, const double& R );

//ExportResult produce correttamente l'output.
bool ExportResult( const string& oFileName,
				   const double& S,
				   const size_t& n,
				   const double* const& w,
				   const double* const& r,
				   const double& R,
				   const double& V );