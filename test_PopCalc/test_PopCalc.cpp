#include <Windows.h>
#include <iostream>

typedef void (__cdecl *PopCalc_t)(void);


int main(int argc, char** argv) {
	HINSTANCE hPopCalc;
	PopCalc_t PopCalc;

	hPopCalc = LoadLibrary(TEXT("PopCalc.dll"));
	if (hPopCalc == NULL) {
		std::cerr << "[!] Error: Could not load the dynamic library" << std::endl;
		return EXIT_FAILURE;
	}
	std::cout << "[+] SUCCESS: Loaded PopCalc.dll" << std::endl;

	PopCalc = (PopCalc_t)GetProcAddress(hPopCalc, "PopCalc");
	if (PopCalc == NULL) {
		std::cerr << "[!] Error: Could not find PopCalc function pointer" << std::endl;
		return EXIT_FAILURE;
	}
	std::cout << "[+] SUCCESS: Found PopCalc function pointer" << std::endl;

	PopCalc();

	return EXIT_SUCCESS;
}