#include "Device.h"

// Métodos básicos para inicializar, actualizar, renderizar y destruir el dispositivo. 
// Actualmente están vacíos, lo que sugiere que se deben implementar según las necesidades específicas del proyecto.
void Device::init()
{
}

void Device::update()
{
}

void Device::render()
{
}

// Limpia y libera el recurso del dispositivo de manera segura.
void Device::destroy()
{
	SAFE_RELEASE(m_device); // Macro diseñada para liberar recursos COM de manera segura.
}

/// <summary>
/// Crea una vista de objetivo de renderizado (render target view, RTV) asociada con un recurso.
/// </summary>
/// <param name="pResource">Puntero al recurso para el cual crear la vista.</param>
/// <param name="pDesc">Descripción de la vista de renderizado a crear.</param>
/// <param name="ppRTView">Puntero al puntero donde se almacenará la vista creada.</param>
/// <returns>HRESULT indicando el éxito o fracaso de la operación.</returns>
HRESULT Device::CreateRenderTargetView(ID3D11Resource* pResource, const D3D11_RENDER_TARGET_VIEW_DESC* pDesc, ID3D11RenderTargetView** ppRTView)
{
	HRESULT hr = S_OK;
	// Verifica que los parámetros necesarios estén presentes.
	if (pResource != nullptr || ppRTView != nullptr) {
		hr = m_device->CreateRenderTargetView(pResource, pDesc, ppRTView);
		WARNING("Device::CreateRenderTargetView : [CREATION OF RESOURCE : OK]\n");
	}
	else {
		WARNING("ERROR: Device::CreateRenderTargetView : Error in data from params [CHECK FOR CREATION METHOD]\n");
		exit(1);
	}
	return hr;
}

/// <summary>
/// Crea una textura 2D basada en la descripción proporcionada.
/// </summary>
/// <param name="pDesc">Descripción de la textura 2D a crear.</param>
/// <param name="pInitialData">Datos iniciales para los mipmaps de la textura.</param>
/// <param name="ppTexture2D">Puntero al puntero donde se almacenará la textura creada.</param>
/// <returns>HRESULT indicando el éxito o fracaso de la operación.</returns>
HRESULT Device::CreateTexture2D(const D3D11_TEXTURE2D_DESC* pDesc, const D3D11_SUBRESOURCE_DATA* pInitialData, ID3D11Texture2D** ppTexture2D)
{
	HRESULT hr = S_OK;
	if (pDesc != nullptr || ppTexture2D != nullptr) {
		hr = m_device->CreateTexture2D(pDesc, pInitialData, ppTexture2D);
		WARNING("Device::CreateTexture2D : [CREATION OF RESOURCE : OK]\n");
	}
	else {
		WARNING("ERROR: Device::CreateTexture2D : Error in data from params [CHECK FOR CREATION METHOD]\n");
		exit(1);
	}
	return hr;
}

/// <summary>
/// Crea una vista de profundidad y stencil (depth stencil view, DSV) asociada con un recurso.
/// </summary>
/// <param name="pResource">Puntero al recurso para el cual crear la vista.</param>
/// <param name="pDesc">Descripción de la vista de profundidad y stencil a crear.</param>
/// <param name="ppDepthStencilView">Puntero al puntero donde se almacenará la vista creada.</param>
/// <returns>HRESULT indicando el éxito o fracaso de la operación.</returns>
HRESULT Device::CreateDepthStencilView(ID3D11Resource* pResource, const D3D11_DEPTH_STENCIL_VIEW_DESC* pDesc, ID3D11DepthStencilView** ppDepthStencilView)
{
	HRESULT hr = S_OK;
	// Verifica que el recurso y el puntero para la vista de profundidad y stencil no sean nulos.
	if (pResource != nullptr && ppDepthStencilView != nullptr) {
		hr = m_device->CreateDepthStencilView(pResource, pDesc, ppDepthStencilView);
		WARNING("Device::CreateDepthStencilView : [CREATION OF RESOURCE : OK]\n");
	}
	else {
		WARNING("ERROR: Device::CreateDepthStencilView : Error in data from params\n");
		exit(1);
	}
	return hr;
}

/// <summary>
/// Crea un sombreador de vértices (vertex shader) utilizando los datos de bytecode proporcionados.
/// </summary>
/// <param name="pShaderBytecode">Puntero al bytecode del sombreador de vértices.</param>
/// <param name="BytecodeLength">Longitud del bytecode proporcionado.</param>
/// <param name="pClassLinkage">Puntero a la clase de enlace para el sombreador; NULL si no se utiliza.</param>
/// <param name="ppVertexShader">Puntero al puntero donde se almacenará el sombreador de vértices creado.</param>
/// <returns>HRESULT indicando el éxito o fracaso de la operación.</returns>
HRESULT Device::CreateVertexShader(const void* pShaderBytecode, unsigned int BytecodeLength, ID3D11ClassLinkage* pClassLinkage, ID3D11VertexShader** ppVertexShader)
{
	HRESULT hr = S_OK;
	if (pShaderBytecode != nullptr && ppVertexShader != nullptr) {
		hr = m_device->CreateVertexShader(pShaderBytecode, BytecodeLength, pClassLinkage, ppVertexShader);
		WARNING("Device::CreateVertexShader : [CREATION OF RESOURCE : OK]\n");
	}
	else {
		WARNING("ERROR: Device::CreateVertexShader: Error in data from params\n");
		exit(1);
	}
	return hr;
}

