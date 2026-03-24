# Informe de Entrega 3 - Segundo Corte
**Estudiante:** Valentina  Delgado Arévalo

## 1. Introducción
Presentar el desarrollo de cuatro retos de programación en C++ enfocados en la gestión de datos, seguridad en transacciones y optimización de algoritmos.

## 2. Metodología y Desarrollo
Para la realización de esta entrega, organizar el proyecto en subdirectorios y utilizar **CMake** como herramienta principal de automatización. Esto permitir generar los ejecutables de manera centralizada en una carpeta de construcción (`build`).

### 2.1. Gestión de Seguridad (Bank Account)
- **Implementar** el uso de `std::thread` para simular múltiples depósitos simultáneos.
- **Utilizar** `std::mutex` para bloquear el acceso al saldo, evitando que los hilos choquen y generen errores en el cálculo final.

### 2.2. Optimización de Consultas (Exam Tracker)
- **Aplicar** la técnica de **Sumas Prefijas**. 
- **Calcular** el acumulado de puntajes una sola vez para permitir que cualquier consulta de rango se resuelva con una simple resta, mejorando la velocidad del programa.

### 2.3. Cifrado de Mensajes (Square Code)
- **Eliminar** espacios en blanco del texto original.
- **Distribuir** los caracteres en una matriz cuadrada y leer por columnas para generar el código secreto.

### 2.4. Control de Acceso (Token Manager)
- **Almacenar** usuarios y tiempos de expiración en un `std::map`.
- **Validar** si un token sigue activo comparando el tiempo de ingreso con el tiempo de expiración guardado.

## 3. Dificultades Encontradas
- **Configuración de CMake:** Ajustar el enlace de la librería de hilos (`pthread`) en el entorno Linux de WSL para que el programa del banco compilara correctamente.
- **Persistencia de archivos:** Manejar errores de rutas al mover carpetas dentro del entorno de trabajo, lo cual se solucionó verificando la estructura de directorios en el terminal.

## 4. Evidencias de Ejecución
Al finall del documento

## 5. Conclusiones
- Lograr la integración de múltiples módulos bajo un mismo sistema de compilación.
- Comprender la importancia de proteger regiones críticas del código cuando se trabaja con programación concurrente.