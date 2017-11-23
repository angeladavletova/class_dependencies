#include "dependencies_data.h"

#include "src/kernel/class_files_data.h"
#include "src/kernel/class_file_tree_node.h"

dependencies_data::dependencies_data ()
{

}

std::string dependencies_data::reset_class_files_tree_root (std::string header_file_path)
{
  auto data = std::make_unique<class_files_data> ();
  std::string err = data->init (header_file_path);

  if (!err.empty ())
    return err;

  m_class_files_tree_root.reset (new class_file_tree_node (std::move (data)));
  return {};
}

const class_file_tree_node *dependencies_data::get_class_file_tree_root () const
{
  return m_class_files_tree_root.get ();
}

dependencies_data::~dependencies_data () = default;
