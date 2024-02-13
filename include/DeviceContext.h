#pragma once
#include "Prerequisites.h"

/// <summary>
/// Represents a device context, responsible for issuing rendering commands to the GPU.
/// </summary>
class DeviceContext
{
public:
    DeviceContext() = default;
    ~DeviceContext() { SAFE_RELEASE(m_deviceContext); };

    /// <summary>
    /// Initializes the device context.
    /// </summary>
    void init();

    /// <summary>
    /// Updates the state of the device context.
    /// </summary>
    void update();

    /// <summary>
    /// Renders content using the device context.
    /// </summary>
    void render();

    /// <summary>
    /// Destroys the device context instance.
    /// </summary>
    void destroy();

    /// <summary>
    /// Clears the depth stencil view with specified parameters.
    /// </summary>
    /// <param name="pDepthStencilView">Pointer to the depth stencil view.</param>
    /// <param name="ClearFlags">Flags indicating which parts of the depth stencil view to clear.</param>
    /// <param name="Depth">Depth value to clear to.</param>
    /// <param name="Stencil">Stencil value to clear to.</param>
    void ClearDepthStencilView(ID3D11DepthStencilView* pDepthStencilView,
        unsigned int ClearFlags,
        float Depth,
        unsigned int Stencil);

    /// <summary>
    /// Sets shader resources to the pixel shader.
    /// </summary>
    /// <param name="StartSlot">Start slot index for the shader resources.</param>
    /// <param name="NumViews">Number of shader resources to set.</param>
    /// <param name="ppShaderResourceViews">Array of shader resource views to set.</param>
    void PSSetShaderResources(unsigned int StartSlot,
        unsigned int NumViews,
        ID3D11ShaderResourceView* const* ppShaderResourceViews);

public:
    ID3D11DeviceContext* m_deviceContext = nullptr; // Pointer to the device context object.
};
