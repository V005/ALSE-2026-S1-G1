# Corte 2 - Entrega 1

Valentina Delgado Arévalo 
Repositorio: https://github.com/V005/ALSE-2026-S1-G1 

En este informe se presentan las soluciones desarrolladas para los ejercicios *Parking, **Armstrong, **Hamming* y *Space Age*. Para cada programa se resume brevemente la metodología utilizada y algunos aspectos relevantes de la implementación.

---

## 1. Parking

### Descripción
Este programa simula un sistema de parqueadero con cupos para carros grandes, medianos y pequeños. Cada vez que entra un carro, el sistema revisa si todavía hay espacio disponible para ese tipo.

### Metodología
Se creó una clase llamada ParkingSystem con tres atributos: big, medium y small, que representan la cantidad de cupos disponibles.  
En el constructor se inicializan estos valores. Luego, con el método addCar(int carType), se verifica el tipo de carro que entra:
- si es tipo 1, ocupa un cupo grande;
- si es tipo 2, ocupa un cupo mediano;
- si es tipo 3, ocupa un cupo pequeño.

Si hay espacio disponible, el programa descuenta un cupo y retorna true. Si no hay espacio, retorna false.

### Aspectos relevantes
Se usó this-> en el constructor para diferenciar los atributos de la clase de los parámetros recibidos. También se probó el funcionamiento desde main() simulando varias entradas de carros.


### Ejemplo de ejecución
- el primer carro grande entra correctamente;
- el carro mediano entra correctamente;
- el carro pequeño no entra porque no había cupos;
- el segundo carro grande tampoco entra porque ya se había ocupado el único cupo disponible.

---

## 2. Armstrong

### Descripción
Este programa determina si un número ingresado por el usuario es un número Armstrong.

### Metodología
Primero se lee un número entero. Después se cuenta cuántos dígitos tiene usando un ciclo while.  
Luego se vuelve a recorrer el número para separar cada dígito con el operador módulo %. Cada dígito se eleva a la cantidad total de dígitos usando pow(), y esos resultados se van sumando.  
Al final, la suma obtenida se compara con el número original:
- si son iguales, el número es Armstrong;
- si no, no lo es.

### Aspectos relevantes
Se utilizaron variables auxiliares para no perder el valor original del número durante el proceso. El programa aplica correctamente operaciones de división entera, módulo y potenciación.


### Ejemplo de ejecución
Si el usuario ingresa un número como *153*, el programa indica que sí es un número Armstrong, ya que:

1³ + 5³ + 3³ = 153

---

## 3. Hamming

### Descripción
Este programa calcula la distancia de Hamming entre dos secuencias de ADN ingresadas por el usuario.

### Metodología
Primero se leen dos cadenas. Luego se verifica que ambas tengan la misma longitud. Si no la tienen, el programa muestra un mensaje de error y finaliza.  
Si las longitudes coinciden, se recorren ambas cadenas posición por posición y se compara cada carácter. Cada vez que los caracteres son distintos, se incrementa un contador.  
Ese contador corresponde a la distancia de Hamming.

### Aspectos relevantes
El programa valida primero que las secuencias sean comparables. Después usa un ciclo for para revisar cada posición de manera ordenada.

### Ejemplo de ejecución
Si se ingresan dos cadenas del mismo tamaño, el programa compara letra por letra y muestra cuántas posiciones son diferentes.

---

## 4. Space Age

### Descripción
Este programa calcula la edad de una persona en la Tierra a partir de los segundos vividos y, adicionalmente, calcula su edad en Mercurio.

### Metodología
Primero se define una constante con la cantidad de segundos que tiene un año terrestre. Luego el usuario ingresa su edad en segundos.  
Con ese dato, el programa calcula la edad en la Tierra dividiendo los segundos vividos entre los segundos que tiene un año terrestre.  
Después se usan factores orbitales para convertir esa edad a otros planetas. En este caso se muestra el cálculo para Mercurio, dividiendo la edad terrestre entre su factor orbital.

### Aspectos relevantes
Se usó long long para almacenar cantidades grandes de segundos y iomanip para mostrar el resultado con dos decimales. También se definieron factores para varios planetas, aunque en la salida final solo se muestra Mercurio.

### Ejemplo de ejecución
El usuario ingresa su edad en segundos y el programa muestra:
- la edad equivalente en la Tierra;
- la edad equivalente en Mercurio.

---

## Compilación

Para compilar todos los programas en una sola ejecución se creó un archivo CMakeLists.txt. Esto permitió organizar mejor el proyecto y generar los ejecutables correspondientes a cada problema.
