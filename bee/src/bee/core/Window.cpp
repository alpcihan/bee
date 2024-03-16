#pragma once

#include "bee/core/Window.h"

namespace bee {

static bool s_isGLFWInitialized = false;

Window::Window(const WindowProps& props) {
    if(!s_isGLFWInitialized) {
        int result = glfwInit();
        assert(result);
        s_isGLFWInitialized = true;
    }

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    m_window = glfwCreateWindow(props.width, props.height, props.name.c_str(), nullptr, nullptr);
}

Window::~Window() {
}

}