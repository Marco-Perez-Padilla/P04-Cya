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

** Archivo variable.h: Declaración de la clase variable
**      Contiene las declaraciones de los metodos de deteccion de variables
**      
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      02/10/2024 - Creacion (primera version) del codigo
**      05/10/2024 - Creacion de los metodos de deteccion del tipo de variables
**/

#ifndef VARIABLE_H
#define VARIABLE_H

#include <iostream>
#include <regex>

class Variable {
 private:
  int line_;
  std::string type_;
  std::string name_;
 public:
  Variable (int line, std::string type, std::string name) : line_(line), type_(type), name_(name) {}

  int getLine() const {return line_;}
  std::string getType() const {return type_;}
  std::string getName() const {return name_;}

  static bool DetectType (const std::string&, std::smatch&);
};
std::ostream& operator<<(std::ostream& os, const Variable&);

#endif