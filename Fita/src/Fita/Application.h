#pragma once
#include "Core.h"

namespace Fita {

	class FITA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();

}
