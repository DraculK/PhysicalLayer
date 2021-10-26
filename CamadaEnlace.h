#include "CamadaFisica.h"
#include "CamadaAplicacao.h"

//TRANSMISSÃO
void CamadaEnlaceDadosTransmissora(vector<int>); //feito

vector<int> CamadaEnlaceDadosTransmissoraEnquadramento (vector<int>); //feito

vector<int> CamadaEnlaceDadosTransmissoraControleDeErro(vector<int>);

vector<int> CamadaEnlaceDadosTransmissoraEnquadramentoContagemDeCaracteres(vector<int>); //feito.

void InsereByte(vector<int> *vetor, unsigned char byte);

vector<int> CamadaEnlaceDadosTransmissoraEnquadramentoInsercaoDeBytes(vector<int>);

//RECEPÇÃO
void CamadaEnlaceDadosReceptora(vector<int>); //feito.

vector<int> CamadaEnlaceDadosReceptoraEnquadramento(vector<int>);

vector<int> CamadaEnlaceDadosReceptoraControleDeErro(vector<int>);

vector<int> CamadaEnlaceDadosReceptoraEnquadramentoContagemDeCaracteres(vector<int>);

vector<int> CamadaEnlaceDadosReceptoraEnquadramentoInsercaoDeBytes(vector<int>);

vector<int> CamadaEnlaceDadosReceptoraControleDeErroBitParidadeImpar(vector<int>);