#include "CamadaFisica.hpp"

void CamadaFisicaTransmissora(vector<int> quadro) {
  int tipoDeCodificacao = 0;
  vector<int> fluxoBrutoDeBits;

  switch(tipoDeCodificacao) {
    case 0: //codificacao binaria
      fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoBinaria(quadro);
      break;
    case 1: //codificacao manchester
      fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoManchester(quadro);
      break;
    case 2: //codificacao bipolar
      fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoBipolar(quadro);
      break;
  }
  MeioDeComunicacao(fluxoBrutoDeBits)
}

vector<int> CamadaFisicaTransmissoraCodificacaoBinaria(vector<int> quadro){

}

vector<int> CamadaFisicaTransmissoraCodificacaoManchester(vector<int> quadro){
	
}

vector<int> CamadaFisicaTransmissoraCodificacaoBipolar(vector<int> quadro){
	
}

void MeioDeComunicacao (vector<int> fluxoBrutoDeBits) {
	vector<int> fluxoBrutoDeBitsPontoA;
	vector<int> fluxoBrutoDeBitsPontoB;

	while(i = 0; i< fluxoBrutoDeBitsPontoA.size(); i++){
		fluxoBrutoDeBitsPontoB.push_back(fluxoBrutoDeBitsPontoA.at(i));
	}

	CamadaFisicaReceptora(fluxoBrutoDeBitsPontoB);
}

void CamadaFisicaReceptora (vector<int> quadro) {
	int tipoDeCodificacao = 0;
	vector<int> fluxoBrutoDeBits;

	switch (tipoDeCodificacao) {
		case 0:
			fluxoBrutoDeBits = CamadaFisicaReceptoraCodificacaoBinaria(quadro);
			break;
		case 1:
			fluxoBrutoDeBits = CamadaFisicaReceptoraCodificacaoManchester(quadro);
			break;
		case 2:
			fluxoBrutoDeBits = CamadaFisicaReceptoraCodificacaoBipolar(quadro);
			break;
	}

	CamadaDeAplicacaoReceptora(fluxoBrutoDeBits);
}

vector<int> CamadaFisicaReceptoraCodificacaoBinaria(vector<int> quadro){

}

vector<int> CamadaFisicaReceptoraCodificacaoManchester(vector<int> quadro){

}

vector<int> CamadaFisicaTransmissoraCodificacaoBipolar(vector<int> quadro){

}

void CamadaDeAplicacaoReceptora (int quadro[]) {
	AplicacaoReceptora(mensagem);
}

void AplicacaoReceptora (string mensagem) {
	cout << "A mensagem recebida foi: " << mensagem <<endl;
}