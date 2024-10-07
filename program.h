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

** Archivo comment.h: Declaración de la clase programa
**      Contiene las declaraciones de la clase programa
**      
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      02/10/2024 - Creacion (primera version) del codigo
**/

#ifndef PROGRAM_H
#define PROGRAM_H


#include <iostream>
#include <regex>
#include <string>

#include "comment.h"
#include "variable.h"
#include "loop.h"
#include "main.h"

class Program {
 private:
  std::string name_;
  std::vector<Comment> comments_;
  std::vector<Variable> variables_;
  std::vector<Loop> loops_;
  Main is_main_;
 public:
  //Constructor
  Program(const std::string& file);
  //Getters
  const std::string getName () const {return name_;}
  std::vector<Comment> getComments () const {return comments_;}
  std::vector<Variable> getVariables () const {return variables_;}
  std::vector<Loop> getLoops () const {return loops_;}
  Main getIsMain () const {return is_main_;}
  
  void Write(const std::string&);

};

#endif