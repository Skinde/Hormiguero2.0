#include"hormi.h"

//reina metodos
		reina::reina(){
			vida = 200.0;
			dano = 0.0;

		}
                void reina::posicionamiento(pos equis, pos ye){
			x = equis;
			y = ye;
		}
                void reina::movimiento(std::vector<std::vector<nivel>> matriz){
                	srand(time(NULL));
        		float arr[] = {matriz[x-1][y+1], matriz[x][y+1], matriz[x+1][y+1], matriz[x-1][y], matriz[x+1][y], matriz[x-1][y-1], matriz[x][y-1], matriz[x+1][y-1]};
        		sort(arr, arr + 8);
        		int R = log2(rand() % 256);
        		if(arr[R] == matriz[x-1][y+1]){
                		y += 1;
                		x -= 1;
        		}
        		else if(arr[R] == matriz[x][y+1]){
				y += 1;
        		}
        		else if(arr[R] == matriz[x+1][y+1]){
                		y += 1;
                		x += 1;
        		}
        		else if(arr[R] == matriz[x-1][y]){
               			x -= 1;
        		}
        		else if(arr[R] == matriz[x+1][y]){
                		x += 1;
        		}
        		else if(arr[R] == matriz[x-1][y-1]){
                		y -= 1;
                		x -= 1;
        		}
        		else if(arr[R] == matriz[x][y-1]){
                		y -= 1;
                	}
        		else if(arr[R] == matriz[x+1][y-1]){
                		y -= 1;
                		x += 1;
			}
}
     		void reina::poner_obrera(){
			hormigas.push_back(new obrera);
		}
                void reina::poner_soldado(){
			hormigas.push_back(new soldado);
		}
                void reina::poner_reina(){
			hormigas.push_back(new reina);
		}
		void reina::crear_hormiguero(pos eq, pos ye){
			/*dibujar rectangulo*/			
		}
                void reina::vivir(std::vector<std::vector<nivel>> matriz){
			while(true){
				movimiento(matriz);
				 if(matriz[y][x] > matriz[y +1][x-1] && matriz[y][x] > matriz[y +1][x] &&
                		 matriz[y][x] > matriz[y + 1][x + 1] && matriz[y][x] > matriz[y][x - 1]
                		 && matriz[y][x] > matriz[y][x+1] && matriz[y][x] > matriz[y-1][x-1]
                		 && matriz[y][x] > matriz[y -1][x] && matriz[y][x] > matriz[y-1][x + 1])
                                         break;
			}	
			crear_hormiguero(x,y);

		}
        
//fin
//soldado metodos
		soldado::soldado(){
			vida = 100.0;
			dano = 25.0;
		}
                void soldado::movimiento(std::vector<std::vector<nivel>> matriz){
		 	srand(time(NULL));
                        float arr[] = {matriz[x-1][y+1], matriz[x][y+1], matriz[x+1][y+1], matriz[x-1][y], matriz[x+1][y], matriz[x-1][y-1], matriz[x][y-1], matriz[x+1][y-1]};
                        sort(arr, arr + 8);
                        int R = log2(rand() % 256);
                        if(arr[R] == matriz[x-1][y+1]){
                                y += 1;
                                x -= 1;
                        }
                        else if(arr[R] == matriz[x][y+1]){
                                x -= 1;
                        }
                        else if(arr[R] == matriz[x+1][y+1]){
                                y += 1;
                                x += 1;
                        }
                        else if(arr[R] == matriz[x-1][y]){
                                x -= 1;
                        }
                        else if(arr[R] == matriz[x+1][y]){
                                x += 1;
                        }
                        else if(arr[R] == matriz[x-1][y-1]){
                                y -= 1;
                                x -= 1;
                        }
                        else if(arr[R] == matriz[x][y-1]){
                                y -= 1;
                        }
                        else if(arr[R] == matriz[x+1][y-1]){
                                y -= 1;
                                x += 1;
                        }
		}
                void soldado::vivir(std::vector<std::vector<nivel>> matriz){
		
		}
                

//fin
//obrera metodos
		obrera::obrera(){
			vida = 50.0;
			dano = 5.0;
			comida = false;
		}
		void obrera::movimiento(std::vector<std::vector<nivel>> matriz){
		 	srand(time(NULL));
                        float arr[] = {matriz[x-1][y+1], matriz[x][y+1], matriz[x+1][y+1], matriz[x-1][y], matriz[x+1][y], matriz[x-1][y-1], matriz[x][y-1], matriz[x+1][y-1]};
                        sort(arr, arr + 8);
                        int R = log2(rand() % 256);
                        if(arr[R] == matriz[x-1][y+1]){
                                y += 1;
                                x -= 1;
                        }
                        else if(arr[R] == matriz[x][y+1]){
                                x += 1;
                        }
                        else if(arr[R] == matriz[x+1][y+1]){
                                y += 1;
                                x += 1;
                        }
                        else if(arr[R] == matriz[x-1][y]){
                                x -= 1;
                        }
                        else if(arr[R] == matriz[x+1][y]){
                                x += 1;
                        }
                        else if(arr[R] == matriz[x-1][y-1]){
                                y -= 1;
                                x -= 1;
                        }
                        else if(arr[R] == matriz[x][y-1]){
                                y -= 1;
                        }
                        else if(arr[R] == matriz[x+1][y-1]){
                                y -= 1;
                                x += 1;
                        }
		}
		void obrera::recolectar_comida(){
			comida = true;
			carga = 10.0;
		}
                void obrera::vivir(std::vector<std::vector<nivel>> matriz){
			while(comida = false){
				movimiento(matriz);
			}
			recolectar_comida();
			while(comida = true){
				movimiento(matriz);
			}
		}
                

//fin
