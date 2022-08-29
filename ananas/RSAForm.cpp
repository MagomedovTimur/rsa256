#include <string>
#include <vector>
#include "boost/multiprecision/cpp_int.hpp"
#include "RSAForm.h"
#include <Windows.h>

using namespace ananas;


// init window
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)

{

	Application::EnableVisualStyles();

	Application::SetCompatibleTextRenderingDefault(false);

	Application::Run(gcnew RSAForm);

	return 0;

}