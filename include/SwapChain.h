#pragma once


#include "Prerequisites.h"


class Device;
class DeviceContext;
class Window;
class Texture;
// Declaración anticipada de clases. Estas clases se utilizarán en este archivo, pero no se definen aquí.

/// <summary>
/// Represents a swap chain, responsible for presenting rendered images to the screen.
/// </summary>
class SwapChain {
    // Declaración de la clase SwapChain.
public:
    SwapChain() = default;
    ~SwapChain() { SAFE_RELEASE(m_swapChain); };
    // Constructor predeterminado y destructor de la clase SwapChain. El destructor libera la memoria asignada a m_swapChain.

    /// <summary>
    /// Initializes the swap chain with the provided Device, DeviceContext, Texture, and Window objects.
    /// </summary>
    /// <param name="device">Reference to the Device object.</param>
    /// <param name="deviceContext">Reference to the DeviceContext object.</param>
    /// <param name="backBuffer">Reference to the Texture representing the back buffer.</param>
    /// <param name="window">Window object for which the swap chain is initialized.</param>
    void init(Device& device,
        DeviceContext& deviceContext,
        Texture& backBuffer,
        Window window);
    // Prototipo de función init que inicializa la cadena de intercambio con los objetos de Device, DeviceContext, Texture y Window proporcionados como argumentos.

    /// <summary>
    /// Updates the state of the swap chain.
    /// </summary>
    void update();
    // Prototipo de función update que probablemente se utilizará para actualizar el estado de la cadena de intercambio.

    /// <summary>
    /// Renders content using the swap chain.
    /// </summary>
    void render();
    // Prototipo de función render que probablemente se utilizará para renderizar algo en la pantalla utilizando la cadena de intercambio.

    /// <summary>
    /// Destroys the swap chain instance.
    /// </summary>
    void destroy();
    // Prototipo de función destroy que probablemente se utilizará para destruir la instancia de la cadena de intercambio.
    void present();
public:
    IDXGISwapChain* m_swapChain = nullptr;
    D3D_DRIVER_TYPE m_driverType = D3D_DRIVER_TYPE_NULL;
    // Puntero público a IDXGISwapChain, que probablemente sea el objeto principal de la cadena de intercambio.

private:
    
    D3D_FEATURE_LEVEL m_featureLevel = D3D_FEATURE_LEVEL_11_0;
    // Variables miembro privadas que almacenan el tipo de controlador y el nivel de características de la cadena de intercambio.
};

