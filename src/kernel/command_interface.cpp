#include "command_interface.h"

#include "src/kernel/dependencies_data.h"
#include "src/helpers/string_functions.h"
#include "src/kernel/command_enum.h"

#include <iostream>

command_interface::command_interface ()
{
  m_data.reset (new dependencies_data);
}

void command_interface::start_read_commands ()
{
  while (read_and_execute_command ()) {}
}

bool command_interface::read_and_execute_command ()
{
  std::string command_str;
  std::cin >> command_str;
  auto words = split_into_words (command_str);

  if (words.empty ())
    {
      print_message ("Enter command");
      return true;
    }

  auto command = words[0];
  switch (string_to_enum<command_enum> (command))
    {
    case command_enum::tr:
      // call function
      break;
    case command_enum::ls:
      // call function
      break;
    case command_enum::cd:
      // call function
      break;
    case command_enum::quit:
      return false;
    case command_enum::END:
      print_message (std::string ("Command ") + command + "is not exist");
      break;
    }
  return true;
}

void command_interface::print_message (std::string str)
{
  std::cout << "WARNING" << ": " << str << "\n";
}

command_interface::~command_interface () = default;

