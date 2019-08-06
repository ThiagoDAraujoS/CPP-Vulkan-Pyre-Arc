#pragma once
#include "Requirements.hpp"
#include "DeviceInspector.hpp"
#include "QueueManager.hpp"

namespace Servo {
	template <class T>
	class Servo {
	public:
		T resource;
		inline Servo() {};
		inline operator T&() {	return resource; }
		inline virtual ~Servo() {};
	};

	//This servo constructs and deconstructs the vkInstance object, it checks if all required extensions are avaliable and triggers the validation layers aswell
	class Instance : public Servo<vk::Instance> {
	private:
		///Check if all required extensions are present for this aplication, if not throw an error
		void ValidateExtensions(const vector<char*>& extensions);
	public:
		Instance();
		virtual ~Instance();
	};

	//This servo builds, opens and closes the window
	class Window : public Servo<SDL_Window*> {
	public:
		Window();
		virtual ~Window();
	};

	//this servo builds the surface for rendering
	class Surface : public Servo<vk::SurfaceKHR> {
	private:
		///Surface servo needs the reference for the instance to destroy itself later
		vk::Instance& instance;
	public:
		Surface(vk::Instance & instance, SDL_Window* & window);
		virtual ~Surface();
	};

	//this servo analyzes all devices and picks one for the application
	class Device : public Servo<vk::Device> {
	private:
		///look through all the existing devices and pick one
		vk::PhysicalDevice PickPhysicalDevice(
			const vk::Instance& instance,
			const vk::SurfaceKHR& surface,
			const PhysicalDeviceRequestIndexes& requestedFeatures);
	public:
		Device(vk::Instance & instance, vk::SurfaceKHR & surface/*, QueueManager & queue*/);
		~Device();
	};
}

