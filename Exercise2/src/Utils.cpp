#include "iostream"
#include "fstream" 
#include "sstream"
#include "iomanip"

#include "Utils.hpp"

using namespace std;

//ImportData permette di importare correttamente i dati.
bool ImportData( const string& iFileName,
				 double& S,
				 size_t& n,
				 double*& w,
				 double*& r )			 
{
	
	// Apro il file.
	ifstream file(iFileName);
	
	//Controllo che l'apertura sia andata a buon fine.
	if ( file.fail() ) {
		cerr << "Opening file attempt failed." << endl;
		return false;
	}
	
	string line;
	
	//Leggo S somma totale investita.
	while ( !file.eof() ) {
		getline(file, line);
		// Salto eventuali righe di commento (che iniziano con il char #).
		if ( line[0] != '#' )
				break; 
	}
	stringstream convertS(line);
	string tmp; //Creo una stringa temporanea che userò per memorizzare stringhe che non mi interessano.
	getline(convertS, tmp, ';'); //Leggo e "scarto" 'S;'
	convertS >> S;
	
	//Leggo n numero di asset.
	while ( !file.eof() ) {
		getline(file, line);
		// Salto eventuali righe di commento.
		if ( line[0] != '#' )
				break; 
	}
	stringstream convertN(line);
	getline(convertN, tmp, ';'); //Leggo e "scarto" 'n;'
	convertN >> n;
	
	
	//Possibile chack su n (se non sto  investendo non ha senso procedere).
	if (n == 0) {
		cerr << "n is 0. We are not currently investing in any assets." << endl;
		return false;
	}
	
	
	getline(file, line); //Leggo "w;r" e non ci faccio niente
	
	/*Ricavo il  vettore w (contenente le frazioni di capitale investito in ciascun asset)
	e il vettore r contente i tassi di ritorno degli asset.*/
	w = new double[n];
	r = new double[n];
	for ( size_t i = 0; i < n && !file.eof(); i++ ) {
		getline(file, line);
		stringstream convertWR(line);
		convertWR >> w[i];
		convertWR.ignore();
		convertWR >> r[i];
	}
	
	//Chiudo il file.
	file.close();
	
	return true;
};


//RateOfReturn calcola il tasso di rendita complessivo dell'investimento fatto.
double RateOfReturn( const double* const& w,
					 const double* const& r,
					 const size_t& n )
{
	double RRate = 0.0;
	for (size_t i = 0; i < n; i++)
		RRate += w[i]*r[i];
	
	return RRate;
};


//FinalValue calcola il valore finale del portafoglio.
double FinalValue( const double& S, const double& R ) 
{
	double V = (1+R)*S;
	return V;
};


//ExportResult produce correttamente l'output.
bool ExportResult( const string& oFileName,
				   const double& S,
				   const size_t& n,
				   const double* const& w,
				   const double* const& r,
				   const double& R,
				   const double& V )
{
	//Apro il file.
	ofstream file(oFileName);
	
	//Controllo che l'apertura del file sia andata a buon fine.
	if ( file.fail() ) {
		cerr << "Opening file attempt failed." << endl;
		return false;
	}
	
	//Inizio a stampare.
	file << fixed;
	
	file << "S = " << setprecision(2) << S << ", n = " << n << endl;
	
	file << "w = [ ";
	for ( size_t i = 0; i < n; i++ )
		file << w[i] << " ";
	file << "]" << endl;
	
	file << "r = [ ";
	for ( size_t j = 0; j < n; j++ )
		file << r[j] << " ";
	file << "]" << endl;
	
	file << "Rate of return of the portfolio: " << setprecision(4) << R << endl;
	
	file << "V: " << setprecision(2) << V << endl;
	
	
	//Chiudo il file.
	file.close();
	
	return true;
};