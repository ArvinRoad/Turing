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

void Turing::TestLog()
{
	Turing::Logger::Init();
	int a = 5;
	TURING_CORE_WARN("Core Logger | Warning");
	CTURING_ERROR("Client Logger | Error");
	STURING_INFO("Service Info | Logger: machine[{0}]", a);
	LOG("LOG", "Logger");
	LOG_INFO("LOG", "INFO Logger");
	LOG_DEBUG("LOG", "DEBUG Logger");
	LOG_WARNING("LOG", "WARNING Logger");
	LOG_ERROR("LOG", "ERROR Logger");
	FLOG("FLOG", "Logger");
	FLOG_DEBUG("FLOG", "DeBug Logger");
	FLOG_INFO("FLOG", "INFO Logger");
	FLOG_WARNING("FLOG", "WARNING Logger");
	FLOG_ERROR("FLOG", "ERROR Logger");
}
