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

** Archivo check_functions.h: Declaracion de las funciones de chequeo de parámetros.
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      02/10/2024 - Creacion (primera version) del codigo
**      05/10/2024 - Funciones de chequeo de paso de argumentos
**      06/10/2024 - Creacion de funciones de validacion de ficheros
**/

#include <iostream>

bool ValidateFile (const std::string& name);
void CheckFileError (const std::string& name);
void ValidateCommand(int argc, char* argv[]);
void Help ();
void Usage();