#include <iostream>
#include <cstdint>
#include <string>
#include <string_view>

/*Program to solve "NYT Spelling Bee" word puzzle relatively fast*/

uint32_t map_key_char(const char kc, const uint32_t str_map)
{
	const uint32_t asc_offset{96};
	const uint32_t init_key_map{(int(kc) - asc_offset)};
	const uint32_t shift_key_map{init_key_map << 26};
	return shift_key_map | str_map;
}

uint32_t map_char(const char wc)
{
	const uint32_t asc_offset{96};
	return (1 << (int(wc) - asc_offset));
}

uint32_t map_str(std::string_view str_v)
{
	if (str_v.length() < 1)
	{
		return 0;
	}
	else
	{
		const uint32_t map_pref{map_char(str_v[1])};
		str_v.remove_prefix(1);
		return map_pref | map_str(str_v);
	}
}

uint32_t map_compare(const uint32_t key_map, const uint32_t candidate_map)
{
	const uint32_t key_index{key_map >> 26};
	const uint32_t key_reference{(1 << key_index)};
	const uint32_t has_key{(candidate_map & key_reference)/key_reference}; //effectively bool
	// need correct comparator, or a sequence therein
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