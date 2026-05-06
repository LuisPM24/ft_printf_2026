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

**Este proyecto no ha usado IA generativa.**

# Bonus
Este ejercicio contiene una **sección bonus** en la que se añade el uso de ***`flags`***:

- ***`hash`***: Añade prefijo en hexadecimal.
- ***`zero`***: Rellena con `0` en vez de con `espacios`.
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

## Parte Obligatoria
### ft_printf.h

Archivo cabecera (`header file`) en el que se incluyen todas las referencias a otras funciones de la parte obligatoria. Se encuentra declarado en todos los archivos `.c` de este repositorio mediante la línea:

```C
#include "ft_printf.h"
```

### ft_printf.c

Contiene la función principal `ft_printf` que lanza el resto de funciones y devuelve un valor equivalente a la cantidad de carácteres impresos por pantalla.

```C
int	ft_printf(char const *str, ...);
```

### printf_putchar

Imprime un carácter `char` por pantalla y devuelve un `1`, en caso de que se imprima, o un `0`, en caso de que no.

```C
int	printf_putchar(const char chr);
```

### printf_putstr

Imprime una cadena de carácteres `char *` por pantalla y devuelve la cantidad de carácteres impresos en pantalla.

```C
int	printf_putstr(const char *str);
```

### printf_putvoid

Imprime la dirección de memoria `void *` y devuelve la cantidad de carácteres impresos en pantalla.

```C
int	printf_putvoid(const void *ptr);
```

### printf_putnbr

Imprime un número entero decimal `int` y devuelve la cantidad de carácteres impresos en pantalla.

```C
int	printf_putnbr(int nbr);
```

### printf_putunnbr

Imprime un número decimal sin signo `unsigned int` y devuelve la cantidad de carácteres impresos en pantalla.

```C
int	printf_putunnbr(unsigned int nbr);
```

### printf_putlwrhex

Imprime un número decimal sin signo `unsigned int` en un número hexadecimal, con carácteres en minúscula, y devuelve la cantidad de carácteres impresos en pantalla.

```C
int	printf_putlwrhex(unsigned int nbr);
```

### printf_putupphex

Imprime un número decimal sin signo `unsigned int` en un número hexadecimal, con carácteres en mayúscula, y devuelve la cantidad de carácteres impresos en pantalla.

```C
int	printf_putupphex(unsigned int nbr);
```

## Parte Bonus

### ft_printf_bonus.h

Archivo cabecera (`header file`) en el que incluye todas las funciones de la parte bonus, una referencia a `ft_printf.h` y la estructura `t_format`:

```C
typedef struct s_format
{
	int		minus;
	int		zero;
	int		dot;
	int		precision;
	int		width;
	int		hash;
	int		space;
	int		plus;
	char	chr;
}	t_format;
```

Se encuentra referenciado en todos los archivos de la parte bonus de la siguiente manera:

```C
#include "ft_printf_bonus.h"
```

### ft_printf_bonus.c

Contiene la función principal `ft_printf` que lanza el resto de funciones, lanza un parser para el manejo de `flags`, `width` y `precision` y devuelve un valor equivalente a la cantidad de carácteres impresos por pantalla. **ATENCIÓN: ¡ESTA FUNCIÓN SOLAPA A LA PARTE OBLIGATORIA POR LO QUE SE HA DE EJECUTAR DE MANERA SEPARADA!**

```C
int	ft_printf(char const *str, ...);
```

### init_format

Función que se usa para inicializar todos los valores de un formato `t_format` a `0`.

```C
void	init_format(t_format *format);
```

### ft_strlen

Devuelve la longitud de la cadena `char *`.

```C
int		ft_strlen(const char *str);
```

### is_flag

Devuelve `1` en caso de que el carácter `char` pasado corresponda con una `flag`. En caso contrario, devuelve `0`.

```C
int		is_flag(char chr);
```

### parse_format

Función que se encarga de rellenar y completar un formato `t_format` con los valores otorgados por el usuario mediante la cadena de carácteres `char *`.

```C
void	parse_format(const char *str, int *pos, t_format *format);
```

### manage_padding

Imprime una cantidad de espacios `width` y devuelve la cantidad impresa.

```C
int		manage_padding(int padd, int amount);
```

### manage_padding_char

Imprime una cantidad de caráctes `char` y devuelve la cantidad impresa.

```C
int		manage_padding_char(int padd, int amount, char c);
```

### print_zeroes

Imprime la cantidad `int` de `0` y devuelve la cantidad impresa.

```C
int		print_zeroes(int amount_zero);
```

### printf_putchar_bonus

Versión bonus de la función obligatoria **`printf_putchar`**. Esta función también maneja la `flag` `minus` y el uso de `width`.

```C
int		printf_putchar_bonus(char chr, t_format format);
```

### printf_putstr_bonus

Versión bonus de la función obligatoria **`printf_putstr`**. Esta función también maneja la `flag` `minus` y el uso de `width` y `precision`.

```C
int		printf_putstr_bonus(char *str, t_format format);
```

### printf_putvoid_bonus

Versión bonus de la función obligatoria **`printf_putvoid`**. Esta función también maneja la `flag` `minus` y el uso de `width`.

```C
int		printf_putvoid_bonus(const void *ptr, t_format format);
```

### printf_putnbr_bonus

Versión bonus de la función obligatoria **`printf_putnbr`**. Esta función maneja el los `flags` `minus`, `space`, `plus` y `zero` junto con el `width` y la `precision`.

```C
int		printf_putnbr_bonus(int nbr, t_format format);
```

### printf_putunnbr_bonus

Versión bonus de la función obligatoria **`printf_putunnbr`**. Esta función maneja el los `flags` `minus` y `zero` junto con el `width` y la `precision`.

```C
int		printf_putunnbr_bonus(unsigned int nbr, t_format format);
```

### printf_putlwrhex_bonus

Versión bonus de la función obligatoria **`printf_putlwrhex`**. Esta función maneja el los `flags` `minus`, `zero` y `hash` junto con el `width` y la `precision`.

```C
int		printf_putlwrhex_bonus(unsigned int nbr, t_format format);
```

### printf_putupphex_bonus

Versión bonus de la función obligatoria **`printf_putupphex`**. Esta función maneja el los `flags` `minus`, `zero` y `hash` junto con el `width` y la `precision`.

```C
int		printf_putupphex_bonus(unsigned int nbr, t_format format);
```

### Funciones aux
Las `funciones aux` son exactamente iguales a sus versiones originales **(ver tabla de equivalencias)**. La razón de estas funciones es que la parte bonus impide comunicar las funciones obligatorias 

#### Tabla de equivalencias
- `aux_printf_putchar_bonus` --> `printf_putchar`
- `aux_printf_putstr_bonus` --> `printf_putstr`
- `aux_printf_putnbr_bonus` --> `printf_putnbr`
- `aux_printf_putunnbr_bonus` --> `printf_putunnbr`
- `aux_printf_putlwrhex_bonus` --> `printf_putlwrhex`
- `aux_printf_putupphex_bonus` --> `printf_putupphex`