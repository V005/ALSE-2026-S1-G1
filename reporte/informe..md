# Informe — Ejercicios Práctica (C++)

Repositorio: https://github.com/V005/ALSE-2026-S1-G1

---

## Ejercicio 9 — Máximo Común Divisor (MCD)

Dos números al usuario y calcula el máximo común divisor usando el algoritmo de Euclides.

Se aplica un ciclo donde se divide un número por el otro y se usa el residuo hasta que uno de los valores sea cero. El último valor distinto de cero es el MCD.

Archivo: src/mcd.cpp

---

## Ejercicio 4.2 — Buscar un elemento en un arreglo

Solicita 10 números para llenar un arreglo. Luego pide un número al usuario y verifica si está presente recorriendo el arreglo con un ciclo.

Si el número se encuentra, se imprime que está presente. Si no, se indica que no está en el arreglo.

Archivo: src/buscar_arreglo.cpp


## LeetCode — Palindrome Number

Se verifica si un número es palíndromo invirtiendo sus dígitos y comparándolo con el número original.

Archivo: src/palindrome_number.cpp

---

## LeetCode — Two Sum

Se recorren todos los pares posibles del arreglo usando dos ciclos anidados para encontrar dos números cuya suma sea igual al target.

Archivo: src/two_sum.cpp

---

## LeetCode 121 — Best Time to Buy and Sell Stock

Se recorre el arreglo una sola vez guardando el precio mínimo visto hasta el momento y calculando la posible ganancia diaria.  
Se va actualizando la mejor ganancia encontrada.

Archivo: src/best_time_buy.cpp

---

## LeetCode 171 — Excel Sheet Column Number

Se interpreta el título de la columna como un número en base 26.  
Cada letra se convierte en su valor correspondiente (A=1, ..., Z=26) y se acumula multiplicando el resultado previo por 26.


Archivo: src/excel_column_number.cpp

---

## Calculadora con Callbacks

Se implementan funciones para suma, resta, multiplicación y división.  
Se utiliza un puntero a función (callback) para ejecutar dinámicamente la operación elegida.

Con algunas excepciones como la división entre 0.

Archivo: src/operacion_callbacks/operacion.cpp