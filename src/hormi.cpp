#include"hormi.h"
		hormiga::hormiga(tamano e, tamano o, pos eq, pos ye, nivel live, nivel ouch){
			w = e;
                	h = o;
                        x = eq;
                        y = ye;
                        lx = eq;
                        ly = ye;
                        vida = live;
                        dano = ouch;
		}
//reina metodos
		reina::reina(pos equis, pos ye): hormiga(2,3,randint(0.0, equis),randint(0.0, ye),200.0, 0.0){
			variacion_obrera = rand()%10;
			variacion_soldado = rand()%10;
			comida = 0;
		}
		reina::reina(pos w, pos u,nivel var_o, nivel var_s): hormiga(2,3,w,u,200.0, 0.0){
			if(var_o > var_s){
				variacion_obrera = var_o + 1.0;
				variacion_soldado = var_s;
			}
			else{ 
				variacion_soldado = var_s + 1.0;
				variacion_obrera = var_o;
			}
			comida = 0;
		}
                void reina::movimiento(std::vector<std::vector<nivel>> matriz){
                	srand(time(NULL));
        		float arr[] = {matriz[x-1][y+1], matriz[x][y+1], matriz[x+1][y+1], matriz[x-1][y], matriz[x+1][y], matriz[x-1][y-1], matriz[x][y-1], matriz[x+1][y-1]};
			std::sort(arr, arr + 8);
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
			hormigas.push_back(new obrera(x,y));
		}
                void reina::poner_soldado(){
			hormigas.push_back(new soldado(x, y));
		}
                void reina::poner_reina(std::vector<reina*> reinas){
			reinas.push_back(new reina(x,y, variacion_obrera, variacion_soldado));
		}
                void reina::vivir(std::vector<std::vector<nivel>> matriz){
				if(matriz[y][x] > matriz[y +1][x-1] || matriz[y][x] > matriz[y +1][x] ||
                		 matriz[y][x] > matriz[y + 1][x + 1] || matriz[y][x] > matriz[y][x - 1]
                		 || matriz[y][x] > matriz[y][x+1] || matriz[y][x] > matriz[y-1][x-1]
                		 || matriz[y][x] > matriz[y -1][x] || matriz[y][x] > matriz[y-1][x + 1])
					movimiento(matriz);
				else{
					nivel sum = variacion_obrera +variacion_soldado;
					nivel ob = (variacion_obrera*10.0)/sum;
					nivel sol= (variacion_soldado*10.0)/sum;
					nivel v = randint(0.0,10.0);
					if(v<=ob && v > sol)
						poner_obrera();
					if(v>ob && v<=sol)
						poner_soldado();
					if(v<ob && ob< sol)
						poner_obrera();
					if(v< sol && sol < ob)
						poner_soldado();
				}
		}
        
//fin
//soldado metodos
		soldado::soldado(pos w, pos u):hormiga(2,2,w,u,100.0, 20.0){}
                void soldado::movimiento(std::vector<std::vector<nivel>> matriz){
		 	srand(time(NULL));
                        float arr[] = {matriz[x-1][y+1], matriz[x][y+1], matriz[x+1][y+1], matriz[x-1][y], matriz[x+1][y], matriz[x-1][y-1], matriz[x][y-1], matriz[x+1][y-1]};
			std::sort(arr, arr + 8);
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
			movimiento(matriz);
		}
                

//fin
//obrera metodos
		obrera::obrera(pos w, pos u):hormiga(1,1,w,u,50.0, 5.0){
			comida = false;
		}
		void obrera::movimiento(std::vector<std::vector<nivel>> matriz){
		 	srand(time(NULL));
                        float arr[] = {matriz[x-1][y+1], matriz[x][y+1], matriz[x+1][y+1], matriz[x-1][y], matriz[x+1][y], matriz[x-1][y-1], matriz[x][y-1], matriz[x+1][y-1]};
			std::sort(arr, arr + 8);
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
		void obrera::depositar_comida(){
			comida = false;
			carga = 0.0;
		}
                void obrera::vivir(std::vector<std::vector<nivel>> matriz){
			movimiento(matriz);
			
		}
                

//fin
