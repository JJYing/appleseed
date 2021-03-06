
//
// This source file is part of appleseed.
// Visit http://appleseedhq.net/ for additional information and resources.
//
// This software is released under the MIT license.
//
// Copyright (c) 2017 Gleb Mishchenko, The appleseedhq Organization
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

// Interface header.
#include "pythoninterpreter.h"

// appleseed.studio headers.
#include "mainwindow/mainwindow.h"
#include "mainwindow/pythonconsole/outputredirector.h"

// appleseed.shared headers.
#include "application/application.h"

// appleseed.foundation headers.
#include "foundation/core/exceptions/exception.h"
#include "foundation/platform/path.h"
#include "foundation/utility/string.h"

// Boost headers.
#include "boost/filesystem.hpp"

// Standard headers.
#include <string>

using namespace appleseed::shared;
using namespace foundation;
using namespace std;
namespace bpy = boost::python;
namespace bf = boost::filesystem;

// Generated by BOOST_PYTHON_MODULE(_appleseedstudio) in python/module.cpp.
extern "C" void init_appleseedstudio();

namespace appleseed {
namespace studio {

//
// PythonInterpreter class implementation
//

PythonInterpreter& PythonInterpreter::instance()
{
    static PythonInterpreter interpreter;
    return interpreter;
}

void PythonInterpreter::set_main_window(MainWindow* main_window)
{
    m_main_window = main_window;
}

MainWindow* PythonInterpreter::get_main_window() const
{
    return m_main_window;
}

namespace
{
    string compute_python_modules_path()
    {
        // Start with the absolute path to appleseed.studio's executable.
        bf::path base_path(get_executable_path());
        bf::path lib_path;

        // Strip appleseed.studio's executable filename from the path.
        base_path = base_path.parent_path();

        // Go up in the hierarchy until bin/ is found.
        while (base_path.filename() != "bin")
        {
            lib_path = base_path.filename() / lib_path;
            base_path = base_path.parent_path();
        }

        // One more step up to reach the parent of bin/.
        lib_path = "lib" / lib_path;
        base_path = base_path.parent_path();

        // Compute full path.
        lib_path = base_path / lib_path / "python2.7";

        return lib_path.string();
    }
}

void PythonInterpreter::initialize(OutputRedirector redirector)
{
    PyImport_AppendInittab("_appleseedstudio", init_appleseedstudio);
    Py_Initialize();
    m_is_initialized = true;

    bpy::object main_module = bpy::import("__main__");
    m_main_namespace = main_module.attr("__dict__");

    // Add path to appleseed module to sys.path so that Python can find it.
    bpy::import("sys").attr("path").attr("append")(compute_python_modules_path());

    bpy::class_<OutputRedirector>("OutputRedirector", bpy::no_init)
        .def("write", &OutputRedirector::write);

    bpy::object sys_module = bpy::import("sys");
    sys_module.attr("stdout") = redirector;
    sys_module.attr("stderr") = redirector;

    // Import Python modules.
    import_python_module("appleseed", "asr");
    import_python_module("appleseed.studio", "studio");
}

void PythonInterpreter::import_python_module(const char* module_name, const char* alias_name)
{
    const string s =
        format("import {0}\n{1} = {0}\n", module_name, alias_name);
    execute(s.c_str());
}

bpy::object PythonInterpreter::execute(const char* command)
{
    if (!m_is_initialized)
        throw Exception("Attempt to execute command while interpreter is not initialized");

    try
    {
        return bpy::exec(command, m_main_namespace, m_main_namespace);
    }
    catch (const bpy::error_already_set&)
    {
        PyErr_Print();
        return bpy::object();
    }
}

PythonInterpreter::PythonInterpreter()
  : m_is_initialized(false), m_main_window(nullptr)
{
}

PythonInterpreter::~PythonInterpreter()
{
    Py_Finalize();
}

}   // namespace studio
}   // namespace appleseed
