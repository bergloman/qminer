/**
 * Copyright (c) 2015, Jozef Stefan Institute, Quintelligence d.o.o. and contributors
 * All rights reserved.
 *
 * This source code is licensed under the FreeBSD license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "anomaly_detection.h"

namespace TAd
{
    
TExtremeValuesDetector::TExtremeValuesDetector() {
}

bool TExtremeValuesDetector::Add(const TTm& Tm, const double Val) {
    Vals.Add(TPair<TTm, TFlt>(Tm, Val));
    return true;
}

void TExtremeValuesDetector::Reset() {
    Vals.Clr();
}

/////////////////////////////////////////////////////////////////////

TValueTrendDetector::TValueTrendDetector() {
}

/////////////////////////////////////////////////////////////////////

TFlowRateDetector::TFlowRateDetector() {
}

}
