#include "class_files_data.h"

class_files_data::class_files_data ()
{
}

std::string class_files_data::init (std::string /*header_file_path*/)
{
  return {};
}

std::vector<std::unique_ptr<class_files_data>> class_files_data::create_dependencies ()
{
  return {};
}

class_files_data::~class_files_data () = default;
