/** @file
 *
 *  QUIC Stats
 *
 *  @section license License
 *
 *  Licensed to the Apache Software Foundation (ASF) under one
 *  or more contributor license agreements.  See the NOTICE file
 *  distributed with this work for additional information
 *  regarding copyright ownership.  The ASF licenses this file
 *  to you under the Apache License, Version 2.0 (the
 *  "License"); you may not use this file except in compliance
 *  with the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#pragma once

#include "records/I_RecProcess.h"

extern RecRawStatBlock *quic_rsb;

enum class QUICStats {
  total_packets_sent_stat,
  count,
};

#define QUIC_INCREMENT_DYN_STAT(x) RecIncrRawStat(quic_rsb, nullptr, (int)x, 1)
#define QUIC_DECREMENT_DYN_STAT(x) RecIncrRawStat(quic_rsb, nullptr, (int)x, -1)
#define QUIC_SET_COUNT_DYN_STAT(x, count) RecSetRawStatCount(quic_rsb, x, count)
#define QUIC_INCREMENT_DYN_STAT_EX(x, y) RecIncrRawStat(quic_rsb, nullptr, (int)x, y)
#define QUIC_CLEAR_DYN_STAT(x)            \
  do {                                    \
    RecSetRawStatSum(quic_rsb, (x), 0);   \
    RecSetRawStatCount(quic_rsb, (x), 0); \
  } while (0)