// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  PmergeMe.Parsing.cpp                                                //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "PmergeMe.hpp" // needed for PmergeMe class, typedefs, std::vector
#include <cstdlib>      // needed for std::atoi
#include <stdexcept>    // needed for std::invalid_argument

bool is_positive_number(t_str_c & input)
{
    size_t pos = input.find_first_not_of("0123456789+");
    if (pos != t_str::npos || std::atoi(input.c_str()) <= 0)
    {
        return false;
    }
    return true;
}

t_vec_str_c str_split_by(t_str_c & str, t_str_c & delimiter)
{
    t_vec_str vec;
    t_str     tmp(str);
    while (1)
    {
        size_t pos = tmp.find_first_of(delimiter);
        if (pos == t_str::npos)
        {
            pos = tmp.size();
        }
        if (pos != 0)
        {
            vec.push_back(tmp.substr(0, pos));
        }
        if (pos == tmp.size())
        {
            break;
        }
        tmp = tmp.substr(pos + 1, tmp.size());
    }
    return vec;
}

t_vec_str_c split_quotated_strings(int argc, char ** argv)
{
    t_vec_str vec;
    for (int i = 1; i <= argc; ++i)
    {
        t_vec_str_c tmp = str_split_by(argv[i], " ");
        vec.insert(vec.end(), tmp.begin(), tmp.end());
    }
    return vec;
}

void PmergeMe::parse_arguments()
{
    t_vec_str_c vec = split_quotated_strings(_argc, _argv);
    if (vec.empty() == true)
    {
        throw std::invalid_argument("empty arguments!");
    }
    for (t_vec_str_cit it = vec.begin(); it != vec.end(); ++it)
    {
        if (is_positive_number(*it) == false)
        {
            throw std::invalid_argument("only positive integers allowed!");
        }
    }
    _args = vec;
}

// -------------------------------------------------------------------------- //
