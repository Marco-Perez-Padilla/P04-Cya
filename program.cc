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

** Archivo program.cc: Implementación de la clase programa
**      Contiene los metodos necesarios para leer un codigo y escribir el resultado del analisis en un fichero
**      
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      02/10/2024 - Creacion (primera version) del codigo
**      06/10/2024 - Creación de los métodos de escritura-lectura
**/

#include "program.h"
#include <fstream>

/**
 * @brief Constructor of Program class
 * @param string name of the file to be analyzed 
 */
Program::Program (const std::string& file) : name_ (file) {
  std::ifstream infile(file);
  if (!infile.is_open()) {
    std::cerr << "Error: File couldn't be opened " << file << ". Try \"p04_code_anylizer --help\" for further information " << std::endl;
    return;
  }

  std::string line;
  int line_number {1};
  bool is_first {true};
  bool in_comment {false};
  std::string comment_content;
      Comment comment;

  while (std::getline(infile, line)) {
    std::smatch result;

    if (Main::DectecMain(line, result)) {
      is_main_.setMain(true);
    }

    if (Comment::DetectComment(line, result, in_comment, comment_content, line_number, comment, is_first)) {
      comments_.push_back(comment);
    } 

    if (Variable::DetectType(line, result)) {
      Variable new_var(line_number, result.str(1), result.str(2)); 
      variables_.push_back(new_var);
    }

    if (Loop::DetectLoop(line, result)) {
      Loop new_loop(line_number, result.str(1));
      loops_.push_back(new_loop);
    }
    
    ++line_number;
  }
}

/**
 * @brief Function that writes in an output file the analysis
 * @param string
 */
void Program::Write(const std::string& out) {
  std::ofstream outfile (out);
  if (!outfile.is_open()) {
    std::cerr << "Error: File couldn't be opened " << out << ". Try \"p04_code_anylizer --help\" for further information " << std::endl;
    return;
  }

  outfile << "PROGRAM: " << getName() << std::endl;
  if (!getComments().empty()) {
    if (!getComments().empty() && getComments()[0].getDescription()) {
      outfile << "DESCRIPTION:" << std::endl;
      outfile << getComments()[0].getContent() << std::endl;
      outfile << std::endl;
    }
  }
  if (!getVariables().empty()) {
    outfile << "VARIABLES:" << std::endl;
    for (const auto& var : getVariables()) {
      outfile << var;  
    }
    outfile << std::endl;
  }
  if (!getLoops().empty()) {
    outfile << "STATEMENTS." << std::endl;
    for (const auto& loop : getLoops()) {
      outfile << loop;  
    }
    outfile << std::endl;
  }
  outfile << "MAIN:" << std::endl;
  outfile << getIsMain() << std::endl;
  if (!getComments().empty()) {
    outfile << "COMMENTS:" << std::endl;;
    for (const auto& comment : getComments()) {
      outfile << comment;  
    }  
  }
}
