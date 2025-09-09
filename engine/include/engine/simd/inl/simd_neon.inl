#pragma once

#ifndef SIMD_INLINE_IMPL
#error "Do not include simd_neon.inl, include engine/simd/simd.hpp instead"
#else

template<uint8_t N>
VectorLanes<float, N>::VectorLanes()
{
    for (int i = 0; i < reg_count; i++)
    {
        regs[i] = vdupq_n_f32(0.0f);
    }
}

template<uint8_t N>
void VectorLanes<float, N>::load(float *data)
{
    for (int i = 0; i < reg_count; i++)
    {
        regs[i] = vld1q_f32(data + i * reg_lanes);
    }
}

template<uint8_t N>
void VectorLanes<float, N>::store(float *data)
{
    for (int i = 0; i < reg_count; i++)
    {
        vst1q_f32(data + i * reg_lanes, regs[i]);
    }
}

template<uint8_t N>
bool VectorLanes<float, N>::operator==(const VectorLanes &rhs) const
{
    for (int i = 0; i < reg_count; i++)
    {
        if (vaddvq_u32(vshrq_n_u32(vceqq_f32(regs[i], rhs.regs[i]), 31)) != reg_lanes)
        {
            return false;
        }
    }
    return true;
}

template<uint8_t N>
VectorLanes<float, N> VectorLanes<float, N>::operator+(const VectorLanes &rhs) const
{
    VectorLanes result;
    for (int i = 0; i < reg_count; i++)
    {
        result.regs[i] = vaddq_f32(regs[i], rhs.regs[i]);
    }
    return result;
}

template<uint8_t N>
VectorLanes<float, N> VectorLanes<float, N>::operator-(const VectorLanes &rhs) const
{
    VectorLanes result;
    for (int i = 0; i < reg_count; i++)
    {
        result.regs[i] = vsubq_f32(regs[i], rhs.regs[i]);
    }
    return result;
}

template<uint8_t N>
VectorLanes<float, N> VectorLanes<float, N>::operator*(const VectorLanes &rhs) const
{
    VectorLanes result;
    for (int i = 0; i < reg_count; i++)
    {
        result.regs[i] = vmulq_f32(regs[i], rhs.regs[i]);
    }
    return result;
}

template<uint8_t N>
VectorLanes<float, N> VectorLanes<float, N>::operator/(const VectorLanes &rhs) const
{
    VectorLanes result;
    for (int i = 0; i < reg_count; i++)
    {
        result.regs[i] = vdivq_f32(regs[i], rhs.regs[i]);
    }
    return result;
}
#endif
