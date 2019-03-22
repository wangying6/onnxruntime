// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once

#include "core/optimizer/graph_transformer.h"

namespace onnxruntime {

class UnsqueezeElimination : public onnxruntime::GraphTransformer {
 public:
  UnsqueezeElimination() noexcept : onnxruntime::GraphTransformer("EliminateUnsqueeze", "Eliminate unsqueeze node") {}

 private:
  Status ApplyImpl(Graph& graph, bool& modified, 
                   const std::vector<std::string>& compatible_provider_types, 
                   int graph_level) const override;
};

}  // namespace onnxruntime
