#pragma once

#include "stdafx.h"
#include <vector>

namespace Microsoft
{
	namespace VisualStudio
	{
		namespace CppUnitTestFramework
		{
			template<>
			static std::wstring ToString<std::vector<int>>
				(const std::vector<int>& v)
			{
				std::wostringstream ws;
				ws << "[";
				for (auto it = v.begin(); it != v.end(); ++it) {
					ws << *it;
					if (it != v.end()-1)
						ws << ", ";
				}
				ws << "]";
				return ws.str();
			}
		}
	}
}