//Código de Método de Eliminación de Gauss-Jordan en Scilab

//Matriz de coeficientes de sistema de ecuaciones.
a=[5,-2, 2;4, 8, -2; 3, 9, -5]

 // 5x -2y + 2z = 7
 // 4x +8y -2z = 6
 // 3x + 9y - 5z = 12

//Matriz de constantes del sistema de ecuaciones.
b=[10;16;9]

//Matriz aumentada
AumAb=[a b]


//Gauss-Jordan
rref(aumAB)
 
//La matriz resultante contiene las soluciones 
//para cada una de las incógnitas del sistema.
