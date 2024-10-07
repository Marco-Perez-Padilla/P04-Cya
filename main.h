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

** Archivo main.h: Declaración de la clase main
**      Contiene los metodos para la deteccion del main
**      
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      05/10/2024 - Creacion (primera version) del codigo
**/

#ifndef MAIN_H
#define MAIN_H

#include <string>
#include <regex>

class Main {
 private:
  bool main_;
 public:
  bool getMain () const {return main_;}
  void setMain (bool main1) {main_ = main1;}
  static bool DectecMain (const std::string& line, std::smatch& result);
};
std::ostream& operator<<(std::ostream& os, const Main& loop);

#endif