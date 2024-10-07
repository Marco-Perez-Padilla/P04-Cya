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

** Archivo variable.cc: Implementación de la clase variable
**      Contiene los metodos de deteccion de variables
**      
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      02/10/2024 - Creacion (primera version) del codigo
**      05/10/2024 - Creacion de los metodos de deteccion del tipo de variables
**/

#include <iostream>
#include <regex>

#include "variable.h"

/**
 * @brief Detects a variable
 * @param string  
 * @param smatch
 * @return bool-type. True if a variable is detected. False otherwise
 */
bool Variable::DetectType (const std::string& line, std::smatch& result) {
  std::regex pattern (R"((int|double)\s+([A-Za-z_][A-Za-z0-9_]*\s*(=\s*[^;]+)?);)");
  return std::regex_search(line, result, pattern);
}

/**
 * @brief Overload of << operator of class Variable
 * @param ostream
 * @param variable  
 * @return ostream
 */
std::ostream& operator<<(std::ostream& os, const Variable& variable) {
  std::string capital_variable = variable.getType();
  std::transform(capital_variable.begin(), capital_variable.end(), capital_variable.begin(), ::toupper);
  os << "[Line " << variable.getLine() << "] " << capital_variable << ": " << variable.getName() << std::endl;
  return os;
}