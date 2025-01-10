
# Resumen primera semana

## Tipos de Datos

### Enteros (`int`)
Representan números sin decimales. Según Kernighan y Ritchie (1988), los enteros ocupan un espacio de almacenamiento dependiente de la arquitectura.

**Ejemplo:**
```c
int edad = 25;
printf("La edad es: %d\n", edad);
```

### Flotantes (`float`, `double`)
Datos numéricos con decimales usados para cálculos precisos (Deitel & Deitel, 2021).

**Ejemplo:**
```c
float pi = 3.14;
printf("El valor de pi es: %.2f\n", pi);
```

### Caracteres (`char`)
Representan un único carácter ASCII. Ocupan 1 byte (Kernighan & Ritchie, 1988).

**Ejemplo:**
```c
char inicial = 'A';
printf("La inicial es: %c\n", inicial);
```

### Cadenas (`char[]`)
Arreglos de caracteres terminados en un carácter nulo '\0' (Deitel & Deitel, 2021).

**Ejemplo:**
```c
char nombre[] = "Juan";
printf("El nombre es: %s\n", nombre);
```

---

## Funciones y Procedimientos

### Funciones
Son bloques de código que realizan tareas específicas y devuelven un valor al programa que las invoca.

**Ejemplo:**
```c
int suma(int a, int b) {
    return a + b;
}

int main() {
    int resultado = suma(5, 3);
    printf("La suma es: %d\n", resultado);
    return 0;
}
```

### Procedimientos
Son bloques de código que no devuelven valor y utilizan el tipo `void`.

**Ejemplo:**
```c
void imprimirMensaje() {
    printf("Hola, mundo!\n");
}

int main() {
    imprimirMensaje();
    return 0;
}
```

### Parámetros
- **Por valor:** Pasa una copia del dato, protegiendo el original (Kernighan & Ritchie, 1988).
- **Por referencia:** Pasa la dirección de memoria del dato, permitiendo modificarlo.

**Ejemplo Por Valor:**
```c
void incrementarPorValor(int x) {
    x = x + 1;
    printf("Dentro de la función: %d\n", x);
}

int main() {
    int numero = 5;
    incrementarPorValor(numero);
    printf("Después de la función: %d\n", numero);
    return 0;
}
```

**Ejemplo Por Referencia:**
```c
void incrementarPorReferencia(int *x) {
    *x = *x + 1;
    printf("Dentro de la función: %d\n", *x);
}

int main() {
    int numero = 5;
    incrementarPorReferencia(&numero);
    printf("Después de la función: %d\n", numero);
    return 0;
}
```

---

## Bucles

### `for`
Ideal para iteraciones con un límite conocido.

**Ejemplo:**
```c
for (int i = 0; i < 5; i++) {
    printf("El valor de i es: %d\n", i);
}
```

### `while`
Repite mientras una condición sea verdadera.

**Ejemplo:**
```c
int i = 0;
while (i < 5) {
    printf("El valor de i es: %d\n", i);
    i++;
}
```

### `do-while`
Asegura al menos una iteración.

**Ejemplo:**
```c
int i = 0;
do {
    printf("El valor de i es: %d\n", i);
    i++;
} while (i < 5);
```

---

## Modularidad en Programación

### Ventajas
- Facilita la lectura y mantenimiento del código (Deitel & Deitel, 2021).
- Promueve la reutilización.

### Cohesión y Acoplamiento
- **Cohesión:** Cada módulo realiza una tarea específica.
- **Acoplamiento:** Interacción mínima entre módulos.

**Ejemplo de Modularidad:**
```c
// Función para calcular el cuadrado de un número
int cuadrado(int n) {
    return n * n;
}

int main() {
    int numero = 4;
    printf("El cuadrado de %d es %d\n", numero, cuadrado(numero));
    return 0;
}
```

---

## Referencias

- Deitel, P. J., & Deitel, H. M. (2021). *C: How to Program (9th ed.).* Pearson.
- Kernighan, B. W., & Ritchie, D. M. (1988). *The C Programming Language (2nd ed.).* Prentice Hall.

