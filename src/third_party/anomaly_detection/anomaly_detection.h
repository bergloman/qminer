/**
 * Copyright (c) 2015, Jozef Stefan Institute, Quintelligence d.o.o. and contributors
 * All rights reserved.
 *
 * This source code is licensed under the FreeBSD license found in the
 * LICENSE file in the root directory of this source tree.
 */

#ifndef ANOMALY_DETECTION_H_
#define ANOMALY_DETECTION_H_

#include "base.h"
#include "mine.h"

namespace TAd
{

class TExtremeValuesDetector {
private:
  TVec<TPair<<TTm, TFlt>> Vals;
public:
  TExtremeValuesDetector();
  bool Add(const TTm& Tm, const double Val);
  void Reset();
};

class TValueTrendDetector {
private:
public:
  TValueTrendDetector();
};

class TFlowRateDetector {
private:
public:
  TFlowRateDetector();
};

}

#endif
