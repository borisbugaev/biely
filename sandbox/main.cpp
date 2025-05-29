#include <iostream>
#include <cstdint>
#include <string>
#include <string_view>

/*Program to solve "NYT Spelling Bee" word puzzle relatively fast*/

uint32_t map_char(char wc)
{
	const int asc_offset{96};
	return 2^(int(wc) - asc_offset);
}

uint32_t map_str(std::string_view str_v)
{
	if (str_v.length() < 1)
	{
		return 0;
	}
	else
	{
		uint32_t map_pref{map_char(str_v[1])};
		str_v.remove_prefix(1);
		return map_pref | map_str(str_v);
	}
}

int main()
{
	// accept bee parameters as argument

	// call map function for b_set
	// call map function for b_primary
	// call map function for each word in dictionary set
	// print each word which passes to file

	// 
	return 0;
}