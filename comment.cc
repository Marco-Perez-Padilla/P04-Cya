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
 * @param smatch: Result
 * @param bool: In_comment, bool to know if we are inside multiline comment
 * @param string: comment content. acumulates the content in case of multiline comment
 * @param int: Line number
 * @param Comment: Comment where we will set the values in each case
 * @param bool: Is_first, bool to know if we've detected the description
 * @return bool-type: True if comment detected. False otherwise 
 */
bool Comment::DetectComment(const std::string& line, std::smatch& result, bool& in_comment, std::string& comment_content, int line_number, Comment& comment, bool& is_first) {
  std::regex pattern_single(R"(//.*)");  
  std::regex pattern_multistart(R"(/\*.*)");  
  std::regex pattern_multiend(R"(.*\*/)");  
  
  // If not inside a multiline comment
  if (!in_comment) {
    if (std::regex_search(line, result, pattern_single)) {
      // Single line comment case
      comment.setStartLine(line_number);
      comment.setFinishLine(line_number);
      comment.setContent(result.str());
      comment.setDescription(false);
      return true;
    } else if (std::regex_search(line, result, pattern_multistart)) {
      // Detection of multiline comment
      in_comment = true;
      comment.setStartLine(line_number);
      comment_content = line;
      return false;
    }
  } else {
    // If inside multiline comment
    comment_content += "\n" + line;
    if (std::regex_search(line, result, pattern_multiend)) {
      // Detect finish of multiline comment
      in_comment = false;
      comment.setFinishLine(line_number);
      comment.setContent(comment_content);
      if (is_first) {
        comment.setDescription(true);
        is_first = false;
      }
      return true;
    }
  }
  
  return false;
}


/**
 * @brief Overload of << operator for Comment class
 * @param ostream  
 * @param comment
 * @return ostream
 */
std::ostream& operator<<(std::ostream& os, const Comment& comment) {
  if (comment.getStartLine() != comment.getFinishLine() && !comment.getDescription()) {
    os << "[Line " << comment.getStartLine() << "-" << comment.getFinishLine() << "]\n" << comment.getContent() << std::endl;
  }

  if (comment.getDescription() && comment.getStartLine() != comment.getFinishLine()) {
    os << "[Line " << comment.getStartLine() << "-" << comment.getFinishLine() << "] DESCRIPTION" << std::endl;
  }

  if (comment.getStartLine() == comment.getFinishLine() && comment.getDescription()) {
    return os; 
  }

  if (comment.getStartLine() == comment.getFinishLine() && !comment.getDescription()) {
    os << "[Line " << comment.getStartLine() << "] " << comment.getContent() << std::endl;
  }

  return os;
}


