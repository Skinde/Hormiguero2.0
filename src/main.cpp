#include"hormi.h"
#include"mundo.h"
#include"insecto.h"
#include"comida.h"

int main(){
	mundo karmaland(45, 45);
	int num;
	std::vector<reina*> reinas;
	std::cout<<"ingresar numero de reinas:";
	std::cin>> num;
	for(int i = 0; i < num; i++)
		reinas.push_back(new reina(randint(0,45),randint(0,45)));

	return 0;
}
