#include <Fita.h>

class Sandbox : public Fita::Application
{
public:
	Sandbox()
	{
		
	}

	~Sandbox()
	{

	}

};

Fita::Application* Fita::CreateApplication()
{
	return new Sandbox();
}