#pragma once
#include "Servo.hpp"

namespace Engine {
	class Queue : Servo
	{
	private:
		vk::Device& device;

	public:

		inline Queue(Foundation & f, VkQueueFlagBits type) : Servo(f), device(f.device)
		{
			device.getQueue(1, 1).

		}

		inline virtual ~Queue()
		{

		}

	};
}
