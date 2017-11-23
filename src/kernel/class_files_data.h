#pragma once

class class_files_data
{
  std::vector<std::string> m_files_names;
public:
  class_files_data ();
  ~class_files_data ();

  std::string init (std::string header_file_path);
};
