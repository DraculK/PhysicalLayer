#include "CamadaFisica.h" 

//TRANSMISSÃO
void CamadaEnlaceDadosTransmissora(vector<int>);

vector<int> CamadaEnlaceDadosTransmissoraEnquadramento (vector<int>);

vector<int> CamadaEnlaceDadosTransmissoraControleDeErro(vector<int>);

vector<int> CamadaEnlaceDadosTransmissoraEnquadramentoContagemDeCaracteres(vector<int>);

vector<int> CamadaEnlaceDadosTransmissoraEnquadramentoInsercaoDeBytes(vector<int>);

//RECEPÇÃO
void CamadaEnlaceDadosReceptora(vector<int>);

vector<int> CamadaEnlaceDadosReceptoraEnquadramento(vector<int>);

vector<int> CamadaDeEnlaceReceptoraControleDeErro(vector<int>);

vector<int> CamadaEnlaceDadosReceptoraEnquadramentoContagemDeCaracteres(vector<int>);

vector<int> CamadaEnlaceDadosReceptoraEnquadramentoInsercaoDeBytes(vector<int>);