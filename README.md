*Este proyecto ha sido creado como parte del currículo de 42 por lupalomi*

# Descripción
Este proyecto consiste en una función que imita el comportamiento de otra función llamada `printf`.

Esta función acepta una cadena de carácteres y los imprime en la salida estándar. También acepta el uso del carácter `%` para recoger e imprimir argumentos pasados por el propio usuario. Las combinaciones posibles son:

- `%c`: Imprime un carácter `char`.
- `%s`: Imprime una cadena de carácteres `char *`.
- `%p`: Imprime un puntero de tipo `void`.
- `%d` y `%i`: Imprime un número decimal entero `int`.
- `%u`: Imprime un número decimal entero sin signo `unsigned int`.
- `%x`: Imprime un número en hexadecimal usando carácteres en minúscula `unsigned int`.
- `%X`: Imprime un número en hexadecimal usando carácteres en mayúscula `unsigned int`.
- `%%`: Imprime el carácter `%`.

**Destacar que estas no son todas las combinaciones existentes en la función original, sino una adaptación de las más usadas.**

Esta función utiliza las librerías `stdarg.h`, para la aceptación de una cantidad indefinida de argumentos y el uso de listas; y `unistd` para el uso de la función `write`.

Un ejemplo de `main.c` que compruebe todas las entradas posibles, de mi función, podría ser el siguiente:

```C
int	main(void)
{
	int				ptr;
	unsigned int	ptr_un;

	ptr = 42;
	ptr_un = 31;
	ft_printf("Debe imprimir el carácter C --> %c\n", 'C');
	ft_printf("Debe imprimir el string 'Hola Mundo!' --> %s\n", "Hola Mundo!");
	ft_printf("Debe imprimir la dirección de memoria de ptr --> %p\n", &ptr);
	ft_printf("Debe imprimir el número guardado en ptr --> %d\n", ptr);
	ft_printf("Debe imprimir el número guardado en ptr --> %i\n", ptr);
	ft_printf("Debe imprimir el número sin signo guardado en ptr_un --> %u\n", ptr_un);
	ft_printf("Debe imprimir el número guardado en ptr_un en hexadecimal con minúsculas --> %x\n", ptr_un);
	ft_printf("Debe imprimir el número guardado en ptr_un en hexadecimal con mayúsculas --> %X\n", ptr_un);
	ft_printf("Debe imprimir el carácter porcentaje --> %%\n");

	return (0);
}
```
# Instrucciones
Este proyecto usa un archivo `Makefile` para compilar todos los archivos del repositorio. Para clonar este proyecto, se debe ejecutar la siguiente línea mediante una terminal, dentro de la carpeta en la que desea usar la función:

```Bash
git clone https://github.com/LuisPM24/ft_printf_2026.git ft_printf
```

Posteriormente, se deberá incluir la siguiente línea en el proyecto donde se desea usar la función:

```C
#include "ft_printf/ft_printf.h"
```

Esta línea permite el uso de todas las funciones pertenecientes al repositorio clonado. Por ello, se recomienda incluir esta línea dentro de un archivo `.h`.

Para compilar los archivos de este proyecto, se deberá ir ejecutar el siguiente comando:

```Bash
cd ft_printf
make
```

Por el contrario, para eliminar los archivos compilados se deberá ejecutar el siguiente comando:

```Bash
cd ft_printf
make fclean
```

Todos los comandos pertenecientes al archivo `Makefile` son los siguientes:

- `make`: Compila todos los archivos de la parte obligatoria.
- `make re`: Elimina y vuelve a compilar los archivos de la parte obligatoria.
- `make bonus`: Compila todos los archivos de la parte bonus **(ver más adelante)**.
- `make clean`: Elimina todos los archivos compilados, a excepción de `libftprintf.a`.
- `make fclean`: Elimina todos los archivos compilados.

# Recursos

Para realizar este proyecto se ha recurido a las siguientes herramientas y páginas web:

