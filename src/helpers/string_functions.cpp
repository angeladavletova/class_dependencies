#include "string_functions.h"


std::vector<std::string> split_into_words (std::string str)
{
  std::vector<std::string> words;
  std::string curr_wrd;
  for (auto c : str)
    {
      if (str == " " && !curr_wrd.empty ())
        {
          words.push_back (curr_wrd);
          curr_wrd.clear ();
        }
      else
        curr_wrd.push_back (c);
    }
  return words;
}
