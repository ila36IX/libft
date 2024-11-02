#include "tests.h" 

/*
 * _strnstr - the bsd original implementations
 * Don't change this function
 */
char *_strnstr(const char *s, const char *find, size_t slen)
{
	char c, sc;
	size_t len;

	if ((c = *find++) != '\0') {
		len = strlen(find);
		do {
			do {
				if (slen-- < 1 || (sc = *s++) == '\0')
					return (NULL);
			} while (sc != c);
			if (len > slen)
				return (NULL);
		} while (strncmp(s, find, len) != 0);
		s--;
	}
	return ((char *)s);
}

typedef struct {
    int index;
    char desc[50];
    char haystack[100];
    char needle[50];
    size_t len;
} StrnstrTestCase;

StrnstrTestCase strnstr_tests[] = {
    {0x00, "Basic match at start", "Heatblast is a Pyronite from the star Pyros", "Heatblast", 50},
    {0x01, "Match within length limit", "Heatblast is a Pyronite from the star Pyros", "Pyros", 35},
    {0x02, "No match within length", "Diamondhead can create crystals", "crystals", 10},
    {0x03, "Empty needle should match start", "XLR8 is one of Ben's fastest aliens", "", 20},
    {0x04, "No match if needle not present", "Upgrade can merge with technology", "Wildmutt", 50},
    {0x05, "Partial match but not complete", "Fourarms has immense strength", "arm", 20},
    {0x06, "Exact match within length", "Stinkfly sprays venom", "Stinkfly", 8},
    {0x07, "Match found at end of haystack", "Ripjaws can breathe underwater", "underwater", 25},
    {0x08, "No match due to short length limit", "Ghostfreak is mysterious", "Ghostfreak", 5},
    {0x09, "Needle longer than haystack", "Echo", "EchoEchoEcho", 15},
    {0x0A, "Haystack and needle are identical", "Cannonbolt", "Cannonbolt", 50},
    {0x0B, "Match with length exceeding string", "Grey Matter is smart", "Matter", 100},
    {0x0C, "Characters overlap but no full match", "Wildvine spreads vines", "vine vines", 50},
    {0x0D, "Match with special characters", "Blitzwolfer has a howl!", "howl!", 30},
    {0x0E, "Non-matching characters in needle", "Ben used Upchuck in battle", "Up-", 50},
    {0x0F, "Match found at start of haystack", "Accelerate quickly", "Accelerate", 15},
    {0x10, "First occurrence matches", "Chromastone is indestructible, Chromastone glows", "Chromastone", 50},
    {0x11, "Match after special character", "Spidermonkey is agile!$", "agile", 50},
    {0x12, "Numeric characters in match", "Waybig 10", "10", 10},
    {0x13, "Match with spaces around", "Wildmutt loves running", " loves", 50},
    {0x14, "Unicode character match", "Albedo’s Omnitrix", "Omnitrix", 50},
    {0x15, "Empty haystack with non-empty needle", "", "Heatblast", 10},
    {0x16, "Both haystack and needle empty", "", "", 10},
};

void run_strnstr_tests(char *(*func_to_test)(const char*, const char*, size_t)) {
	int num_tests = sizeof(strnstr_tests) / sizeof(strnstr_tests[0]);

	printf("\nRun strnstr\n");
	for (int i = 0; i < num_tests; i++) {
		StrnstrTestCase test_case = strnstr_tests[i];

		const char *expected = _strnstr(test_case.haystack, test_case.needle, test_case.len);
		const char *result = func_to_test(test_case.haystack, test_case.needle, test_case.len);

		if (result == expected && result && expected && strcmp(result, expected) == 0)
		{
				TEST_PASS(test_case.desc);
		}
		else if (result == expected && !result && !expected)
				TEST_PASS(test_case.desc);
		else
		{
			TEST_FAIL(test_case.desc);
			printf("  -> Expected: %s\n", expected ? expected : "NULL");
			printf("  -> Got: %s\n", result ? result : "NULL");
		}
		printf("\n");
	}
}

int main() {
    run_strnstr_tests(ft_strnstr);
    return 0;
}
