#pragma once

class class_files_data;

#include "src/pch/pch.h"

class class_file_tree_node
{
  class_file_tree_node *m_parent;
  std::unique_ptr<class_files_data> m_data;
  std::vector<std::unique_ptr<class_file_tree_node>> m_children;

  void create_children ();
public:
  class_file_tree_node (std::unique_ptr<class_files_data> data, class_file_tree_node *parent = nullptr);
  ~class_file_tree_node ();

  void create_subtree ();
};
