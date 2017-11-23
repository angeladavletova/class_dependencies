#pragma once

enum class command_enum
{
  tr,
  cd,
  ls,
  quit,

  END
};

std::string enum_to_string (command_enum c);
