#include <Wisaya_pch.hpp>
#include <wisaya/rendering/WisayaContext.hpp>

#include <platform/opengl/OpenGLContext.hpp>


namespace Wisaya {

    scoped_ptr<WisayaContext> WisayaContext::Create(void* window) {
        return create_scoped<Platform::OpenGL::OpenGLContext>(window);
    }

} // namespace Wisaya
