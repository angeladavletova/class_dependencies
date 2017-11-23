#pragma once

template<typename EnumT>
EnumT get_next_enum_value (EnumT val)
{
  return static_cast<EnumT> (static_cast<int> (val) + 1);
}

template<typename EnumT>
std::vector<EnumT> get_enum_vector ()
{
  std::vector<EnumT> res;
  EnumT val = static_cast<EnumT> (0);
  while (val != EnumT::END)
    {
      res.push_back (val);
      val = get_next_enum_value (val);
    }
  return res;
}

template <typename EnumT>
static EnumT string_to_enum (const std::string &str, EnumT default_value = EnumT::END)
{
  for (auto e : get_enum_vector<EnumT> ())
    if (enum_to_string (e) == str)
      return e;
  return default_value;
}
