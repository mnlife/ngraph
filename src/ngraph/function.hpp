// ----------------------------------------------------------------------------
// Copyright 2017 Nervana Systems Inc.
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// ----------------------------------------------------------------------------

#pragma once

#include "node.hpp"
#include "op.hpp"
#include "ops/parameter.hpp"
#include "type.hpp"

namespace ngraph
{
    /// A user-defined function.
    class Function
    {
    public:
        Function(const std::shared_ptr<Node>&                   result,
                 const std::vector<std::shared_ptr<op::Parameter>>& parameters);

        std::shared_ptr<Node>                         get_result() { return m_result; }
        const std::vector<std::shared_ptr<op::Parameter>> get_parameters() const
        {
            return m_parameters;
        }
        std::string get_name() const { return m_name; }

    protected:
        std::shared_ptr<Node>                               m_result;
        std::vector<std::shared_ptr<ngraph::op::Parameter>> m_parameters;
        std::string                                         m_name;
    };
}