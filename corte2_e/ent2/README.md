# Informe de Actividad Entregable 2 

Valentina Delgado Arévalo 

---

## 1. Introducción
Este documento presenta la solución a cuatro retos de programación que involucran lógica de sistemas, estructuras de datos y algoritmos de simulación. La compilación se ha automatizado mediante **CMake** para garantizar que todos los módulos funcionen de manera integrada y sencilla.

---

## 2. Metodología y Desarrollo

### A. Twitter Design (twitter.cpp)
Se implementó un sistema de noticias utilizando `unordered_map` para asociar usuarios con sus tweets y sus seguidores. Para obtener el feed de los 10 mensajes más recientes, se utilizó una **Priority Queue (Min-Heap)** que filtra por el `timestamp` de cada publicación.
* **Dificultades:** Manejar la concurrencia de tweets entre el usuario y sus seguidos para no exceder el límite de 10 elementos.
Librerías `<vector>`, `<unordered_map>`, `<queue>`.

### B. Spreadsheet System (spreadsheet.cpp)
Se diseñó una hoja de cálculo lógica basada en un mapa de strings a enteros. El sistema permite procesar fórmulas simples (como `=A1+B2`) mediante el parsing de cadenas y la búsqueda de valores en las celdas referenciadas.
* **Dificultades:** Separar correctamente los operandos de la fórmula y convertir los strings a valores numéricos usando `stoi`.
Librerías `<string>`, `<unordered_map>`.

### C. Robot Simulator (robot_simulator.cpp)
Simulación de movimiento en un plano 2D. Se utilizó un `enum` para las direcciones (N, E, S, W) EAST, WEST, NORTH AND SOUTH, y una estructura de coordenadas. El robot procesa una cadena de instrucciones (`R`, `L`, `A`) actualizando su estado tras cada paso.
* **Dificultades:** Implementar la lógica de rotación circular (por ejemplo, que al girar a la derecha estando en 'West' pase a 'North').
Lógica de condicionales y tipos enumerados.

### D. Queen Attack (queen_attack.cpp)
Algoritmo geométrico para determinar si dos reinas en un tablero de 8x8 pueden atacarse. Se validan tres condiciones: misma fila, misma columna o misma diagonal (donde la diferencia absoluta de filas es igual a la de columnas).
* **Dificultades:** Validar que las posiciones de las reinas estén dentro de los límites legales del tablero antes de calcular el ataque.
Funciones matemáticas de valor absoluto (`abs`).

---

## 3. Instrucciones de Compilación y Ejecución

Se ha incluido un archivo `CMakeLists.txt`. 

### Pasos para compilar:
1. Abrir la terminal en la carpeta `ent2`.
2. Crear carpeta de build: `mkdir build_ent2 && cd build_ent2`.
3. Configurar: `cmake ..`
4. Compilar: `cmake --build .`

Una vez compilado, se pueden ejecutar los programas con los siguientes comandos:
* `./ejecutable_twitter`
* `./ejecutable_spreadsheet`
* `./ejecutable_robot`
* `./ejecutable_queens`

---

## 4. Compilaciones
