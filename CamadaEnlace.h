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

int intXor(int, int);

vector<int> CamadaEnlaceDadosTransmissoraControleDeErroCRC(vector<int>);

vector<int> CamadaEnlaceDadosTransmissoraControleDeErroCodigoDeHamming(vector<int>);

std::vector<int> CamadaEnlaceDadosTransmissoraControleDeErroBitParidadePar(std::vector<int> quadro);

std::vector<int> CamadaEnlaceDadosTransmissoraControleDeErroBitParidadeImpar(std::vector<int> quadro);

std::vector<int> CamadaEnlaceDadosReceptoraControleDeErroCRC(std::vector<int> quadro);

std::vector<int> CamadaEnlaceDadosReceptoraControleDeErroCodigoDeHamming(std::vector<int> quadro);

bool CheckParidadeQuadro(std::vector<int> quadro);

int intXor(int numero0, int numero1);

