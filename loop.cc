/**
** Universidad de La Laguna
** Escuela Superior de Ingenieria y Tecnologia
** Grado en Ingenieria Informatica
** Asignatura: Computabilidad y Algoritmia
** Curso: 2º
** Practica 3: Expresiones regulares
** Autor: Marco Pérez Padilla
** Correo: alu0101469348@ull.edu.es
** Fecha: 02/10/2024

** Archivo loop.cc: Implementación de la clase loop
**      Contiene las implementaciones de las funciones de deteccion de bucles
**      
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      02/10/2024 - Creacion (primera version) del codigo
**      05/10/2024 - Creacion de los metodos de deteccion
**/

#include <iostream>
#include <regex>

#include "loop.h"

/**
 * @brief Detects a loop
 * @param string  
 * @param smatch
 * @return bool-type. True if a loop is detected. False otherwise
 */
bool Loop::DetectLoop (const std::string& line, std::smatch& result) {
  std::regex pattern (R"(\b(for|while)\s*\(.*\))");
  return std::regex_search(line, result, pattern);
}

/**
 * @brief Overload of << operator of class Loop
 * @param ostream
 * @param loop  
 * @return ostream
 */
std::ostream& operator<<(std::ostream& os, const Loop& loop) {
  os << "[Line " << loop.getLine() << "] LOOP: " << loop.getType() << std::endl;
  return os;
}

