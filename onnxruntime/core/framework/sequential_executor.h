// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once

#include <vector>
#include "core/common/common.h"
#include "core/common/status.h"
#include "core/common/logging/logging.h"
#include "core/framework/iexecutor.h"
#include "core/framework/framework_common.h"
#include "core/framework/ml_value.h"
#include "core/framework/session_state.h"
#include "core/graph/graph.h"

namespace onnxruntime {
class SequentialExecutor : public IExecutor {
 public:
  SequentialExecutor() = default;

  common::Status Execute(const SessionState& session_state,
                         const NameMLValMap& feeds,
                         const std::vector<std::string>& output_names,
                         std::vector<MLValue>& fetches,
                         const Logging::Logger& logger) override;

 private:
  LOTUS_DISALLOW_COPY_ASSIGN_AND_MOVE(SequentialExecutor);
};
}  // namespace onnxruntime
