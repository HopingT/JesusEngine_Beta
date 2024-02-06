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
