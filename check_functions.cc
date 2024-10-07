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

** Archivo check_functions.cc: Implementación de las funciones de chequeo de parámetros.
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      02/10/2024 - Creacion (primera version) del codigo
**      05/10/2024 - Funciones de chequeo de paso de argumentos
**      06/10/2024 - Creacion de funciones de validacion de ficheros
**/

#include <regex>
#include <iostream>
#include "check_functions.h"

/**
 * @brief Validates the extension of the input file
 * @param string  
 * @return bool-type. True if the file is accepted. False otherwise
 */
bool ValidateFile (const std::string& name) {
  if (name.find('.') == std::string::npos) {
    return false;  
  }
  std::regex pattern (R"((.*)\.(cc|cpp|h|hpp)$)");
  return std::regex_match(name, pattern);
}

/**
 * @brief Uses ValidateFile function. Acts in consequence of the returned type
 * @param string  
 */
void CheckFileError (const std::string& name) {
  if (ValidateFile(name)) return;
  std::cerr << "Error in input file: Wrong extension. Please, try \"p04_code_anylizer --help\" for further information" << std::endl;
  exit(EXIT_FAILURE);
}

/**
 * @brief Validates the line of commands and uses Help, Usage and CheckFileError functions
 * @param int argc  
 * @param char* argv[]
 */
void ValidateCommand(int argc, char* argv[]) {
  if (argc == 2 && std::string(argv[1]) == "--help") {
    Help();
    exit(EXIT_SUCCESS);
  }
  if (argc != 3) {
    Usage();
    exit(EXIT_FAILURE);
  }
  CheckFileError(std::string(argv[1]));
}

/**
 * @brief Prints Help to the user
 */
void Help () {
    std::cout << "./p04_code_analyzer -- Code analyzer\n"
              << "Usage:          ./p04_code_analyzer filein.txt fileout.txt\n"
              << "\n"
              << "filein.cc:       Input file, with extensions: .cc, .cpp, .h, .hpp\n"
              << "fileout.txt:     Output file with the results of the analysis\n"
              << "\n";
}

/**
 * @brief Prints how to use the program
 */
void Usage() {
  std::cout << "How to use: ./p04_code_analyzer filein.txt fileout.txt\n"
            << "Try 'p04_code_analyzer --help' for further information\n";
}