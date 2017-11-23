#include <fstream>
#include <iostream>
#include "class_files_data.h"

class_files_data::class_files_data ()
{
}

static bool delete_filename_extension (std::string &s)
{
  int i = s.length () - 1;
  while (i >= 0)
    {
      if (s[i] == '.')
        break;
      i--;
    }
  if (i == -1)
    return false;
  s.erase(s.begin () + i, s.end ());
  return true;
}

static std::string make_file_name_from_path (const std::string &s)
{
  int i = 0;
  std::string name;
  while (i < static_cast<int> (s.length ()))
    {
      if (s[i] != '/')
        name += s[i];
      else
        name.clear ();
      i++;
    }
  return name;
}

std::string class_files_data::init (std::string header_file_path)
{
  std::ifstream file_h (header_file_path);
  if (!file_h)
    return header_file_path + " does not exist\n";
  file_h.close();
  m_files_names.push_back (header_file_path);

  delete_filename_extension (header_file_path);
  header_file_path += ".cpp";
  std::ifstream file_cpp (header_file_path);
  if (file_cpp)
    {
      m_files_names.push_back (header_file_path);
      file_cpp.close();
    }
  return {};
}

class_files_data::~class_files_data () = default;
