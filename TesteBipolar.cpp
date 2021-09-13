/* Este arquivo é apenas um modelo, vai ser apagado posteriormente */
#include <iostream>

int main() {
	int bit[8] = {0, 1, 0, 1, 0, 0, 1, 1};
	int aux, i = 0;

	/* printar */
	for(i = 0; i < 8; i++){
		std::cout << bit[i];
	}
	std::cout << "\n" << std::endl;
	
	/* codificação bipolar */
	for(i = 0; i < 8; i++){
		if(bit[i] == 1 && aux == 0){
			bit[i] = 1;
			aux = 1;
		}else if(bit[i] == 1 && aux == 1){
			bit[i] = -1;
			aux = 0;
		}
	}
	
	/* printar */
	for(i = 0; i < 8; i++){
		std::cout << bit[i];
	}
	std::cout << "\n" << std::endl;

	/* decodificação bipolar */
	for(i = 0; i < 8; i++){
		if(bit[i] == 1 || bit[i] == -1){
			bit[i] = 1;
		}
	}
	
	/* printar */
	for(i = 0; i < 8; i++){
		std::cout << bit[i];
	}
	std::cout << "\n" << std::endl;
	
    return 0;
}