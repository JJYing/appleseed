
//
// This source file is part of appleseed.
// Visit http://appleseedhq.net/ for additional information and resources.
//
// This software is released under the MIT license.
//
// Copyright (c) 2017 Artem Bishev, The appleseedhq Organization
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

#ifndef APPLESEED_RENDERER_KERNEL_LIGHTING_MATERIALSAMPLERS_H
#define APPLESEED_RENDERER_KERNEL_LIGHTING_MATERIALSAMPLERS_H

// appleseed.renderer headers.
#include "renderer/global/globaltypes.h"
#include "renderer/kernel/shading/shadingray.h"

// appleseed.foundation headers.
#include "foundation/math/basis.h"
#include "foundation/math/dual.h"
#include "foundation/math/vector.h"

// Forward declarations.
namespace renderer  { class BSDF; }
namespace renderer  { class ShadingComponents; }
namespace renderer  { class ShadingContext; }
namespace renderer  { class ShadingPoint; }

//
// This file contains wrappers over samplable functions, such as BSDF and PhaseFunction.
// These wrappers provide a uniform interface for sampling and evaluating these functions
// at a certain point, which can be used during lighting integration.
//

namespace renderer
{

class IMaterialSampler
{
  public:
    virtual const foundation::Vector3d& get_point() const = 0;

    virtual bool contributes_to_light_sampling() const = 0;

    virtual const ShadingPoint& trace(
        const ShadingContext&           shading_context,
        const foundation::Vector3f&     direction,
        Spectrum&                       transmission) const = 0;

    virtual void trace_between(
        const ShadingContext&           shading_context,
        const foundation::Vector3d&     target_position,
        Spectrum&                       transmission) const = 0;

    virtual bool sample(
        SamplingContext&                sampling_context,
        const foundation::Dual3d&       outgoing,
        foundation::Dual3f&             incoming,
        ShadingComponents&              value,
        float&                          pdf) const = 0;

    virtual float evaluate(
        const int                       light_sampling_modes,
        const foundation::Vector3f&     outgoing,
        const foundation::Vector3f&     incoming,
        ShadingComponents&              value) const = 0;

    virtual bool cull_incoming_direction(
        const foundation::Vector3d&     incoming) const = 0;
};

class BSDFSampler
  : public IMaterialSampler
{
  public:
    BSDFSampler(
        const BSDF&                     bsdf,
        const void*                     bsdf_data,
        const int                       bsdf_sampling_modes,
        const ShadingPoint&             shading_point);

    virtual const foundation::Vector3d& get_point() const override;

    virtual bool contributes_to_light_sampling() const override;

    virtual const ShadingPoint& trace(
        const ShadingContext&           shading_context,
        const foundation::Vector3f&     direction,
        Spectrum&                       transmission) const override;

    virtual void trace_between(
        const ShadingContext&           shading_context,
        const foundation::Vector3d&     target_position,
        Spectrum&                       transmission) const override;

    virtual bool sample(
        SamplingContext&                sampling_context,
        const foundation::Dual3d&       outgoing,
        foundation::Dual3f&             incoming,
        ShadingComponents&              value,
        float&                          pdf) const override;

    virtual float evaluate(
        const int                       light_sampling_modes,
        const foundation::Vector3f&     outgoing,
        const foundation::Vector3f&     incoming,
        ShadingComponents&              value) const override;

    virtual bool cull_incoming_direction(
        const foundation::Vector3d&  incoming) const override;

  private:
    const BSDF&                         m_bsdf;
    const void*                         m_bsdf_data;
    const int                           m_bsdf_sampling_modes;
    const foundation::Basis3d&          m_shading_basis;
    const foundation::Vector3d&         m_geometric_normal;
    const ShadingPoint&                 m_shading_point;
};

class PhaseFunctionSampler
  : public IMaterialSampler
{
  public:
    PhaseFunctionSampler(
        const ShadingRay&               volume_ray,
        const PhaseFunction&            phase_function,
        const void*                     phase_function_data,
        const float                     distance);

    virtual const foundation::Vector3d& get_point() const override;

    virtual bool contributes_to_light_sampling() const override;

    virtual const ShadingPoint& trace(
        const ShadingContext&           shading_context,
        const foundation::Vector3f&     direction,
        Spectrum&                       transmission) const override;

    virtual void trace_between(
        const ShadingContext&           shading_context,
        const foundation::Vector3d&     target_position,
        Spectrum&                       transmission) const override;

    virtual bool sample(
        SamplingContext&                sampling_context,
        const foundation::Dual3d&       outgoing,
        foundation::Dual3f&             incoming,
        ShadingComponents&              value,
        float&                          pdf) const override;

    virtual float evaluate(
        const int                       light_sampling_modes,
        const foundation::Vector3f&     outgoing,
        const foundation::Vector3f&     incoming,
        ShadingComponents&              value) const override;

    virtual bool cull_incoming_direction(
        const foundation::Vector3d&     incoming) const override;

  private:
    const ShadingRay&               m_volume_ray;
    const PhaseFunction&            m_phase_function;
    const void*                     m_phase_function_data;
    const float                     m_distance;
    const foundation::Vector3d      m_point;
};

}       // namespace renderer

#endif  // !APPLESEED_RENDERER_KERNEL_LIGHTING_MATERIALSAMPLERS_H
