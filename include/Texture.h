#pragma once
#include "Prerequisites.h"
class Device;
class DeviceContext;

class
	Texture {

public:
	Texture() = default;
	~Texture();

	void
		init(Device device, std::string textureName);

	void
		init(Device device,
			unsigned width,
			unsigned height,
			DXGI_FORMAT Format,
			unsigned int BlindFlags);

	void
		update();

	void
		render(DeviceContext& deviceContext, unsigned int StarSlot);

	void
		destroy();

public:
	//The variable is in charge from handle a texture resource as data
	ID3D11Texture2D* m_texture = nullptr;

	//This variable is in charge of a handle texture resource as image data
	ID3D11ShaderResourceView* m_textureFromImg;

};