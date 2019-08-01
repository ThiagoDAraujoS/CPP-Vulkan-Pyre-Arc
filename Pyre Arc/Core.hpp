#pragma once
#include "Servo.hpp"


namespace Engine {

	class Core
	{
	public:
		//Resources each servo will get a reference to those so they can work with
	//	Servo::QueueManager queue;

		///Servo declarations
		Servo::Instance instance = Servo::Instance();
		Servo::Window   window   = Servo::Window();
		Servo::Surface  surface  = Servo::Surface(instance, window);
		Servo::Device   device   = Servo::Device(instance, surface/*, queue*/);
		 
		void Run();
	};
}




