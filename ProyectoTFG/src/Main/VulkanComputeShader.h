#pragma once

#include "VulkanShader.h"

class VulkanComputeShader: public VulkanShader
{
private:
	VkComputePipelineCreateInfo compShaderStageInfo = { VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO };
	StorageBufferObject ssbo;
	VkShaderModule compShaderModule;

	const std::string rawComputeName = "rawCompute";

	virtual void destroyModules();

public:
	VulkanComputeShader();
	~VulkanComputeShader();

	void init(std::string computePath);
	virtual void use() {};
	virtual void release();

	void setSSBO(const StorageBufferObject value);

	inline VkComputePipelineCreateInfo getCompShaderStageInfo() { return compShaderStageInfo; }
	inline VkShaderModule getComputeShaderModule() { return compShaderModule; }
	StorageBufferObject getSSBO();
};
