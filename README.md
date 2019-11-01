# Proyecto POO1: Simulación de Hormiguero 2.0: 
### Diego Paredes, Jean Paul Huby y Miguel Lama

## Overview
Nuestro proyecto consiste en la creación  de una simulación de lo que vendría a ser un hormiguero. Este contará con una duración indefinida y se podrá apreciar las diferentes generaciones descendientes de la hormiga reina '0'. 
    
En esta simulación se podrá apreciar como las hormigas reinas se adaptan al ambiente generado y como estas administran sus colonias, a su vez, podremos ver como las otras hormigas (obreras, soldados, etc) trabajan por separado.

## Algoritmos de la simulación
 1. Perlin noise: Este algoritmo es el encargado de generar un mundo aleatorio "creible", en otras palabras, un mundo con estructura natural.
 2. Algoritmo Genetico: Este algoritmo es parte del objeto hormiga reina el cual define como administra la colonia la hormiga reina y crea copias de los datos recolectados para trasladarselo a sus sucesoras.
 3. Ant Colony Optimization: Este algoritmo es el encargado del movimiento de las hormigas en general.Utiliza la generacion y degradacion de las hormonas puestas por hormigas obreras y soldados.

## Clases/Objetos
 * Hormiga: Es la clase padre de las siguientes tre clases, esta contiene los atributos color, tamaño, vida, etc. 
 * Hormiga reina: Encargada de poner los huevos en la colonia y a su vez administrar dicha colonia.
 * Hormiga soldado: Encargada de defender la colonia asimismo ayuda en la caza de insectos.
 * Hormiga obrera: Encargada de la recolección de la comida, exploración del terreno y cuidado de las larvas.
 * Insectos: Estos van a ser las presas de las hormigas y la fauna de la simulación.
 * Mundo: Se va a generar con el algoritmo de perlin y va a tener múltiples propiedades como: humedad, altura, etc.
 * fm: "fm" es el objeto de la clase Funciones_De_Miguel su proposito es proveer funciones que automatizen el uso de la interfaz      
       visual


