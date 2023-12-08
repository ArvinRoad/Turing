#include <Turing.h>
class Sandbox : public Turing::Application
{
public:
	Sandbox()
	{
		
	}
	~Sandbox()
	{
		
	}
private:
};

Turing::Application* Turing::CreateApplication()
{
	return new Sandbox();
}