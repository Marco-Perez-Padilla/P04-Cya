/**
** Universidad de La Laguna
** Escuela Superior de Ingenieria y Tecnologia
** Grado en Ingenieria Informatica
** Asignatura: Computabilidad y Algoritmia
** Curso: 2º
** Practica 4: Expresiones regulares
** Autor: Marco Pérez Padilla
** Correo: alu0101469348@ull.edu.es
** Fecha: 02/10/2024

** Archivo p04_code_analyzer.cc: programa cliente.
**      Contiene la funcion main del proyecto que usa las clases programa, comentario, variable, bucle, principal
**      para analizar un codigo en c++ pasado por linea de comandos. Contiene así mismo las funciones de ayuda y validación.
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      02/10/2024 - Creacion (primera version) del codigo
**      05/10/2024 - Funciones de chequeo de paso de argumentos
**      06/10/2024 - Creacion de funciones de validacion de ficheros
**/

#include "program.h"
#include "check_functions.h"

int main(int argc, char* argv[]) {
  ValidateCommand(argc, argv);
  Program program(argv[1]); 
  program.Write(argv[2]); 

  return 0;
}
