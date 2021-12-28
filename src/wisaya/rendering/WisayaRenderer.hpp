#ifndef WISAYARENDERER_H
#define WISAYARENDERER_H

#pragma once

namespace Wisaya {

    typedef enum class RenderAPI {
        NONE = 0,
        VULKAN = 1, OPENGL = 2
    } RenderAPI;

    class WisayaRenderer
    {
    public:
        static RenderAPI GetAPI() { return s_RenderAPI; }
    private:
        static RenderAPI s_RenderAPI;
    };

} // namespace Wisaya


#endif // WISAYARENDERER_H