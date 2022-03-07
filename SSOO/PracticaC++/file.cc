/**
 * @file file.cc
 * @author Daniel Felipe Gómez Arisitizabal (alu0101438139@ull.edu.es)
 * @brief Definiciones de las funciones de la clase File
 * @version 0.1
 * @date 2021-12-13
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "file.h"

/**
 * @brief Constructor de la clase File, recibe un nombre y abre el
 * correspondiente fichero
 *
 * @param name_file
 */
File::File(const std::string &name_file) {
  char char_name_file[50];
  strcpy(char_name_file,name_file.c_str());
  file_descriptor_ = open(char_name_file, O_RDONLY);
  if (file_descriptor_ < 0) {
    throw std::system_error(errno, std::system_category(),
                            "ViewNet: No se pudo abrir el archivo");
  }
}

/**
 * @brief Destructor de la clase File, cierra el fichero utilizando su
 * respectivo 'file descriptor'
 *
 */
File::~File() {
  close(file_descriptor_);
}

/**
 * @brief Llama a la función read, devuelve el número de bits leídos y guarda lo
 * leído en parámetro buf
 *
 * @param fd
 * @param buf
 * @param count
 * @return int con el número de bits leídos
 */
int File::Read(int fd, void* buf, int count) {
  return read(fd, buf, count);
}

/**
 * @brief Escribe un mensaje en el buf pasado por parámetro
 * 
 * @param fd 
 * @param buf 
 * @param count 
 * @return int devuelve el el número de bits escritos
 */
int File::Write(int fd, void* buf, int count) {
  return write(fd, buf, count);
}

/**
 * @brief Retorna el descriptor de fichero obtenido de abrir el fichero
 *
 * @return int descriptor del fichero
 */
int File::GetFileDescriptor() {
  return file_descriptor_;
}