#ifndef __ENTRYPOINT_H__
#define __ENTRYPOINT_H__

/* Entry Point */
#ifdef TR_PLATFORM_WINDOWS

extern Turing::Application* Turing::CreateApplication();
int main(int argc, char** argv) 
{
	Turing::Logger::Init();
	int a = 5;
	TURING_CORE_WARN("内核日志 | 警告");
	CTURING_ERROR("客户端日志 | 错误");
	STURING_INFO("服务器日志 | 日志: 机器{0}", a);
	auto app = Turing::CreateApplication();
	if (app != nullptr) app->RUN();
	delete app;
}

#endif

#endif