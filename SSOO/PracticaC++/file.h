/**
 * @file file.h
 * @author Daniel Felipe Gómez Arisitizabal (alu0101438139@ull.edu.es)
 * @brief Declaración de la clase File
 * @version 0.1
 * @date 2021-12-13
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#pragma once
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string>
#include <unistd.h>
#include "tools.h"
#include "socket.h"

class File {
 public:
  File(const std::string &name_file);
  ~File();
  int Read(int fd, void* buf, int count);
  int Write(int fd, void* buf, int count);
  int GetFileDescriptor();
 private:
  int file_descriptor_;
};