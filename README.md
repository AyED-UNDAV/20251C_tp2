# Trabajo Práctico 2

## Contexto

Una heladería nos pasa sus ventas y es necesario decodificar el mensaje. El mensaje lo envía a través de una función que está en el archivo que NO debemos modificar, el `input_helados.cpp`.

## Consigna

En el archivo `helados_decoder.cpp` debemos procesar el mensaje que nos llega e imprimir por pantalla por cada pedido el número de pedido, el tamaño y los gustos.

Por ejemplo, para el pedido

`DC,c|DV,g|C,g|DVC,g\0`

debe imprimir:

```
Pedido 1
Tamaño chico
Gustos: Dulce de Leche, Chocolate

Pedido 2
Tamaño grande
Gustos: Dulce de leche, Vainilla

Pedido 3
Tamaño grande
Gustos: Chocolate

Pedido 4
Tamaño grande
Gustos: Dulce de leche, Vainilla, Chocolate
```

## Formato del mensaje

🧠 ¿Cómo está armado el mensaje?

Cuando generamos el reporte de helados, estamos creando un texto grande que tiene varios registros. Cada registro representa un pedido de helado.

Cada parte del mensaje significa algo:

1. Los gustos

    Se eligen entre 1 y 5 gustos.

    Cada gusto está representado por una sola letra:

        D = Dulce de leche

        C = Chocolate

        V = Vainilla


👉 Ejemplo de gustos juntos: DVC → significa: Dulce de leche, Vainilla y Chocolate.

2. La coma ,

    Después de los gustos, se agrega una coma ,.

    Esta coma separa los gustos del tamaño del helado.

3. El tamaño (g o c)

    Después de la coma, agregamos una letra que indica el tamaño del helado:

        g → grande

        c → chico

👉 Ejemplo completo de un registro:

DVC,g → Helado de Dulce de leche, Vainilla y Chocolate, tamaño grande.

4. El separador |

    Cada helado (o pedido) se separa del siguiente usando un |.

    Así podemos diferenciar cada registro fácilmente.

👉 Ejemplo con varios pedidos:

DVC,g|CV,c|C,g

Esto significa:

    Primer pedido: Dulce de leche, Vainilla y Chocolate, grande.

    Segundo pedido: Chocolate y Vainilla, chico.

    Tercer pedido: Chocolate, grande.

5. El final del mensaje ('\0')

    En C++, toda cadena de caracteres (char[]) termina con un '\0'.

    Esto lo hacen automáticamente las funciones como strcat.

    Sirve para que el programa sepa dónde termina la cadena y no siga leyendo basura en memoria.

✍️ Resumen gráfico de la estructura:

[gustos][,][tamaño][|][gustos][,][tamaño][|][gustos][,][tamaño]...\0

Ejemplo real:

DC,c|DV,g|C,g|DVC,g\0


## Entregables y forma de entrega

- Se debe entregar un archivo txt contando la estrategia de resolución. Se recomienda primero analizar el problema y luego codificarlo. No es necesario que se extiendan un montón, solo con uno o dos párrafos contándonos con sus palabras cómo van a resolver el problema, está muy bien.
- Se deben comprimir los archivos `.cpp` y el `.txt` en un zip y se deben subir al campus dentro de la entrega.