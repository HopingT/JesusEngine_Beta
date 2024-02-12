#pragma once
#include "Prerequisites.h"

class DeviceContext
{
public:
	DeviceContext() = default;
	~DeviceContext() { SAFE_RELEASE(m_deviceContext); };

	void
		init();

	void
		update();

	void
		render();

	void
		destroy();

	void ClearDepthStencilView(ID3D11DepthStencilView* pDepthStencilView,
		unsigned int ClearFlags,
		float Depth,
		unsigned int Stencil);

	void PSSetShaderResources(unsigned int StartSlot,
		unsigned int NumViews,
		ID3D11ShaderResourceView* const* ppShaderResourceViews);

public:
	ID3D11DeviceContext* m_deviceContext = nullptr;
};