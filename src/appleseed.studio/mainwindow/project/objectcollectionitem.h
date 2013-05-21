
//
// This source file is part of appleseed.
// Visit http://appleseedhq.net/ for additional information and resources.
//
// This software is released under the MIT license.
//
// Copyright (c) 2010-2013 Francois Beaune, Jupiter Jazz Limited
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

#ifndef APPLESEED_STUDIO_MAINWINDOW_PROJECT_OBJECTCOLLECTIONITEM_H
#define APPLESEED_STUDIO_MAINWINDOW_PROJECT_OBJECTCOLLECTIONITEM_H

// appleseed.studio headers.
#include "mainwindow/project/collectionitembase.h"

// appleseed.renderer headers.
#include "renderer/api/object.h"
#include "renderer/api/scene.h"

// appleseed.foundation headers.
#include "foundation/platform/compiler.h"

// Qt headers.
#include <QObject>

// Standard headers.
#include <string>

// Forward declarations.
namespace appleseed { namespace studio { class AssemblyItem; } }
namespace appleseed { namespace studio { class ItemBase; } }
namespace appleseed { namespace studio { class ProjectBuilder; } }
namespace renderer  { class ParamArray; }
class QMenu;

namespace appleseed {
namespace studio {

class ObjectCollectionItem
  : public CollectionItemBase<renderer::Object>
{
    Q_OBJECT

  public:
    ObjectCollectionItem(
        renderer::ObjectContainer&  objects,
        renderer::Assembly&         parent,
        AssemblyItem*               parent_item,
        ProjectBuilder&             project_builder,
        renderer::ParamArray&       settings);

    virtual QMenu* get_single_item_context_menu() const OVERRIDE;

  public slots:
    void slot_import_objects();

  private:
    renderer::Assembly&             m_parent;
    AssemblyItem*                   m_parent_item;
    renderer::ParamArray&           m_settings;

    virtual ItemBase* create_item(renderer::Object* object) OVERRIDE;

    void insert_objects(const std::string& path) const;
};

}       // namespace studio
}       // namespace appleseed

#endif  // !APPLESEED_STUDIO_MAINWINDOW_PROJECT_OBJECTCOLLECTIONITEM_H
