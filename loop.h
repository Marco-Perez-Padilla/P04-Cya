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

** Archivo loop.h: Declaración de la clase loop
**      Contiene las declaraciones de los metodos de deteccion de bucles
**      
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      02/10/2024 - Creacion (primera version) del codigo
**      05/10/2024 - Creacion de los metodos de deteccion
**/

#ifndef LOOP_H
#define LOOP_H

#include <iostream>
#include <regex>

class Loop {
 private:
  int line_;
  std::string type_;
 public:
  Loop (int line, std::string type) : line_(line), type_(type) {}

  int getLine () const {return line_;}
  std::string getType () const {return type_;}

  static bool DetectLoop (const std::string&, std::smatch&);
};
std::ostream& operator<<(std::ostream& os, const Loop&);

#endif