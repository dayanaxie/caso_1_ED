# Caso 1 Estructuras de Datos

Estudiante: Dayana Xie Li

Curso: Estructuras de Datos

Carnet: 2022097967

## Descripción del caso

Existe un teorema llamado  _four color_  el cual indica que con tan solo 4 colores es posible pintar las regiones de cualquier mapa de tal forma que dos regiones adyacentes nunca van a tener el mismo color.  [https://en.wikipedia.org/wiki/Four_color_theorem](https://en.wikipedia.org/wiki/Four_color_theorem)  . cómo demostraría usted por medio de un programa en C++ que un mapa dado cumple con dicho teorema? que estructura de datos diseñaría para que su solución y algoritmo sea simple? cómo le suministraría la información del mapa al algoritmo?

## Formato

El formato establecido para la suministración de la información del mapa es harcoded. La información que se debe especificar es el id (identificación), los ids vecinos y el color de cada región. Además de que en la constante "AMOUNT_REGIONS" se debe especificar la cantidad de regiones que se quiere tener en el mapa. 

Los colores son representados por medio de números, en donde el cero representa que la región no posee color, y los números del uno al cuatro representan un color diferente.

La estructura de datos de la solución está conformada por un arreglo del tipo struct region, en donde el arreglo está conformado por cada region que forma parte del mapa y que cada uno contiene un id, un arreglo de neighbours y un regionColor de tipo int. 

Por ejemplo:

Si queremos suministrar un mapa con cuatro regiones, debemos indicar en la constante la cantidad de regiones que se quiere que tenga el mapa. Luego en el arreglo que va a guardar las regiones, se especifica primero el identificador de la región (1,2,...,n), seguido de otros corchetes en donde dentro de ellos se ingresarán los identificadores de los vecinos de la región y finalmente se especifica el color actual del mapa.
```
#define AMOUNT_REGIONS 4
region map[AMOUNT_REGIONS] = {

{1, {2, 3, 4}, 1},

{2, {3, 1, 4}, 4},

{3, {1, 2, 4}, 3},

{4, {1, 2, 3}, 2}

};
``` 

