/*
 * Copyright (C) 2004, 2005, 2006, 2008 Nikolas Zimmermann <zimmermann@kde.org>
 * Copyright (C) 2004, 2005, 2006 Rob Buis <buis@kde.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef SVGLineElement_h
#define SVGLineElement_h

#if ENABLE(SVG)
#include "SVGExternalResourcesRequired.h"
#include "SVGLangSpace.h"
#include "SVGStyledTransformableElement.h"
#include "SVGTests.h"

namespace WebCore {

    class SVGLength;

    class SVGLineElement : public SVGStyledTransformableElement,
                           public SVGTests,
                           public SVGLangSpace,
                           public SVGExternalResourcesRequired {
    public:
        static PassRefPtr<SVGLineElement> create(const QualifiedName&, Document*);

    private:
        SVGLineElement(const QualifiedName&, Document*);
        
        virtual bool isValid() const { return SVGTests::isValid(); }

        virtual void parseMappedAttribute(Attribute*);
        virtual void svgAttributeChanged(const QualifiedName&);
        virtual void synchronizeProperty(const QualifiedName&);

        virtual Path toPathData() const;

        virtual bool supportsMarkers() const { return true; }

        virtual bool selfHasRelativeLengths() const;

        DECLARE_ANIMATED_PROPERTY(SVGLineElement, SVGNames::x1Attr, SVGLength, X1, x1)
        DECLARE_ANIMATED_PROPERTY(SVGLineElement, SVGNames::y1Attr, SVGLength, Y1, y1)
        DECLARE_ANIMATED_PROPERTY(SVGLineElement, SVGNames::x2Attr, SVGLength, X2, x2)
        DECLARE_ANIMATED_PROPERTY(SVGLineElement, SVGNames::y2Attr, SVGLength, Y2, y2)

        // SVGExternalResourcesRequired
        DECLARE_ANIMATED_PROPERTY(SVGLineElement, SVGNames::externalResourcesRequiredAttr, bool, ExternalResourcesRequired, externalResourcesRequired)
    };

} // namespace WebCore

#endif // ENABLE(SVG)
#endif