---

## Organización del Código: Ubicación de las Funciones

### ¿Por qué las funciones deben ir fuera de `main`?

Colocar las funciones fuera de `main` es una **práctica estándar** en C porque:
1. **Modularidad y Reutilización:**
    - Las funciones fuera de `main` pueden ser reutilizadas en diferentes partes del programa o incluso en otros programas.
    - Esto promueve el diseño modular y facilita la lectura del código.

2. **Claridad del Código:**
    - Colocar funciones fuera de `main` separa la lógica de implementación de la lógica de control principal.
    - Hace que `main` sea más legible al concentrarse únicamente en coordinar el flujo del programa.

3. **Facilita el Depurado:**
    - Funciones separadas permiten probarlas de manera aislada para verificar su funcionamiento.

### ¿Por qué las funciones se declaran al inicio?

Las funciones deben **declararse al inicio** del programa o al menos **antes de ser usadas** por las siguientes razones:
1. **Requisitos del Compilador:**
    - En C, el compilador necesita conocer la existencia de una función antes de que sea invocada en `main` o en otras funciones.

2. **Evitar Errores de Compilación:**
    - Si una función no se declara antes de usarse, el compilador no sabrá cómo manejarla y generará errores.

### Formas de Declaración de Funciones

1. **Prototipos de Función:**
    - Declarar el prototipo de las funciones al inicio del programa y escribir su implementación después de `main`.
    - **Ejemplo:**
   ```c
   #include <stdio.h>

   // Prototipo de la función
   int suma(int a, int b);

   int main() {
       int resultado = suma(5, 3);
       printf("La suma es: %d\n", resultado);
       return 0;
   }

   // Implementación de la función
   int suma(int a, int b) {
       return a + b;
   }
   ```

2. **Definición Directa Antes de `main`:**
    - Escribir la implementación completa de las funciones antes de `main`.
    - **Ejemplo:**
   ```c
   #include <stdio.h>

   int suma(int a, int b) {
       return a + b;
   }

   int main() {
       int resultado = suma(5, 3);
       printf("La suma es: %d\n", resultado);
       return 0;
   }
   ```

### Ventajas de Usar Prototipos
- Permite organizar las funciones de manera lógica sin preocuparse por su ubicación en el archivo.
- Facilita la comprensión de la estructura del programa.


---

## Funciones Básicas: Validación de Enteros

### Validar que el input sea un número entero positivo
Esta función solicita un número al usuario y asegura que sea un entero positivo.

**Código:**
```c
#include <stdio.h>

int validatePositiveInt() {
    int number;
    do {
        printf("Introduce un número entero positivo: ");
        scanf("%d", &number);
        if (number <= 0) {
            printf("Error: El número debe ser mayor que 0. Intenta nuevamente.\n");
        }
    } while (number <= 0); // Repite hasta que el número sea válido

    return number;
}

int main() {
    int validNumber = validatePositiveInt();
    printf("Número válido ingresado: %d\n", validNumber);
    return 0;
}
```

### Validar si un número es par
Esta función verifica si un número entero es par o impar.

**Código:**
```c
#include <stdio.h>
#include <stdbool.h>

bool esPar(int numero) {
    return numero % 2 == 0;
}

int main() {
    int numero;
    printf("Introduce un número: ");
    scanf("%d", &numero);

    if (esPar(numero)) {
        printf("%d es par\n", numero);
    } else {
        printf("%d es impar\n", numero);
    }

    return 0;
}
```

---

## Funciones Básicas: Manejo de Cadenas

### Obtener la longitud de una cadena
Usa la función estándar `strlen` para calcular la longitud de una cadena.

**Código:**
```c
#include <stdio.h>
#include <string.h>

int main() {
    char cadena[100];
    printf("Introduce una cadena: ");
    scanf("%s", cadena);

    printf("La longitud de la cadena es: %lu\n", strlen(cadena));
    return 0;
}
```

