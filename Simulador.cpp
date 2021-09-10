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
	string aux;
	int quadro [mensagem.size()];
    for(int i = 0; i<mensagem.size(); i++){
        aux = std::bitset<8>(mensagem[i]).to_string();
        // cout << aux <<endl;
        quadro[i] = stoi(aux);
    }
    
    for(int i = 0; i<mensagem.size(); i++){
        // cout << quadro[i] <<endl;
    }
	
	CamdaFisicaTransmissora(quadro);
}

void AplicacaoReceptora (string mensagem) {
	cout << "A mensagem recebida foi: " << mensagem <<endl;
}