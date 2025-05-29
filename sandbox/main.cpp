#include <iostream>
#include <cstdint>
#include <string>
#include <string_view>
#include <bitset>
#define LIVE_TEST

/*
Program to solve "NYT Spelling Bee" word puzzle relatively fast
TODO:
-resolve indeterminism (lmao)
-dictionary candidate input
-file output
*/

const uint32_t ASC_OFST{96};
const uint32_t MAP_OFST{26};
const uint32_t ONE_BIT{1};

/* 
add a 5-bit key character identifier at the head of ui32
as 5 bits is adequate for a unique identifier 1=<i=<26
and the map schema is 26-bit, which leaves 6 bits for additional information
 */
uint32_t map_key_char(char kc, uint32_t str_map)
{
	const uint32_t init_key_map{MAP_OFST - (uint32_t(kc) - ASC_OFST) + ONE_BIT};
	const uint32_t shift_key_map{init_key_map << MAP_OFST};
	return shift_key_map | str_map;
}

/*
Let each lowercase ascii letter be l where a=<l=<z
Each unique value l returns bitmap as ui32
*/
uint32_t map_char(char wc)
{
	return (ONE_BIT << (MAP_OFST - (uint32_t(wc) - ASC_OFST)));
}

/*
Creates bitmap for set of chars in str_v
As str_v is a subset of the alphabet, the bitmap must >= 26 bits
Uses ui32 type to contain the returned bitmap
*/
uint32_t map_str(std::string_view str_v)
{
	if (str_v.length() < 1)
	{
		return 0;
	}
	else
	{
		const char chr{str_v[0]};
		const uint32_t map_pref{map_char(str_v[0])};
		str_v.remove_prefix(1);
		return map_pref | map_str(str_v);
	}
}

/*
Per NYT Bee rules:
Let c_set represent the set of letters used to spell a candidate word
Let k_set represent the set of valid letters
Let key be a single letter
Where c_set must be a subset of k_set
And c_set must contain key
Function returns 1 if conditions met
Else returns 0
*/
uint32_t map_compare(uint32_t key_map, uint32_t candidate_map)
{
	const uint32_t key_index{key_map >> MAP_OFST}; //this is "destructive" but it doesn't matter
	const uint32_t key_reference{(ONE_BIT << key_index)};
	const uint32_t has_key{(candidate_map & key_reference) / key_reference}; //effectively bool
	const uint32_t is_submap{candidate_map / (key_map | candidate_map)};
	return (candidate_map * has_key * is_submap) / candidate_map;
}

int main() 
{
	#ifdef LIVE_TEST
	std::cout << "Key Character: ";
	char key_char{};
	std::cin >> key_char;
	std::cout << "\nAll characters: ";
	std::string valid_chars{};
	std::cin >> valid_chars;
	std::string_view valid_view{valid_chars};
	uint32_t init_map{map_str(valid_view)};
	uint32_t k_map{map_key_char(key_char, init_map)};
	std::cout << "Enter candidate word: ";
	std::string candidate{};
	std::cin >> candidate;
	std::string_view c_view{candidate};
	uint32_t cmap{map_str(c_view)};
	std::cout << map_compare(k_map, map_str(c_view));
	#endif
	// 
	return 0;
}