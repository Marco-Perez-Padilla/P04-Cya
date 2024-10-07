/**
** Universidad de La Laguna
** Escuela Superior de Ingenieria y Tecnologia
** Grado en Ingenieria Informatica
** Asignatura: Computabilidad y Algoritmia
** Curso: 2º
** Practica 3: Expresiones regulares
** Autor: Marco Pérez Padilla
** Correo: alu0101469348@ull.edu.es
** Fecha: 05/10/2024

** Archivo main.cc: Implementación de la clase main
**      Contiene las implementaciones de las funciones de deteccion del main
**      
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      05/10/2024 - Creacion (primera version) del codigo
**/

#include <iostream>
#include <regex>

#include "main.h"

/**
 * @brief Detects if the input file is a main program or not
 * @param string  
 * @param smatch
 * @return bool-type. Returns true if main is detected. False otherwise.
 */
bool Main::DectecMain (const std::string& line, std::smatch& result) {
  std::regex pattern (R"(\bint\s+main\s*\(.*\))");
  return std::regex_search(line, result, pattern);
}

/**
 * @brief Overload of << operator for Main class
 * @param ostream  
 * @param main
 * @return ostream
 */
std::ostream& operator<<(std::ostream& os, const Main& main1) {
  if (main1.getMain()) {
    os << "True" << std::endl;
  } else {
    os << "False" << std::endl;
  }
  return os;
}

