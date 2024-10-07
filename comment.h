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

** Archivo comment.h: Declaración de la clase comentario
**      Contiene las declaraciones de la clase comentario
**      
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      02/10/2024 - Creacion (primera version) del codigo
**      05/10/2024 - Adición de setters adicionales
**/

#ifndef COMMENT_H
#define COMMENT_H

#include <iostream>
#include <regex>
#include <string>

class Comment {
 private:
  int start_line_;
  int finish_line_;
  std::string content_;
  bool description_;
 public:
  //Constructors
  Comment (int start_line, int finish_line, std::string content) : start_line_(start_line), finish_line_(finish_line), content_(content), description_(false) {}
  Comment () = default;
  //Getters
  int getStartLine () const {return start_line_;}
  int getFinishLine () const {return finish_line_;}
  bool getDescription () const {return description_;}
  std::string getContent () const {return content_;}
  //Setters
  void setStartLine (int start) {start_line_ = start;}
  void setFinishLine (int finish) {finish_line_ = finish;}
  void setContent (const std::string& content) {content_ = content;}
  void setDescription (const bool description) {description_ = description;}
  
  static bool DetectComment(const std::string& line, std::smatch& result, bool& in_comment, std::string& comment_content, int line_number, Comment& comment, bool& is_first);


};
std::ostream& operator<<(std::ostream& os, const Comment&);


#endif