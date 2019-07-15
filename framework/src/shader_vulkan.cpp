#include "shader_vulkan.h"

namespace cgb
{
	shader shader::prepare(shader_info pInfo)
	{
		shader result;
		result.mInfo = std::move(pInfo);
		result.mTracker.setTrackee(result);
		return result;
	}

	shader shader::create(shader_info pInfo)
	{
		auto shdr = shader::prepare(std::move(pInfo));
		shdr.mShaderModule = shader::build_from_file(shdr.info().mPath);
		return shdr;
	}

	vk::UniqueShaderModule shader::build_from_file(std::string_view pPath)
	{
		auto binFileContents = cgb::load_binary_file("shaders/shader.vert.spv");
		return shader::build_from_binary_code(binFileContents);
	}

	vk::UniqueShaderModule shader::build_from_binary_code(const std::vector<char>& pCode)
	{
		auto createInfo = vk::ShaderModuleCreateInfo()
			.setCodeSize(pCode.size())
			.setPCode(reinterpret_cast<const uint32_t*>(pCode.data()));

		return context().logical_device().createShaderModuleUnique(createInfo);
	}

	bool shader::has_been_built()
	{
		return static_cast<bool>(mShaderModule);
	}

}
