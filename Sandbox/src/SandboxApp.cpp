#include <Fita.h>

class ExampleLayer : public Fita::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		FI_INFO("ExampleLayer::Update");
	}

	void OnEvent(Fita::Event& event) override
	{
		FI_TRACE("{0}", event);
	}
};

class Sandbox : public Fita::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}

};

Fita::Application* Fita::CreateApplication()
{
	return new Sandbox();
}