#include "MyForm3.h"
#include <cstdio>
#include <cstring>
#include <sndfile.h>
#include <sndfile.hh>


using namespace System;
using namespace System::Windows::Forms;
[STAThread]
int main(array<System::String^>^ argv) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Progetto1::MyForm form;
	Application::Run(%form);
}