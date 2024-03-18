#include "SwapChain.h"
#include "Device.h"
#include "DeviceContext.h"
#include "Window.h"
#include "Texture.h"

/// <summary>
/// Inicializa la cadena de intercambio. Establece la conexión entre el dispositivo de renderizado, el contexto del dispositivo, y la ventana de visualización.
/// </summary>
/// <param name="device">Referencia al dispositivo de renderizado.</param>
/// <param name="deviceContext">Referencia al contexto del dispositivo.</param>
/// <param name="backBuffer">Referencia al buffer trasero para la cadena de intercambio.</param>
/// <param name="window">La ventana donde se renderizará el contenido.</param>
void
SwapChain::init(Device& device,
    DeviceContext& deviceContext,
    Texture& backBuffer,
    Window window)
{
    // Verifica si el recurso de la ventana existe
    if (window.m_hWnd == nullptr)
    {
        WARNING("ERROR: SwapChain::init : Error in data from params [CHECK FOR Window window ] \n");
        exit(1); // Finaliza la ejecución si no hay una ventana válida.
    }
    unsigned int createDeviceFlags = 0;
#ifdef _DEBUG
    createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG; // Añade banderas de depuración si está en modo debug.
#endif

    // Define los tipos de drivers a intentar.
    D3D_DRIVER_TYPE driverTypes[] =
    {
        D3D_DRIVER_TYPE_HARDWARE, // Prioriza el hardware.
        D3D_DRIVER_TYPE_WARP,     // Emulación por software.
        D3D_DRIVER_TYPE_REFERENCE, // Driver de referencia (muy lento).
    };
    unsigned int numDriverTypes = ARRAYSIZE(driverTypes);

    // Niveles de características de DirectX a intentar usar.
    D3D_FEATURE_LEVEL featureLevels[] =
    {
        D3D_FEATURE_LEVEL_11_0, // Intenta usar DirectX 11.
        D3D_FEATURE_LEVEL_10_1, // Retrocede a 10.1 si es necesario.
        D3D_FEATURE_LEVEL_10_0, // Retrocede a 10 si es necesario.
    };
    unsigned int numFeatureLevels = ARRAYSIZE(featureLevels);

    // Configuración de la cadena de intercambio.
    DXGI_SWAP_CHAIN_DESC sd;
    memset(&sd, 0, sizeof(sd)); // Inicializa la estructura a 0.
    sd.BufferCount = 1; // Un solo buffer trasero.
    sd.BufferDesc.Width = window.m_width; // Ancho de la ventana.
    sd.BufferDesc.Height = window.m_height; // Alto de la ventana.
    sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM; // Formato de color.
    sd.BufferDesc.RefreshRate.Numerator = 60; // 60 Hz de tasa de refresco.
    sd.BufferDesc.RefreshRate.Denominator = 1; // Denominador de la tasa de refresco.
    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT; // Uso del buffer.
    sd.OutputWindow = window.m_hWnd; // Handle de la ventana.
    sd.SampleDesc.Count = 1; // Sin multi-muestreo.
    sd.SampleDesc.Quality = 0; // Calidad del multi-muestreo.
    sd.Windowed = TRUE; // Modo ventana.

    HRESULT hr = S_OK;

    // Intenta crear el dispositivo y la cadena de intercambio con los drivers y niveles de característica definidos.
    for (unsigned int driverTypeIndex = 0; driverTypeIndex < numDriverTypes; driverTypeIndex++)
    {
        m_driverType = driverTypes[driverTypeIndex];
        hr = D3D11CreateDeviceAndSwapChain(nullptr, m_driverType, nullptr, createDeviceFlags, featureLevels, numFeatureLevels,
            D3D11_SDK_VERSION, &sd, &m_swapChain, &device.m_device, &m_featureLevel, &deviceContext.m_deviceContext);
        if (SUCCEEDED(hr))
            break; // Sale del bucle si tiene éxito.
    }
    if (FAILED(hr))
    {
        WARNING("ERROR: SwapChain::init : Error in data from method [CHECK FOR D3D11CreateDeviceAndSwapChain()]\n");
        exit(1); // Finaliza si falla la creación.
    }

    // Obtiene el buffer trasero de la cadena de intercambio.
    hr = m_swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&backBuffer.m_texture);
    if (FAILED(hr))
    {
        WARNING("ERROR: SwapChain::init : Error in data from method [CHECK FOR m_swapChain->GetBuffer()] \n");
        exit(1); // Finaliza si no puede obtener el buffer trasero.
    }
}

void SwapChain::update()
{
    // Este método se mantendrá vacío ya que no es necesario actualizar la cadena de intercambio constantemente.
}

void SwapChain::render()
{
    // Este método podría contener lógica para preparar la cadena de intercambio antes de renderizar.
}

void SwapChain::destroy()
{
    SAFE_RELEASE(m_swapChain); // Libera de forma segura la cadena de intercambio.
}

/// <summary>
/// Presenta el contenido del buffer trasero en la pantalla.
/// </summary>
void SwapChain::present()
{
    m_swapChain->Present(0, 0); // Presenta el buffer trasero al frente.
}
