#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTOS 100
#define MAX_DESCRIPCION 100

typedef struct {
    char nombre[MAX_DESCRIPCION];
    char descripcion[MAX_DESCRIPCION];
    int cantidad;
    float precio;
} Producto;

void mostrarMenu(Producto productos[], int numProductos) {
    printf("Menú:\n");
    for (int i = 0; i < numProductos; i++) {
        printf("%d Producto: %s -Descripcion: %s - Cantidad: %d - Precio: %.2f\n",
               i + 1, productos[i].nombre, productos[i].descripcion,
               productos[i].cantidad, productos[i].precio);
    }
    printf("\n");
}

void agregarProducto(Producto productos[], int *numProductos) {
    if (*numProductos >= MAX_PRODUCTOS) {
        printf("El menú está completo. No se pueden agregar más productos.\n\n");
        return;
    }

    Producto nuevoProducto;
    printf("Ingrese el nombre del nuevo producto: ");
    fgets(nuevoProducto.nombre, MAX_DESCRIPCION, stdin);
    nuevoProducto.nombre[strcspn(nuevoProducto.nombre, "\n")] = '\0'; 

    printf("Ingrese la descripción del nuevo producto: ");
    fgets(nuevoProducto.descripcion, MAX_DESCRIPCION, stdin);
    nuevoProducto.descripcion[strcspn(nuevoProducto.descripcion, "\n")] = '\0';

    printf("Ingrese la cantidad del nuevo producto: ");
    scanf("%d", &nuevoProducto.cantidad);

    printf("Ingrese el precio del nuevo producto: ");
    scanf("%f", &nuevoProducto.precio);

    productos[*numProductos] = nuevoProducto;
    (*numProductos)++;

    printf("El producto ha sido agregado al menú.\n\n");
}

void reemplazarProducto(Producto productos[], int numProductos) {
    int indice;
    printf("Ingrese el número del producto que desea reemplazar: ");
    scanf("%d", &indice);

    if (indice < 1 || indice > numProductos) {
        printf("El número de producto ingresado no es válido.\n\n");
        return;
    }

    Producto nuevoProducto;
    printf("Ingrese el nombre del nuevo producto: ");
    fgets(nuevoProducto.nombre, MAX_DESCRIPCION, stdin);
    nuevoProducto.nombre[strcspn(nuevoProducto.nombre, "\n")] = '\0'; 

    printf("Ingrese la descripción del nuevo producto: ");
    fgets(nuevoProducto.descripcion, MAX_DESCRIPCION, stdin);
    nuevoProducto.descripcion[strcspn(nuevoProducto.descripcion, "\n")] = '\0'; 

    printf("Ingrese la cantidad del nuevo producto: ");
    scanf("%d", &nuevoProducto.cantidad);

    printf("Ingrese el precio del nuevo producto: ");
    scanf("%f", &nuevoProducto.precio);

    productos[indice - 1] = nuevoProducto;

    printf("El producto ha sido reemplazado en el menú.\n\n");
}

void eliminarProducto(Producto productos[], int *numProductos) {
    int indice;
    printf("Ingrese el número del producto que desea eliminar: ");
    scanf("%d", &indice);

    if (indice < 1 || indice > *numProductos) {
        printf("El número de producto ingresado no es válido.\n\n");
        return;
    }

    for (int i = indice - 1; i < *numProductos - 1; i++) {
        productos[i] = productos[i + 1];
    }

    (*numProductos)--;

    printf("El producto ha sido eliminado del menú.\n\n");
}

int main() {
    Producto productos[MAX_PRODUCTOS] = {
        {"Camisetas", "Contamos con camisetas de todas las tallas para cualquier deporte", 50, 12.00},
        {"Pantalonetas", "Contamos con pantalonetas de todas las tallas para cualquier deporte", 50, 10.00},
        {"Zapatos deportivos", "Contamos con zapatos deportivos de todas las tallas para cualquier deporte", 25, 40.00},
        {"Balones", "Contamos con balones para cualquier deporte", 100, 50.00},
        {"Medias", "Contamos con medias de todas las tallas para cualquier deporte", 35, 2.00}
    };
    int numProductos = 5;
    int opcion;

    do {
        printf("1) Mostrar menú\n");
        printf("2) Agregar producto\n");
        printf("3) Reemplazar producto\n");
        printf("4) Eliminar producto\n");
        printf("0) Salir\n");
        printf("Escoge una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                mostrarMenu(productos, numProductos);
                break;

            case 2:
                agregarProducto(productos, &numProductos);
                break;

            case 3:
                reemplazarProducto(productos, numProductos);
                break;

            case 4:
                eliminarProducto(productos, &numProductos);
                break;

            case 0:
                printf("¡Hasta luego!\n");
                break;

            default:
                printf("La opción que elegiste no existe.\n\n");
                break;
        }
    } while (opcion != 0);

    return 0;
}