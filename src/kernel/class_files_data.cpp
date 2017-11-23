#include "class_files_data.h"

class_files_data::class_files_data ()
{
}

std::string class_files_data::init (std::string header_file_path)
{
  //проверка на .h
  std::ifstream file_h (header_file_path);
  if (!file_h)
    return header_file_path + " does not exist\n";

  int i = 0;
  std::string s;
  while (i < header_file_path.length ())
    {
      if (header_file_path[i] != '/')
        s += header_file_path[i];
      else
        s.clear ();
      i++;
    }
  file_h.close();
  m_files_names.push_back (s);
  header_file_path.pop_back ();
  header_file_path += "cpp";
  std::ifstream file_cpp (header_file_path);
  if (file_cpp)
    {
      s.pop_back ();
      s += "cpp";
      m_files_names.push_back (s);
      file_cpp.close();
    }
  return {};
}

std::vector<std::unique_ptr<class_files_data>> class_files_data::create_dependencies ()
{
  return {};
}

class_files_data::~class_files_data () = default;
