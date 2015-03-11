#ifndef OZONE_FRAMEWORK_SYNCHRONIZER_PIMPL_HPP
#define OZONE_FRAMEWORK_SYNCHRONIZER_PIMPL_HPP

#include "Synchronizer.hpp"
#include <Windows.h>

namespace Ozone
{
	namespace Thread
	{
		class THREAD_DLL Synchronizer::Pimpl
		{
		public:
			HANDLE handle;
		};
	}
}

#endif /* OZONE_FRAMEWORK_SYNCHRONIZER_PIMPL_HPP */
