#include "SharedColorRenderBuffer.h"

#include <liboscar/Graphics/ColorRenderBufferParams.h>

#include <gtest/gtest.h>

using namespace osc;

TEST(SharedColorRenderBuffer, can_default_construct)
{
    [[maybe_unused]] const SharedColorRenderBuffer default_constructed;
}

TEST(SharedColorRenderBuffer, default_constructed_as_1x1_pixel_dimensions)
{
    ASSERT_EQ(SharedColorRenderBuffer{}.pixel_dimensions(), Vec2i(1, 1));
}

TEST(SharedColorRenderBuffer, default_constructed_with_1x_anti_aliasing)
{
    ASSERT_EQ(SharedColorRenderBuffer{}.anti_aliasing_level(), AntiAliasingLevel{1});
}
TEST(SharedColorRenderBuffer, can_construct_depth_buffer)
{
    [[maybe_unused]] const SharedColorRenderBuffer depth_buffer{ColorRenderBufferParams{}};
}

TEST(SharedColorRenderBuffer, dimensionality_defaults_to_Tex2D)
{
    ASSERT_EQ(SharedColorRenderBuffer{}.dimensionality(), TextureDimensionality::Tex2D);
}

TEST(SharedColorRenderBuffer, dimensionality_is_based_on_parameters)
{
    const SharedColorRenderBuffer buffer{ColorRenderBufferParams{.dimensionality = TextureDimensionality::Cube}};
    ASSERT_EQ(buffer.dimensionality(), TextureDimensionality::Cube);
}

TEST(SharedColorRenderBuffer, pixel_dimensions_is_based_on_parameters)
{
    const SharedColorRenderBuffer buffer{ColorRenderBufferParams{.pixel_dimensions = Vec2i(3, 5)}};
    ASSERT_EQ(buffer.pixel_dimensions(), Vec2i(3,5));
}

TEST(SharedColorRenderBuffer, anti_aliasing_level_is_based_on_parameters)
{
    const SharedColorRenderBuffer buffer{ColorRenderBufferParams{.anti_aliasing_level = AntiAliasingLevel{4}}};
    ASSERT_EQ(buffer.anti_aliasing_level(), AntiAliasingLevel{4});
}