- Páginas `man` dentro la propia terminal.
- [Linux man pages online](https://man7.org/linux/man-pages/): Esta página se ha usado para consultar ciertos aspectos de la función original [printf](https://man7.org/linux/man-pages/man3/printf.3.html).

Se requiere un compilador de C (como `cc`) y un sistema compatible con POSIX (Linux o macOS), ya que se utilizan cabeceras estándar como `<unistd.h>`.

**Este proyecto ha usado IA generativa para generar un main de ejemplo para la parte bonus.**

# Bonus
Este ejercicio contiene una **sección bonus** en la que se añade el uso de ***`flags`***:

- ***`hash`***: Añade prefijo en hexadecimal.
- ***`zero`***: Rellena con '0' en vez de con ' '.
- ***`minus`***: Alinea a la izquierda una cantidad de carácteres.
- ***`space`***: Añade un espacio delante de los positivos.
- ***`plus`***: En caso de número positivo, indica el signo.

También se añade el uso de los siguiente elementos:
- ***`width`***: Añade padding si el contenido no ocupa un tamaño máximo.
- ***`precision`***: Se añade un tamaño máximo a la salida. En caso de números, rellena el espacio sobrante con 0.

El proceso tiene el siguiente orden:

```Bash
%[argument$][flags][width][.precision]conversion
```

Mientras que las ***`flags`*** siguen el siguiente orden:

```Bash
[minus][zero][hash][space][plus]
```

Un ejemplo de `main.c` con todos los casos, es el siguiente:

```C
#include <stdio.h>
#include "ft_printf_bonus.h"

int	main(void)
{
	int	x = 42;

	// Test 1
	ft_printf("|%-5c|\n", 'A');
	printf("|%-5c|\n", 'A');

	ft_printf("|%1c|\n", 0);
	printf("|%1c|\n\n", 0);

	// Test 2
	ft_printf("|%-10s|\n", "hola");
	printf("|%-10s|\n", "hola");
	
	ft_printf("|%.3s|\n", "abcdef");
	printf("|%.3s|\n\n", "abcdef");

	// Test 3
	ft_printf("|%-20p|\n", &x);
	printf("|%-20p|\n", &x);

	ft_printf("|%10p|\n", NULL);
	printf("|%10p|\n\n", NULL);

	// Test 4
	ft_printf("|%.5d|\n", 42);
	printf("|%.5d|\n", 42);

	ft_printf("|%+05d|\n", 42);
	printf("|%+05d|\n\n", 42);

	// Test 5
	ft_printf("|%.5u|\n", 42);
	printf("|%.5u|\n", 42);

	ft_printf("|%-8.5u|\n", 42);
	printf("|%-8.5u|\n\n", 42);

	// Test 6
	ft_printf("|%#x|\n", 42);
	printf("|%#x|\n", 42);

	ft_printf("|%#8.5x|\n", 42);
	printf("|%#8.5x|\n\n", 42);

	// Test 7
	ft_printf("|%08X|\n", 42);
	printf("|%08X|\n", 42);

	ft_printf("|%#X|\n", 42);
	printf("|%#X|\n\n", 42);

	// Test 8
	ft_printf("|%5%|\n");
	printf("|%5%|\n");

	ft_printf("|%05%|\n");
	printf("|%05%|\n\n");

	return (0);
}
```

## Propiedades importantes

- `minus` anula a `zero`.
- `precision` anula a `zero` en `%d`, `%i`, `%u`, `%x` y `%X`.
- `plus` anula a `spaces`.
- `hash` solo afecta a `%x` y a `%X` si el número a imprimir es distinto de 0.

# Funciones

Este proyecto se divide en múltiples archivos y funciones que se resumen a continuación:

## ft_printf.h

Archivo cabecera (`header file`) en el que se incluyen todas las referencias a otras funciones. Se encuentra declarado en todos los archivos `.c` de este repositorio mediante la línea:

```C
#include "ft_printf.h"
```