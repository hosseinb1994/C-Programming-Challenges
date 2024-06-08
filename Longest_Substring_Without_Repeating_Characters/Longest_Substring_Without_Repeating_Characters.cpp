extern "C" {
	#include "Longest_Substring_Without_Repeating_Characters.h"
}
int lengthOfLongestSubstring(char* s);

int main()
{
	const char *s = "abcbefabcbb";
	int res = lengthOfLongestSubstring((char*)s);
	printf("Lnegth of longest substring witout repeating carachters: %d\n", res);
	return 0;
}

int lengthOfLongestSubstring(char* s) {
	int len = strlen(s);
	int max_len = 0;
	int start = 0;// beginning the substring
	int char_index[256] = { -1 };
	for (int i = 0; i < len; i++) {
		if (char_index[s[i]] >= start) {
			start = char_index[s[i]] + 1;
		}
		char_index[s[i]] = i;
		int current_len = i - start + 1;
		if (current_len > max_len) {
			max_len = current_len;
		}
	}
	return max_len;
}

