#include "Servo.hpp"

Servo::Surface::Surface(vk::Instance & instance, SDL_Window* & window) : instance(instance)
{
	try {
		SDL_SysWMinfo windowInfo;
		SDL_VERSION(&windowInfo.version);
		if (!SDL_GetWindowWMInfo(window, &windowInfo)) {
			throw std::system_error(std::error_code(), "[ERROR] Surface - SDK window manager info is not available.");
		}

		if (windowInfo.subsystem == SDL_SYSWM_WINDOWS) {
			vk::Win32SurfaceCreateInfoKHR surfaceInfo = vk::Win32SurfaceCreateInfoKHR()
				.setHinstance(GetModuleHandle(NULL))
				.setHwnd(windowInfo.info.win.window);
			resource = instance.createWin32SurfaceKHR(surfaceInfo);
			COUT("[DONE] Surface")

		}
		else
			throw std::system_error(std::error_code(), "[ERROR] Surface - Unsupported window manager is in use.");
	}
	catch (const std::exception& e) {
		string m = "[ERROR] Surface - ";
		m += +e.what();
		COUT(m)
	}
};

Servo::Surface::~Surface()
{
	instance.destroySurfaceKHR(resource);
	COUT("[UNDONE] Surface")
};