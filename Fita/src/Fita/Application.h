#pragma once

#include "Core.h"

#include "Window.h"
#include "Fita/LayerStack.h"
#include "Fita/Events/Event.h"
#include "Fita/Events/ApplicationEvent.h"

namespace Fita {

	class FITA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	//To be defined in CLIENT
	Application* CreateApplication();

}
