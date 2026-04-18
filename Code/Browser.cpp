#include "Browser.h"
using namespace System;
using namespace System::Windows::Forms;
[STAThread]

void main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	ProjectGUI::Browser form;
	Application::Run(% form);
}
