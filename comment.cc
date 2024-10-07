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

** Archivo comment.cc: Implementación de la clase comentario 
**      Contiene los metodos necesarios para detectar y manejar los comentarios en un codigo
**      
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      02/10/2024 - Creacion (primera version) del codigo
**      05/10/2024 - Sobrecarga del operador <<
**/

#include <iostream>
#include <regex>

#include "comment.h"

/**
 * @brief Function that detects comments in a code
 * @param string: Line of text 
 * @param smatch
 * @return bool-type: True if comment detected. False otherwise 
 */
bool Comment::DetectComment (const std::string& line, std::smatch& result) {
  std::regex pattern (R"((/\*.*\*/|//.*))");
  return std::regex_search(line, result, pattern);
}

/**
 * @brief Overload of << operator for Comment class
 * @param ostream  
 * @param comment
 * @return ostream
 */
std::ostream& operator<<(std::ostream& os, const Comment& comment) {
  if (comment.getStartLine() != comment.getFinishLine() && (comment.getStartLine() != 1)) {
    os << "[Line " << comment.getStartLine() << "-" << comment.getFinishLine() << "]\n" << comment.getContent() << std::endl;
  }
  if (comment.getDescription()) {
    os << "[Line " << comment.getStartLine() << "-" << comment.getFinishLine() << "] DESCRIPTION" << std::endl;
  }
  if (comment.getStartLine() == comment.getFinishLine()) {
    os << "[Line " << comment.getStartLine() <<"] " << comment.getContent() << std::endl;
  }
  return os;
}
