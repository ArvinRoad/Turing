#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include <Core.h>

namespace Turing
{
	class TURING_API Application
	{
	public:
		Application();
		virtual ~Application();

		void RUN();
	private:
	};

	/* 定义于客户端 */
	Application* CreateApplication();
	void TestLog();
}
#endif