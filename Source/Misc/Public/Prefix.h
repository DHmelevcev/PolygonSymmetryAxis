#pragma once

#include <vector>

//---------------------------------------------------------------------------------------

/*
* Computes an array that represents the length of
* the longest proper prefix which is also a suffix
* for each prefix of a given array.
* 
* @return Array of prefixes lengths.
*/
template<typename T>
inline std::vector<size_t> PrefixFunction
(
    const std::vector<T>& String
)
{
    size_t string_size = String.size();

    std::vector<size_t> prefixes(string_size, 0);

    for (size_t i = 1; i < string_size; ++i)
    {
        size_t k = prefixes[i - 1];

        while (k > 0 && String[k] != String[i])
            k = prefixes[k - 1];

        if (String[k] == String[i])
            ++k;

        prefixes[i] = k;
    }

    return prefixes;
}
