#pragma once

#include "src/pch/pch.h"
class class_file_tree_node;

class dependencies_data
{
  std::unique_ptr<class_file_tree_node> m_class_files_tree_root;

public:
  dependencies_data ();
  ~dependencies_data ();

  std::string reset_class_files_tree_root (std::string header_file_path);
  const class_file_tree_node *get_class_file_tree_root () const;
};
