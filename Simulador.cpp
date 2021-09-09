void main (void) {
	AplicacaoTransmissora();
}

void AplicacaoTransmissora (void) {
	string mensagem;
	cout << "Digite uma mensagem: " << endl;
	cin >> mensagem;

	CamadaDeAplicacaoTransmissora(mensagem);
}

void CamadaDeAplicacaoTransmissora (string mensagem) {
	
	CamdaFisicaTransmissora(quadro);
}

void AplicacaoReceptora (string mensagem) {
	cout << "A mensagem recebida foi: " << mensagem <<endl;
}