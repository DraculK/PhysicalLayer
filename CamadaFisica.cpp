void CamadaFisicaTransmissora (int quadro[]) {
	int tipoDeCodificacao = 0;
	int fluxoBrutoDeBits [];

	switch (tipoDeCodificacao) {
		case 0:
			fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoBinaria(quadro);
			break;
		case 1:
			fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoManchester(quadro);
			break;
		case 2:
			fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoBipolar(quadro);
			break;
	}

	MeioDeComunicacao(fluxoBrutoDeBits);
}

int [] CamadaFisicaTransmissoraCodificacaoBinaria (int quadro[]) {
	//implementar método
}

int [] CamadaFisicaTransmissoraCodificacaoManchester (int quadro[]) {
	//implementar método
}

int [] CamadaFisicaTransmissoraCodificacaoBipolar (int quadro[]) {
	//implementar método
}

void MeioDeComunicacao (int fluxoBrutoDeBits []) {
	int fluxoBrutoDeBitsPontoA[], fluxoBrutoDeBitsPontoB;

	fluxoBrutoDeBitsPontoA = fluxoBrutoDeBits;

	while (fluxoBrutoDeBitsPontoB.lenght != fluxoBrutoDeBitsPontoA) {
		fluxoBrutoDeBitsPontoB += fluxoBrutoDeBitsPontoA;
	}

	CamadaFisicaReceptora(fluxoBrutoDeBitsPontoB);
}

void CamadaFisicaReceptora (int quadro[]) {
	int tipoDeCodificacao = 0;
	int fluxoBrutoDeBits [];

	switch (tipoDeCodificacao) {
		case 0:
			fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoBinaria(quadro);
			break;
		case 1:
			fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoManchester(quadro);
			break;
		case 2:
			fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoBipolar(quadro);
			break;
	}

	CamadaDeAplicacaoReceptora(fluxoBrutoDeBits);
}

int [] CamadaFisicaReceptoraCodificacaoBinaria (int quadro[]) {
	//implementar método
}

int [] CamadaFisicaReceptoraCodificacaoManchester (int quadro[]) {
	//implementar método
}

int [] CamadaFisicaReceptoraCodificacaoBipolar (int quadro[]) {
	//implementar método
}

void CamadaDeAplicacaoReceptora (int quadro[]) {
	AplicacaoReceptora(mensagem);
}

void AplicacaoReceptora (string mensagem) {
	cout << "A mensagem recebida foi: " << mensagem <<endl;
}