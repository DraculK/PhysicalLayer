/* Este arquivo é apenas um modelo, vai ser apagado posteriormente*/
#include <iostream>

int main() {
	int bit[8] = {0, 1, 0, 1, 0, 0, 1, 1};
	int manchester[16];
	int clock = 1;
	int i, j = 0;
	/* i é utilizado para bit e j para manchester */
	
	/* printar */
	for(i = 0; i < 8; i++){
		std::cout << bit[i];
	}
	std::cout << "\n" << std::endl;

	/* Codificação Manchester */
	for(i = 0; i < 8; i++){
		clock = 0;
		if(clock == 0 && bit[i] == 0){
			manchester[j] = 0;
		}else if(clock == 0 && bit[i] == 1){
			manchester[j] = 1;
		}else if(clock == 1 && bit[i] == 0){
			manchester[j] = 1;
		}else if(clock == 1 && bit[i] == 1){
			manchester[j] = 0;
		}
		j += 1;
		clock = 1;
		if(clock == 0 && bit[i] == 0){
			manchester[j] = 0;
		}else if(clock == 0 && bit[i] == 1){
			manchester[j] = 1;
		}else if(clock == 1 && bit[i] == 0){
			manchester[j] = 1;
		}else if(clock == 1 && bit[i] == 1){
			manchester[j] = 0;
		}
		j += 1;
	}
	
	/* printar */
	for(i = 0; i < (8*2); i++){
		std::cout << manchester[i];
	}
	std::cout << "\n" << std::endl;

	/* Decodificação manchester */
	for(j = 1; j < (8*2); j+=2){
		clock = 1;
		/* (clock % 2 == 0) */
		/* (clock == 0) ? (faz nada) : (executa o if) */
		if(manchester[j] == 0){
			bit[i] = 1;
		}else if(manchester[j] == 1){
			bit[i] = 0;
		}
	}
	
	/* printar */
	for(i = 0; i < 8; i++){
		std::cout << bit[i];
	}
	std::cout << "\n" << std::endl;
	
    return 0;
}