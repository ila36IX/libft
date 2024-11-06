#include "tests.h"

typedef struct {
	int     index;        
	char    desc[50];     
	char    input[200];    
	char    delimiter;    
	char    *expected[200];
} TestCase;

TestCase tests[] = {
	{0x01, "Simple split", "Ben10 is cool", ' ', {"Ben10", "is", "cool", NULL}},
	{0x02, "No delimiters", "Cannonbolt", ' ', {"Cannonbolt", NULL}},
	{0x03, "Only delimiters", ";;;;", ';', {NULL}},
	{0x04, "Delimiters at edges", ",Heatblast,", ',', {"Heatblast", NULL}},
	{0x05, "Multiple consecutive delimiters", "Ben;;10;;Heroes", ';', {"Ben", "10", "Heroes", NULL}},
	{0x06, "Different delimiter", "Kevin,Levin,Series", ',', {"Kevin", "Levin", "Series", NULL}},
	{0x07, "Delimiters at start", ",,,Heatblast", ',', {"Heatblast", NULL}},
	{0x08, "Empty string input", "", '-', {NULL}},
	{0x09, "Single character input", "X", 'X', {NULL}},
	{0x0A, "No split needed", "Vilgax", ',', {"Vilgax", NULL}},
	{0x0B, "Delimiters at end", "Heatblast,,,", ',', {"Heatblast", NULL}},
	{0x0C, "Mixed delimiters", "XLR8;Upgrade,Wildmutt", ';', {"XLR8", "Upgrade,Wildmutt", NULL}},
	{0x0D, "Long sequence", "Omnitrix:Watch:Power:Alien", ':', {"Omnitrix", "Watch", "Power", "Alien", NULL}},
	{0x0E, "Whitespace handling", "  Gwen  Tennyson  ", ' ', {"Gwen", "Tennyson", NULL}},
	{0x0F, "Special chars", "Four-Arms|Grey-Matter|Ripjaws", '|', {"Four-Arms", "Grey-Matter", "Ripjaws", NULL}},
	{0x10, "Numeric splits", "Ben10:4Arms:2Fast", ':', {"Ben10", "4Arms", "2Fast", NULL}},
	{0x11, "Single char splits", "A:B:C:D", ':', {"A", "B", "C", "D", NULL}},
	{0x12, "Mixed case", "HEATBLAST:heatblast:HeatBlast", ':', {"HEATBLAST", "heatblast", "HeatBlast", NULL}},
	{0x13, "Underscore handling", "Max_Tennyson_Plumber", '_', {"Max", "Tennyson", "Plumber", NULL}},
	{0x14, "Tab delimiter", "Diamondhead\tTetrax\tPetrosapien", '\t', {"Diamondhead", "Tetrax", "Petrosapien", NULL}},
	{0x15, "Multiple spaces", "Way  Big   Alien", ' ', {"Way", "Big", "Alien", NULL}},
	{0x16, "$ chars", "Upgrade$Galvanic$Mechamorph", '$', {"Upgrade", "Galvanic", "Mechamorph", NULL}},
	{0x17, "Numbers only", "10:11:12:13", ':', {"10", "11", "12", "13", NULL}},
	{0x18, "Mixed content", "Alien-123;Force-456;Ultimate-789", ';', {"Alien-123", "Force-456", "Ultimate-789", NULL}},
	{0x19, "Long word", "SuperhugeultimatealienforceomnitrixwieldingBen", ' ', {"SuperhugeultimatealienforceomnitrixwieldingBen", NULL}},
	{0x1A, "Symbol delimiter", "Stinkfly#Wildvine#Ghostfreak", '#', {"Stinkfly", "Wildvine", "Ghostfreak", NULL}},
	{0x1B, "very long string", "   ben     ben     ben ben ben ben ben ben ben ben ben ben ben ben ben ben ben ben ben ben ben ben ben ben ben ben ben ben ben ben ben ben ben ben ben ben ben ben ", ' ', {"ben","ben","ben","ben","ben","ben","ben","ben","ben","ben","ben","ben","ben","ben","ben","ben","ben","ben","ben","ben","ben","ben","ben","ben","ben","ben","ben","ben","ben","ben","ben","ben","ben","ben","ben","ben","ben","ben", NULL}},
	{0x1B, "very other long string", "x x x x x x x x x x x x x ", ' ',{ "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x",  NULL}}
};

int calc_size(char **tokens)
{
	int i = 0;
	while (tokens[i])
		i++;
	return (i);
}
int	run_ft_split_tests(int debug) {
	int num_tests = sizeof(tests) / sizeof(tests[0]);
	int OK = TRUE;

	for (int i = 0; i < num_tests; i++) {
		TestCase test_case = tests[i];
		char **result = ft_split(test_case.input, test_case.delimiter);
		int passed = TRUE;
		int exp_size = calc_size(test_case.expected);
		int got_size = calc_size(result);
		if (exp_size == got_size)
		{
			for (int j = 0; test_case.expected[j] != NULL; j++)
			{
				if (strcmp(result[j], test_case.expected[j]) != 0)
				{
					passed = FALSE;
					OK = FALSE;
					break;
				}
			}
		}
		else
			OK = FALSE, passed = FALSE;
		if (debug)
		{
			if (passed)
				TEST_PASS(test_case.desc);
			else
				TEST_FAIL(test_case.desc);
		}

		for (int j = 0; result[j] != NULL; j++)
			free(result[j]);
		free(result);
	}
	return (OK);
}

int main(int ac, char **av)
{
	int debug = FALSE;

	(void) av;
	if (ac > 1)
		debug = TRUE;
	if (run_ft_split_tests(debug))
		TEST_PASS("split");
	else
		TEST_FAIL("split");
	return 0;
}

