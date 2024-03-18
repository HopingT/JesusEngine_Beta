#include "RenderTargetView.h"
#include "Device.h"
#include "DeviceContext.h"
#include "Texture.h"
#include "DepthStencilView.h"

/// <summary>
/// Inicializa la vista de objetivo de renderizado. Este método configura la vista de renderizado
/// usando un dispositivo de DirectX y un buffer trasero como entrada, además de un formato específico.
/// Se asume que tanto el dispositivo como el buffer trasero son válidos y se han inicializado previamente.
/// </summary>
/// <param name="device">El dispositivo de DirectX usado para crear la vista de renderizado.</param>
/// <param name="backBuffer">El buffer trasero asociado a la vista de renderizado.</param>
/// <param name="Format">El formato DXGI del objetivo de renderizado.</param>
void RenderTargetView::init(Device device, Texture backBuffer, DXGI_FORMAT Format)
{
    if (device.m_device == nullptr)
    {
        WARNING("ERROR: RenderTargetView::init : Error in data from params [CHECK FOR Device device] \n");
        exit(1);
    }
    else if (backBuffer.m_texture == nullptr)
    {
        WARNING("ERROR: RenderTargetView::init : Error in data from params [CHECK FOR Texture backBuffer] \n");
        exit(1);
    }

    HRESULT hr = S_OK;

    D3D11_RENDER_TARGET_VIEW_DESC desc = {};
    desc.Format = Format;
    desc.ViewDimension = D3D11_RTV_DIMENSION_TEXTURE2D;
    hr = device.CreateRenderTargetView(backBuffer.m_texture, &desc, &m_renderTargetView);

    if (FAILED(hr))
    {
        WARNING("ERROR: RenderTargetView::init : Error in data from params [CHECK FOR CreateRenderTargetView()] \n");
        exit(1);
    }
}


void RenderTargetView::update()
{

}

/// <summary>
/// Configura el objetivo de renderizado y el view de profundidad para el contexto de dispositivo actual.
/// Limpia el objetivo de renderizado con un color específico y establece el objetivo de renderizado y
/// el view de profundidad para el dibujado.
/// </summary>
/// <param name="deviceContext">El contexto del dispositivo en uso.</param>
/// <param name="depthStencilView">El view de profundidad asociado.</param>
/// <param name="numViews">Número de vistas de renderizado para configurar. Normalmente 1.</param>
/// <param name="ClearColor">Color usado para limpiar el objetivo de renderizado.</param>
void RenderTargetView::render(DeviceContext& deviceContext, DepthStencilView& depthStencilView, unsigned int numViews, float ClearColor[4])
{
    deviceContext.ClearRenderTargetView(m_renderTargetView, ClearColor);
    deviceContext.OMSetRenderTargets(numViews, &m_renderTargetView, depthStencilView.m_depthStencilView);
}

/// <summary>
/// Libera los recursos asociados con la vista de objetivo de renderizado. Este método asegura que
/// los recursos de DirectX sean liberados de manera adecuada cuando ya no sean necesarios, ayudando
/// a prevenir fugas de memoria.
/// </summary>
void RenderTargetView::destroy()
{
    SAFE_RELEASE(m_renderTargetView);
}