#include <fstream>
#include <iostream>
#include "class_files_data.h"

class_files_data::class_files_data ()
{
}

static bool delete_filename_extension (std::string &s)
{
  int i = s.length ();
  while (i >= 0)
    {
      if (s[i] == '.')
        {
          s.pop_back ();
          return true;
        }
      s.pop_back ();
      i--;
    }
  return false;
}

static std::string make_file_name_from_path (const std::string &s)
{
  int i = 0;
  std::string name;
  while (i < s.length ())
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
  //проверка на .h
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

std::vector<std::unique_ptr<class_files_data>> class_files_data::create_dependencies ()
{
  return {};
}

class_files_data::~class_files_data () = default;
