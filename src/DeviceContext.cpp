#include "DeviceContext.h"

void
DeviceContext::ClearDepthStencilView(ID3D11DepthStencilView* pDepthStencilView,
	unsigned int ClearFlags,
	float Depth,
	unsigned int Stencil) {
	if (pDepthStencilView == nullptr) {
		WARNING("ERROR: DeviceContext::ClearDepthStencilView : Error in data from params [CHECK FOR ID3D11DepthStencilView* pDepthStencilView]\n");
		exit(1);
	}
	else {
		m_deviceContext->ClearDepthStencilView(pDepthStencilView, ClearFlags, Depth, Stencil);
	}
}

void
DeviceContext::PSSetShaderResources(unsigned int StartSlot,
	unsigned int NumViews,
	ID3D11ShaderResourceView* const* ppShaderResourceViews) {
	if (ppShaderResourceViews == nullptr) {
		WARNING("ERROR: DeviceContext::ClearDepthStencilView : Error in data from params [CHECK FOR ID3D11ShaderResourceView* const* ppShaderResourceViews]\n");
		exit(1);
	}
	else {
		m_deviceContext->PSSetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
	}
}
