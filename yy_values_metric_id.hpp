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

#include <string>

namespace yafiyogi::yy_values {

class MetricId final
{
  public:
    explicit MetricId(std::string_view p_metric_name) noexcept;
    MetricId(std::string_view p_name,
             std::string_view p_location) noexcept;

    constexpr MetricId() noexcept = default;
    constexpr MetricId(const MetricId &) noexcept = default;
    constexpr MetricId(MetricId &&) noexcept = default;

    constexpr MetricId & operator=(const MetricId &) noexcept = default;
    constexpr MetricId & operator=(MetricId &&) noexcept = default;

    constexpr bool operator<(const MetricId & p_other) const noexcept
    {
      return compare(p_other) < 0;
    }

    constexpr bool operator==(const MetricId & p_other) const noexcept
    {
      return compare(p_other) == 0;
    }

    constexpr int compare(const MetricId & p_other) const noexcept
    {
      if(int comp = m_name.compare(p_other.m_name);
         0 != comp)
      {
        return comp;
      }

      return m_location.compare(p_other.m_location);
    }

    constexpr const std::string & Name() const noexcept
    {
      return m_name;
    }

    constexpr const std::string & Location() const noexcept
    {
      return m_location;
    }

    constexpr void Location(const std::string & p_location) noexcept
    {
      m_location = p_location;
    }

    constexpr void Location(std::string && p_location) noexcept
    {
      m_location = std::move(p_location);
    }

  private:
    std::string m_name{};
    std::string m_location{};
};

} // namespace yafiyogi::yy_values
