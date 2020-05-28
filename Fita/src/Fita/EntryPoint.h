#pragma once

#ifdef FI_PLATFORM_WINDOWS

extern Fita::Application* Fita::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Fita::CreateApplication();
	app->Run();
	delete app;
}

#endif // FI_PLATFORM_WINDOWS
