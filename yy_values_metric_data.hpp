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

#pragma once

#include <string>
#include <variant>

#include "yy_cpp/yy_types.hpp"
#include "yy_cpp/yy_vector.h"
#include "yy_cpp/yy_observer_ptr.hpp"

#include "yy_value_type.hpp"
#include "yy_values_metric_id.hpp"
#include "yy_values_labels.hpp"

namespace yafiyogi::yy_values {

class MetricData
{
  public:
    using binary_type = std::variant<double, int64_t, bool>;

    MetricData(const MetricId & p_id) noexcept;
    MetricData(MetricId && p_id,
               yy_values::Labels && p_labels) noexcept;

    constexpr MetricData() noexcept = default;
    constexpr MetricData(const MetricData &) noexcept = default;
    constexpr MetricData(MetricData && p_other) noexcept:
      m_id(std::move(p_other.m_id)),
      m_labels(std::move(p_other.m_labels)),
      m_timestamp(p_other.m_timestamp),
      m_value(std::move(p_other.m_value)),
      m_binary(std::move(p_other.m_binary)),
      m_value_type(p_other.m_value_type)
    {
      p_other.m_timestamp = timestamp_type{};
      p_other.m_value_type = ValueType::Unknown;
    }
    virtual ~MetricData() noexcept = default;

    constexpr MetricData & operator=(const MetricData &) noexcept = default;
    constexpr MetricData & operator=(MetricData && p_other) noexcept
    {
      if(this != &p_other)
      {
        m_id = std::move(p_other.m_id);
        m_labels = std::move(p_other.m_labels);
        m_timestamp = p_other.m_timestamp;
        p_other.m_timestamp = timestamp_type{};
        m_value = std::move(p_other.m_value);
        m_binary = std::move(p_other.m_binary);
        m_value_type = p_other.m_value_type;
        p_other.m_value_type = ValueType::Unknown;
      }
      return *this;
    }

    constexpr bool operator<(const MetricData & other) const noexcept
    {
      return m_id < other.m_id;
    }

    constexpr bool operator==(const MetricData & other) const noexcept
    {
      return m_id == other.m_id;
    }

    constexpr MetricId & Id() noexcept
    {
      return m_id;
    }

    constexpr const MetricId & Id() const noexcept
    {
      return m_id;
    }

    constexpr yy_values::Labels & Labels() noexcept
    {
      return m_labels;
    }

    constexpr const yy_values::Labels & Labels() const noexcept
    {
      return m_labels;
    }

    constexpr timestamp_type Timestamp() const noexcept
    {
      return m_timestamp;
    }

    constexpr void Timestamp(timestamp_type p_timestamp) noexcept
    {
      m_timestamp = p_timestamp;
    }

    constexpr const std::string_view Value() const noexcept
    {
      return m_value;
    }

    constexpr void Value(std::string_view p_value) noexcept
    {
      m_value = p_value;
    }

    constexpr binary_type Binary() const noexcept
    {
      return m_binary;
    }

    constexpr void Binary(binary_type p_binary) noexcept
    {
      m_binary = p_binary;
    }

    constexpr ValueType Type() const noexcept
    {
      return m_value_type;
    }

    constexpr void Type(ValueType p_value_type) noexcept
    {
      m_value_type = p_value_type;
    }

    void swap(MetricData & p_other) noexcept;

    friend void swap(MetricData & p_lhs, MetricData & p_rhs) noexcept
    {
      p_lhs.swap(p_rhs);
    }

  private:
    MetricId m_id{};
    yy_values::Labels m_labels{};
    timestamp_type m_timestamp{};
    std::string m_value{};
    binary_type m_binary{};
    ValueType m_value_type = ValueType::Unknown;
};

using MetricDataObsPtr = yy_data::observer_ptr<MetricData>;
using MetricDataVector = yy_quad::simple_vector<MetricData>;
using MetricDataVectorPtr = yy_data::observer_ptr<MetricDataVector>;

} // namespace yafiyogi::yy_values