### Comparar dos cadenas
Usa la función estándar `strcmp` para comparar dos cadenas lexicográficamente.

**Código:**
```c
#include <stdio.h>
#include <string.h>

int main() {
    char cadena1[100], cadena2[100];
    printf("Introduce la primera cadena: ");
    scanf("%s", cadena1);
    printf("Introduce la segunda cadena: ");
    scanf("%s", cadena2);

    if (strcmp(cadena1, cadena2) == 0) {
        printf("Las cadenas son iguales\n");
    } else {
        printf("Las cadenas son diferentes\n");
    }
    return 0;
}
```

### Copiar una cadena a otra
Usa la función estándar `strcpy` para copiar una cadena.

**Código:**
```c
#include <stdio.h>
#include <string.h>

int main() {
    char cadena1[100], cadena2[100];
    printf("Introduce una cadena: ");
    scanf("%s", cadena1);

    strcpy(cadena2, cadena1);
    printf("La copia de la cadena es: %s\n", cadena2);
    return 0;
}
```

### Concatenar dos cadenas
Usa la función estándar `strcat` para concatenar dos cadenas.

**Código:**
```c
#include <stdio.h>
#include <string.h>

int main() {
    char cadena1[100], cadena2[100];
    printf("Introduce la primera cadena: ");
    scanf("%s", cadena1);
    printf("Introduce la segunda cadena: ");
    scanf("%s", cadena2);

    strcat(cadena1, cadena2);
    printf("La cadena concatenada es: %s\n", cadena1);
    return 0;
}
```

### Validar si una cadena es un palíndromo
Verifica si una cadena es igual cuando se lee al revés.

**Código:**
```c
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool esPalindromo(char *cadena) {
    int inicio = 0;
    int fin = strlen(cadena) - 1;

    while (inicio < fin) {
        if (cadena[inicio] != cadena[fin]) {
            return false;
        }
        inicio++;
        fin--;
    }
    return true;
}

int main() {
    char cadena[100];
    printf("Introduce una cadena: ");
    scanf("%s", cadena);

    if (esPalindromo(cadena)) {
        printf("La cadena es un palíndromo\n");
    } else {
        printf("La cadena no es un palíndromo\n");
    }
    return 0;
}
```

---

## Resumen
Estas funciones cubren validaciones básicas de números enteros y operaciones comunes con cadenas, utilizando la biblioteca estándar de C (`<string.h>`). Estas funciones son fundamentales para manipular datos de entrada y realizar validaciones eficaces en programas más complejos.


---

## Formatos de `printf` en C

En C, la función `printf` utiliza especificadores de formato para imprimir diferentes tipos de datos. La siguiente tabla resume los formatos más comunes:

| Tipo de Dato         | Especificador de Formato | Ejemplo de Uso                  |
|----------------------|--------------------------|----------------------------------|
| Entero (`int`)       | `%d` o `%i`             | `printf("Número: %d", 42);`     |
| Entero sin signo     | `%u`                    | `printf("Número: %u", 42);`     |
| Entero en octal      | `%o`                    | `printf("Octal: %o", 42);`      |
| Entero en hexadecimal| `%x` (minúscula)        | `printf("Hex: %x", 42);`        |
|                     | `%X` (mayúscula)        | `printf("HEX: %X", 42);`        |
| Flotante (`float`)    | `%f`                    | `printf("Pi: %.2f", 3.14);`     |
| Flotante en notación científica | `%e` o `%E` | `printf("Científica: %e", 3.14);` |
| Doble precisión (`double`) | `%lf`             | `printf("Número: %lf", 3.14);`  |
| Carácter (`char`)     | `%c`                    | `printf("Letra: %c", 'A');`     |
| Cadena (`char[]`)     | `%s`                    | `printf("Texto: %s", "Hola");`  |
| Puntero               | `%p`                    | `printf("Puntero: %p", &x);`    |
| Porcentaje (`%`)      | `%%`                    | `printf("Porcentaje: %%");`     |

