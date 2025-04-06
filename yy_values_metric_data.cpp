/*

  MIT License

  Copyright (c) 2024-2025 Yafiyogi

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

#include "yy_values_metric_data.hpp"

namespace yafiyogi::yy_values {

MetricData::MetricData(const MetricId & p_id) noexcept:
  m_id(std::move(p_id))
{
}

MetricData::MetricData(MetricId && p_id,
                       yy_values::Labels && p_labels) noexcept:
  m_id(std::move(p_id)),
  m_labels(std::move(p_labels))
{
}

void MetricData::swap(MetricData & p_other) noexcept
{
  if(this != &p_other)
  {
    std::swap(m_id, p_other.m_id);
    std::swap(m_labels, p_other.m_labels);
    std::swap(m_timestamp, p_other.m_timestamp);
    std::swap(m_value, p_other.m_value);
    std::swap(m_binary, p_other.m_binary);
    std::swap(m_value_type, p_other.m_value_type);
  }
}

} // namespace yafiyogi::yy_values
