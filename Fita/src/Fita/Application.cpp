#include "Application.h"

#include "Fita/Events/ApplicationEvent.h"
#include "Fita/Log.h"

namespace Fita {

	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		FI_TRACE(e);

		while (true);
	}

}