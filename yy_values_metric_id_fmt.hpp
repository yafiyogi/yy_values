/*

  MIT License

  Copyright (c) 2025 Yafiyogi

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.

*/

#pragma once

#include <string_view>

#include "fmt/format.h"

#include "yy_values_metric_id.hpp"

namespace yafiyogi::yy_values::fmt_detail {

static constexpr std::string_view metric_id_fmt{"{}:{}"};

} // namespace yafiyogi::yy_values::fmt_detail

template <>
struct fmt::formatter<yafiyogi::yy_values::MetricId>:
  formatter<std::string_view>
{
    auto format(const yafiyogi::yy_values::MetricId & p_metric_id,
                format_context & ctx) const
    {
      return fmt::format_to(ctx.out(),
                            yafiyogi::yy_values::fmt_detail::metric_id_fmt,
                            p_metric_id.Name(),
                            p_metric_id.Location());
    }
};
