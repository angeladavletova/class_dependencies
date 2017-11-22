#include "class_file_tree_node.h"

#include "src/kernel/class_files_data.h"

class_file_tree_node::class_file_tree_node (std::unique_ptr<class_files_data> data, class_file_tree_node *parent)
  : m_parent (parent), m_data (std::move (data))
{

}

void class_file_tree_node::create_children ()
{
  m_children.clear ();
  auto children_data = m_data->create_dependencies ();
  for (auto &data : children_data)
    {
      std::unique_ptr<class_file_tree_node> child;
      child.reset (new class_file_tree_node (std::move (data), this));
      m_children.push_back (std::move (child));
    }
}

void class_file_tree_node::create_subtree ()
{
  create_children ();

  for (auto &child : m_children)
    child->create_subtree ();
}

class_file_tree_node::~class_file_tree_node () = default;