### Ejemplo de Uso General
El siguiente código demuestra cómo usar varios formatos de `printf`:

**Código:**
```c
#include <stdio.h>

int main() {
    int entero = 42;
    float flotante = 3.14;
    char caracter = 'A';
    char cadena[] = "Hola, mundo";
    void *puntero = &entero;

    printf("Entero: %d\n", entero);
    printf("Flotante: %.2f\n", flotante);
    printf("Carácter: %c\n", caracter);
    printf("Cadena: %s\n", cadena);
    printf("Puntero: %p\n", puntero);
    printf("Porcentaje: %%\n");

    return 0;
}
```

### Salida Esperada
```
Entero: 42
Flotante: 3.14
Carácter: A
Cadena: Hola, mundo
Puntero: 0x7ffee1f9a780
Porcentaje: %
```

---

---

## Formatos de `scanf` en C

Al igual que `printf`, la función `scanf` utiliza especificadores de formato para leer diferentes tipos de datos desde la entrada estándar. La siguiente tabla resume los formatos más comunes:

| Tipo de Dato         | Especificador de Formato | Ejemplo de Uso                     |
|----------------------|--------------------------|-------------------------------------|
| Entero (`int`)       | `%d` o `%i`             | `scanf("%d", &numero);`            |
| Entero sin signo     | `%u`                    | `scanf("%u", &numero);`            |
| Entero en octal      | `%o`                    | `scanf("%o", &numero);`            |
| Entero en hexadecimal| `%x` (minúscula)        | `scanf("%x", &numero);`            |
|                     | `%X` (mayúscula)        | `scanf("%X", &numero);`            |
| Flotante (`float`)    | `%f`                    | `scanf("%f", &numero);`            |
| Doble precisión (`double`) | `%lf`             | `scanf("%lf", &numero);`           |
| Carácter (`char`)     | `%c`                    | `scanf("%c", &letra);`             |
| Cadena (`char[]`)     | `%s`                    | `scanf("%s", cadena);`             |
| Long (`long int`)     | `%ld`                  | `scanf("%ld", &numero);`           |
| Long sin signo        | `%lu`                  | `scanf("%lu", &numero);`           |
| Long doble precisión (`long double`) | `%Lf`  | `scanf("%Lf", &numero);`           |

### Notas sobre el uso de `scanf`

1. **Entrada de cadenas (`%s`):**
    - `scanf` lee una cadena de caracteres hasta que encuentra un espacio o un salto de línea.
    - Si deseas incluir espacios en la entrada, considera usar `fgets` en lugar de `scanf`.

2. **Direcciones de memoria:**
    - Excepto para cadenas (`char[]`), todos los demás tipos requieren que pases la dirección de memoria del valor donde se almacenará el dato. Esto se logra con el operador `&`.

3. **Validaciones adicionales:**
    - Siempre verifica que el usuario ingrese el tipo de dato esperado para evitar errores.

### Ejemplo de Uso General

**Código:**
```c
#include <stdio.h>

int main() {
    int entero;
    float flotante;
    char caracter;
    char cadena[100];

    printf("Introduce un entero: ");
    scanf("%d", &entero);

    printf("Introduce un flotante: ");
    scanf("%f", &flotante);

    printf("Introduce un carácter: ");
    scanf(" %c", &caracter); // Nota: el espacio antes de %c consume caracteres residuales

    printf("Introduce una cadena: ");
    scanf("%s", cadena);

    printf("\nResultados:\n");
    printf("Entero: %d\n", entero);
    printf("Flotante: %.2f\n", flotante);
    printf("Carácter: %c\n", caracter);
    printf("Cadena: %s\n", cadena);

    return 0;
}
```

### Salida Esperada
Supongamos que el usuario introduce los valores siguientes:
```
42
3.14
A
Hola
```

El programa generará la siguiente salida:
```
Resultados:
Entero: 42
Flotante: 3.14
Carácter: A
Cadena: Hola
```

---
