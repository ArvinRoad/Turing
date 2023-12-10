#ifndef __ENTRYPOINT_H__
#define __ENTRYPOINT_H__

/* Entry Point */
#ifdef TR_PLATFORM_WINDOWS

extern Turing::Application* Turing::CreateApplication();
int main(int argc, char** argv) 
{
	Turing::TestLog();
	auto app = Turing::CreateApplication();
	if (app != nullptr) app->RUN();
	delete app;
}

#endif

#endif