/// <summary>
/// Crea un layout de entrada (input layout) que describe los datos de vértice al sombreador de vértices.
/// </summary>
/// <param name="pInputElementDescs">Arreglo de descripciones de elementos de entrada.</param>
/// <param name="NumElements">Número de elementos en el arreglo de descripciones.</param>
/// <param name="pShaderBytecodeWithInputSignature">Bytecode del sombreador que incluye la firma de entrada.</param>
/// <param name="BytecodeLength">Longitud del bytecode proporcionado.</param>
/// <param name="ppInputLayout">Puntero al puntero donde se almacenará el layout de entrada creado.</param>
/// <returns>HRESULT indicando el éxito o fracaso de la operación.</returns>
HRESULT Device::CreateInputLayout(const D3D11_INPUT_ELEMENT_DESC* pInputElementDescs, unsigned int NumElements, const void* pShaderBytecodeWithInputSignature, unsigned int BytecodeLength, ID3D11InputLayout** ppInputLayout)
{
	HRESULT hr = S_OK;
	if (pInputElementDescs != nullptr && pShaderBytecodeWithInputSignature != nullptr && ppInputLayout != nullptr) {
		hr = m_device->CreateInputLayout(pInputElementDescs, NumElements, pShaderBytecodeWithInputSignature, BytecodeLength, ppInputLayout);
		WARNING("Device::CreateInputLayout : [CREATION OF RESOURCE : OK]\n");
	}
	else {
		WARNING("ERROR: Device::CreateInputLayout: Error in data from params\n");
		exit(1);
	}
	return hr;
}

/// <summary>
/// Crea un sombreador de píxeles (pixel shader) utilizando los datos de bytecode proporcionados.
/// </summary>
/// <param name="pShaderBytecode">Puntero al bytecode del sombreador de píxeles.</param>
/// <param name="BytecodeLength">Longitud del bytecode proporcionado.</param>
/// <param name="pClassLinkage">Puntero a la clase de enlace para el sombreador; NULL si no se utiliza.</param>
/// <param name="ppPixelShader">Puntero al puntero donde se almacenará el sombreador de píxeles creado.</param>
/// <returns>HRESULT indicando el éxito o fracaso de la operación.</returns>
HRESULT Device::CreatePixelShader(const void* pShaderBytecode, unsigned int BytecodeLength, ID3D11ClassLinkage* pClassLinkage, ID3D11PixelShader** ppPixelShader)
{
	HRESULT hr = S_OK;
	if (pShaderBytecode != nullptr && ppPixelShader != nullptr) {
		hr = m_device->CreatePixelShader(pShaderBytecode, BytecodeLength, pClassLinkage, ppPixelShader);
		WARNING("Device::CreatePixelShader : [CREATION OF RESOURCE : OK]\n");
	}
	else {
		WARNING("ERROR: Device::CreatePixelShader: Error in data from params\n");
		exit(1);
	}
	return hr;
}

HRESULT
Device::CreateBuffer(const D3D11_BUFFER_DESC* pDesc,
	const D3D11_SUBRESOURCE_DATA* pInitialData,
	ID3D11Buffer** ppBuffer) {
	HRESULT hr = S_OK;

	if (pDesc == nullptr) {
		WARNING("ERROR: Device::CreateBuffer: Error in data from params [CHECK FOR const D3D11_BUFFER_DESC* pDesc]\n");
		exit(1);
	}
	else if (ppBuffer == nullptr) {
		WARNING("ERROR: Device::CreateBuffer: Error in data from params [CHECK FOR ID3D11Buffer** ppBuffer]\n");
		exit(1);
	}
	else {
		hr = m_device->CreateBuffer(pDesc, pInitialData, ppBuffer);
		WARNING("Device::CreateBuffer : [CREATION OF RESOURCE : OK] \n");
	}
	return hr;
}

HRESULT
Device::CreateSamplerState(const D3D11_SAMPLER_DESC* pSamplerDesc,
	ID3D11SamplerState** ppSamplerState) {
	HRESULT hr = S_OK;
	if (pSamplerDesc == nullptr) {
		WARNING("ERROR: Device::CreateSampleState: Error in data from params [CHECK FOR const D3D11_SAMPLER_DESC* pSamplerDesc]\n");
		exit(1);
	}
	else if (ppSamplerState == nullptr) {
		WARNING("ERROR: Device::CreateSampleState: Error in data from params [CHECK FOR ID3D11SamplerState** ppSamplerStat]\n");
		exit(1);
	}
	else {
		hr = m_device->CreateSamplerState(pSamplerDesc,
			ppSamplerState);
		WARNING("Device::CreateSamplerState : [CREATION OF RESOURCE : OK]\n");
	}

	return hr;
}