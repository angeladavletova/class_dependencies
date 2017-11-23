#include "command_enum.h"

std::string enum_to_string (command_enum c)
{
  switch (c)
    {
    case command_enum::tr:
      return "tr";
    case command_enum::cd:
      return "cd";
    case command_enum::ls:
      return "ls";
    case command_enum::quit:
      return "quit";
    case command_enum::END:
      break;
    }
  return "";
}
