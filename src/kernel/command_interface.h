#pragma once

#include "src/pch/pch.h"

class dependencies_data;

class command_interface
{
  std::unique_ptr<dependencies_data> m_data;

  bool read_and_execute_command ();
  void print_message (std::string str);
public:
  command_interface ();
  ~command_interface ();

  void start_read_commands ();
};
