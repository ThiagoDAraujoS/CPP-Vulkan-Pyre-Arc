#include "Servo.hpp"

//Check if all required extensions are present for this aplication, if not throw an error
void Servo::Instance::ValidateExtensions(const vector<char*>& extensions) {
	vector<string> missingExtensions = {};
	vector<vk::ExtensionProperties> iExtensions = vk::enumerateInstanceExtensionProperties();
	for (const auto& extensionName : extensions)
		if (find_if(iExtensions.begin(), iExtensions.end(), [&extensionName](vk::ExtensionProperties prop) { return strcmp(prop.extensionName, extensionName); }) == iExtensions.end())
			missingExtensions.push_back(extensionName);

	if (missingExtensions.size() > 0) {
		string errorMessage = "[ERROR] Failed to find required extensions\n";
		for (const auto& extensionName : missingExtensions)
			errorMessage += "	- " + extensionName + "\n";
		COUT(errorMessage);
		throw vk::ExtensionNotPresentError(errorMessage);
	}
};

/*
Servo::Instance::operator vk::Instance&() {
	return instance;
};
*/
Servo::Instance::Instance() //: instance(instance)
{
	const vector<char*> layers = {
		#if _DEBUG
			"VK_LAYER_LUNARG_standard_validation"
		#endif
	};
	const vector<char*> extensions = {
		VK_KHR_SURFACE_EXTENSION_NAME,
		VK_KHR_WIN32_SURFACE_EXTENSION_NAME
	};

	//check if system has required extensions
	ValidateExtensions(extensions);

	//build application info struct, it contains info about this application...
	vk::ApplicationInfo appInfo = vk::ApplicationInfo()
		.setPApplicationName("Pyre Arc")
		.setApplicationVersion(1)
		.setApiVersion(MINIMAL_API_VERSION);

	//fill the instance creation form using requested layers, extensions and application info
	vk::InstanceCreateInfo instInfo = vk::InstanceCreateInfo()
		.setFlags(vk::InstanceCreateFlags())
		.setPApplicationInfo(&appInfo)
		.setEnabledExtensionCount(static_cast<uint32_t>(extensions.size()))
		.setPpEnabledExtensionNames(extensions.data())
		.setEnabledLayerCount(static_cast<uint32_t>(layers.size()))
		.setPpEnabledLayerNames(layers.data());

	try {
		//try to build the instance
		resource = vk::Instance(vk::createInstance(instInfo));
		COUT("[DONE] Instance")
	}
	catch (const std::exception& e) {
		//if something bad happens throw an error
		char* errorMsg = "[ERROR] Could not create a Vulkan Instance: ";
		COUT(strcat(errorMsg, e.what()))
	}
};


Servo::Instance::~Instance()
{
	//destroy the vkInstance
	resource.destroy();
	COUT("[UNDONE] Instance")
};