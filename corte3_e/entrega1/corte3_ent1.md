# Informe de Entrega: Corte 3 - Programación Orientada a Objetos


* Valentina Delgado Arévalo

**Repositorio GitHub:** [Pega aquí el enlace a tu repo público]

---

## 1. Underground System (Sistema de Metro)

### Metodología
Se diseñó una solución basada en el uso de mapas de dispersión con la función (`unordered_map`). El primer mapa rastrea los ingresos de los pasajeros mediante su ID, almacenando la estación y el tiempo de entrada. El segundo mapa utiliza una llave compuesta (estación origen + destino) para acumular los tiempos totales y el conteo de viajes, permitiendo calcular el promedio en tiempo constante.

### Dificultades
La mayor dificultad fue la gestión de las llaves para las rutas, ya que se debía asegurar que la combinación de estaciones fuera única para no mezclar estadísticas de trayectos.


---

## 2. ATM (Cajero Automático)

### Metodología
Se implementó un algoritmo de tipo **Greedy**. El sistema recorre las denominaciones de billetes de mayor a menor para intentar cubrir el monto solicitado. Se utilizó el tipo de dato `long long` para el conteo de billetes.

### Dificultades
Asegurar que el cajero no entregara billetes si el monto total no podía completarse exactamente.


---

## 3. Auction System (Sistema de Subastas)

### Metodología
Se utilizó una estructura de datos anidada (`unordered_map` dentro de otro `unordered_map`). Esto permite una búsqueda eficiente. 

### Dificultades
Implementar la lógica de desempate en la función `getHighestBidder`, comparando tanto el monto de la oferta como el ID.


---

## 4. Meetup (Buscador de Fechas)

### Metodología
Se aplicó lógica de calendarios para calcular días específicos del mes. Se definió un rango de búsqueda según la semana solicitada. Por último, se implementó una función auxiliar para determinar el día de la semana de cualquier fecha.

### Dificultades
La lógica para la semana "last" fue la más compleja, ya que requiere identificar el último día del mes (teniendo en cuenta años bisiestos).


---

## 5. Clock (Reloj Cíclico)

### Metodología
Se centralizó la lógica del tiempo convirtiendo horas y minutos a una sola unidad: "minutos totales". Esto facilitó las operaciones de suma y resta. Se utilizó el operador módulo para garantizar que el tiempo siempre se mantuviera en el rango de hora como todos lo conocemos.

### Dificultades
Asegurar que el reloj se devolviera al día anterior.

---

## Compilación con CMake
Se incluyó un archivo `CMakeLists.txt` en la raíz que permite compilar los 5 proyectos de forma simultánea.

```bash
# Comandos utilizados para compilar manualmente:
g++ -o atm_prog ATM/main.cpp ATM/ATM.cpp
---
g++ -o auction_prog AuctionSystem/main.cpp 
---
g++ -o clock_prog Clock/main.cpp Clock/Clock.cpp
---
g++ -o meetup_prog Meetup/Main.cpp Meetup/Meetup.cpp
---
g++ -o underground_prog UndergroundSystem/main.cpp 